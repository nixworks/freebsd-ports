From 455c52a027ab3548953372a0b7bdb0008420e9ba Mon Sep 17 00:00:00 2001
From: "Jan Alexander Steffens (heftig)" <jan.steffens@gmail.com>
Date: Fri, 8 Jun 2018 22:29:50 +0200
Subject: [PATCH] Fix validation rejecting all NAME and TEXT attrs

When the UTF-8 validation loop finishes successfully, `*ptr` points at
the `'\0'` at the end of the string. The code misinterpreted this as a
control character (`*ptr < ' '`) and failed the validation.

Fixes https://github.com/apple/cups/issues/5325
---
 cups/ipp.c | 24 ++++++++++--------------
 1 file changed, 10 insertions(+), 14 deletions(-)

diff --git a/cups/ipp.c b/cups/ipp.c
index 95d53cc44..204c71fcd 100644
--- cups/ipp.c
+++ cups/ipp.c
@@ -5030,15 +5030,13 @@ ippValidateAttribute(
 	    else if (*ptr & 0x80)
 	      break;
 	    else if ((*ptr < ' ' && *ptr != '\n' && *ptr != '\r' && *ptr != '\t') || *ptr == 0x7f)
-	      break;
+		{
+		  ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad text value \"%s\" - bad control character (PWG 5100.14 section 8.3)."), attr->name, attr->values[i].string.text);
+		  return (0);
+		}
 	  }
 
-	  if (*ptr < ' ' || *ptr == 0x7f)
-	  {
-	    ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad text value \"%s\" - bad control character (PWG 5100.14 section 8.3)."), attr->name, attr->values[i].string.text);
-	    return (0);
-	  }
-	  else if (*ptr)
+	  if (*ptr)
 	  {
 	    ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad text value \"%s\" - bad UTF-8 sequence (RFC 8011 section 5.1.2)."), attr->name, attr->values[i].string.text);
 	    return (0);
@@ -5088,15 +5086,13 @@ ippValidateAttribute(
 	    else if (*ptr & 0x80)
 	      break;
 	    else if (*ptr < ' ' || *ptr == 0x7f)
-	      break;
+		{
+		  ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad name value \"%s\" - bad control character (PWG 5100.14 section 8.1)."), attr->name, attr->values[i].string.text);
+		  return (0);
+		}
 	  }
 
-	  if (*ptr < ' ' || *ptr == 0x7f)
-	  {
-	    ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad name value \"%s\" - bad control character (PWG 5100.14 section 8.1)."), attr->name, attr->values[i].string.text);
-	    return (0);
-	  }
-	  else if (*ptr)
+	  if (*ptr)
 	  {
 	    ipp_set_error(IPP_STATUS_ERROR_BAD_REQUEST, _("\"%s\": Bad name value \"%s\" - bad UTF-8 sequence (RFC 8011 section 5.1.3)."), attr->name, attr->values[i].string.text);
 	    return (0);
