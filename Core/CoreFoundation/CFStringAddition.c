//
//  CFStringAddition.c
//  Core
//
//  Created by Sam Marshall on 4/29/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef Core_CFStringAddition_c
#define Core_CFStringAddition_c

#include "CFStringAddition.h"

char * CreateCStringFromCFStringRef(CFStringRef string) {
	CFIndex length = CFStringGetLength(string) + 1;
	char * c_path = calloc(length, sizeof(char));
	Boolean result = CFStringGetCString(string, c_path, length, kCFStringEncodingUTF8);
	if (result == false) {
		free(c_path);
		c_path = "";
	}
	return c_path;
}

#endif
