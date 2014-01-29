//
//  CFTypeAddition.c
//  Core
//
//  Created by Sam Marshall on 1/12/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef Core_CFTypeAddition_c
#define Core_CFTypeAddition_c

#include "CFTypeAddition.h"
#include "CFDictionaryAddition.h"
#include "Number.h"
#include <objc/NSObjCRuntime.h>
#include "Logging.h"

extern void PrintCFDictionaryInternalFormatting(CFDictionaryRef dictionary, uint32_t depth);

void PrintCFTypeInternalFormat(CFTypeRef value, uint32_t depth) {
	bool foundType = false;
	CFStringRef valueType = CFCopyTypeIDDescription(CFGetTypeID(value));
	CFStringRef dictionaryType = CFCopyTypeIDDescription(CFDictionaryGetTypeID());
	if (CFStringCompare(valueType, dictionaryType, 0x0) == kCFCompareEqualTo) {
		foundType = true;
		printf("{\n");
		PrintCFDictionaryInternalFormatting(value, depth+0x1);
		PrintDepth(depth,"}\n");
	}
	CFSafeRelease(dictionaryType);
	
	CFStringRef booleanType = CFCopyTypeIDDescription(CFBooleanGetTypeID());
	if (CFStringCompare(valueType, booleanType, 0x0) == kCFCompareEqualTo) {
		foundType = true;
		printf("%s\n",(CFBooleanGetValue(value) ? "True" : "False"));
	}
	CFSafeRelease(booleanType);
	
	CFStringRef stringType = CFCopyTypeIDDescription(CFStringGetTypeID());
	if (CFStringCompare(valueType, stringType, 0x0) == kCFCompareEqualTo) {
		foundType = true;
		printf("%s\n",(char*)CFStringGetCStringPtr(value,kCFStringEncodingUTF8));
	}
	CFSafeRelease(stringType);
	
	CFStringRef numberType = CFCopyTypeIDDescription(CFNumberGetTypeID());
	if (CFStringCompare(valueType, numberType, 0x0) == kCFCompareEqualTo) {
		foundType = true;
		CFIndex numberType = CFNumberGetType(value);
		switch (numberType) {
			case kCFNumberSInt8Type: {
				SInt8 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%hhd\n",number);
				break;
			};
			case kCFNumberSInt16Type: {
				SInt16 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%hd\n",number);
				break;
			};
			case kCFNumberSInt32Type: {
				SInt32 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%d\n",(int32_t)number);
				break;
			};
			case kCFNumberSInt64Type: {
				SInt64 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%lld\n",number);
				break;
			};
			case kCFNumberFloat32Type: {
				Float32 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%.f\n",number);
				break;
			};
			case kCFNumberFloat64Type: {
				Float64 number;
				CFNumberGetValue(value, numberType, &number);
				printf("%.f\n",number);
				break;
			};
			case kCFNumberCharType: {
				char number;
				CFNumberGetValue(value, numberType, &number);
				printf("%c\n",number);
				break;
			};
			case kCFNumberShortType: {
				short number;
				CFNumberGetValue(value, numberType, &number);
				printf("%hd\n",number);
				break;
			};
			case kCFNumberIntType: {
				int number;
				CFNumberGetValue(value, numberType, &number);
				printf("%d\n",number);
				break;
			};
			case kCFNumberLongType: {
				long number;
				CFNumberGetValue(value, numberType, &number);
				printf("%ld\n",number);
				break;
			};
			case kCFNumberLongLongType: {
				long long number;
				CFNumberGetValue(value, numberType, &number);
				printf("%qd\n",number);
				break;
			};
			case kCFNumberFloatType: {
				float number;
				CFNumberGetValue(value, numberType, &number);
				printf("%.f\n",number);
				break;
			};
			case kCFNumberDoubleType: {
				double number;
				CFNumberGetValue(value, numberType, &number);
				printf("%.f\n",number);
				break;
			};
			case kCFNumberCFIndexType: {
				CFIndex number;
				CFNumberGetValue(value, numberType, &number);
				printf("%ld\n",number);
				break;
			};
			case kCFNumberNSIntegerType: {
				NSInteger number;
				CFNumberGetValue(value, numberType, &number);
				printf("%ld\n",(long)number);
				break;
			};
			case kCFNumberCGFloatType: {
				CGFloat number;
				CFNumberGetValue(value, numberType, &number);
				printf("%.f\n",number);
				break;
			};
			default: {
				break;
			};
		}
	}
	CFSafeRelease(numberType);
	
	CFStringRef arrayType = CFCopyTypeIDDescription(CFArrayGetTypeID());
	if (CFStringCompare(valueType, arrayType, 0x0) == kCFCompareEqualTo) {
		foundType = true;
		CFIndex count = CFArrayGetCount(value);
		printf("[\n");
		for (CFIndex i = 0x0; i < count; i++) {
			CFTypeRef item = CFArrayGetValueAtIndex(value, i);
			PrintDepth(depth+0x1,"");
			PrintCFTypeInternalFormat(item, depth+0x1);
		}
		PrintDepth(depth,"]\n");
	}
	CFSafeRelease(arrayType);
	
	if (!foundType) {
		CFStringRef description = CFCopyDescription(value);
		printf("%s\n",(char*)CFStringGetCStringPtr(description,kCFStringEncodingUTF8));
		CFSafeRelease(description);
	}
	
	CFSafeRelease(valueType);
}

void PrintCFType(CFTypeRef value) {
	PrintCFTypeInternalFormat(value, 0x0);
}

void CFSafeRelease(CFTypeRef CF_RELEASES_ARGUMENT var) {
	if (var != NULL) {
		CFRelease(var);
	}
	var = NULL;
}

#endif