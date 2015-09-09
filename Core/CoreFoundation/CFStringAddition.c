//
//  CFStringAddition.c
//  Core
//
//  Created by Samantha Marshall on 4/29/14.
//  Copyright (c) 2014 Samantha Marshall. All rights reserved.
//

#ifndef Core_CFStringAddition_c
#define Core_CFStringAddition_c

#include "CFStringAddition.h"

char *CreateCStringFromCFStringRef(CFStringRef string)
{
	CFIndex alloclen = CFStringGetMaximumSizeForEncoding(CFStringGetLength(string), kCFStringEncodingUTF8) + 1;
	char *cstr = calloc(alloclen, sizeof(char));
	CFStringGetCString(string, cstr, alloclen, kCFStringEncodingUTF8);
	return cstr;
}

#endif
