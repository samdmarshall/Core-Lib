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

CFStringRef CFTypeStringRep(CFTypeRef value) {
	CFStringRef string_rep = NULL;
	
	CFStringRef valueType = CFCopyTypeIDDescription(CFGetTypeID(value));
	
	CFStringRef booleanType = CFCopyTypeIDDescription(CFBooleanGetTypeID());
	if (CFStringCompare(valueType, booleanType, 0x0) == kCFCompareEqualTo) {
		string_rep = (CFBooleanGetValue(value) ? CFSTR("1") : CFSTR("0"));
	}
	CFSafeRelease(booleanType);
	
	CFStringRef stringType = CFCopyTypeIDDescription(CFStringGetTypeID());
	if (CFStringCompare(valueType, stringType, 0x0) == kCFCompareEqualTo) {
		string_rep = CFStringCreateCopy(kCFAllocatorDefault, value);
	}
	CFSafeRelease(stringType);
	
	CFStringRef numberType = CFCopyTypeIDDescription(CFNumberGetTypeID());
	if (CFStringCompare(valueType, numberType, 0x0) == kCFCompareEqualTo) {
		CFIndex numberType = CFNumberGetType(value);
		switch (numberType) {
			case kCFNumberSInt8Type: {
				SInt8 number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%hhd"),number);
				break;
			};
			case kCFNumberSInt16Type: {
				SInt16 number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%hd"),number);
				break;
			};
			case kCFNumberSInt32Type: {
				SInt32 number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%d"),(int32_t)number);
				break;
			};
			case kCFNumberSInt64Type: {
				SInt64 number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%lld"),number);
				break;
			};
			case kCFNumberFloat32Type: {
				Float32 number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%.f"),number);
				break;
			};
			case kCFNumberFloat64Type: {
				Float64 number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%.f"),number);
				break;
			};
			case kCFNumberCharType: {
				char number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%c"),number);
				break;
			};
			case kCFNumberShortType: {
				short number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%hd"),number);
				break;
			};
			case kCFNumberIntType: {
				int number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%d"),number);
				break;
			};
			case kCFNumberLongType: {
				long number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%ld"),number);
				break;
			};
			case kCFNumberLongLongType: {
				long long number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%qd"),number);
				break;
			};
			case kCFNumberFloatType: {
				float number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%.f"),number);
				break;
			};
			case kCFNumberDoubleType: {
				double number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%.f"),number);
				break;
			};
			case kCFNumberCFIndexType: {
				CFIndex number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%ld"),number);
				break;
			};
			case kCFNumberNSIntegerType: {
				NSInteger number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%ld"),(long)number);
				break;
			};
			case kCFNumberCGFloatType: {
				CGFloat number;
				CFNumberGetValue(value, numberType, &number);
				string_rep = CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%.f"),number);
				break;
			};
			default: {
				break;
			};
		}
	}
	CFSafeRelease(numberType);

	CFSafeRelease(valueType);
	
	return string_rep;
}

void PrintCFTypeInternalFormat(CFTypeRef value, uint32_t depth) {
	bool foundType = false;
	CFStringRef valueType = CFCopyTypeIDDescription(CFGetTypeID(value));
	CFStringRef dictionaryType = CFCopyTypeIDDescription(CFDictionaryGetTypeID());
	if (CFStringCompare(valueType, dictionaryType, 0x0) == kCFCompareEqualTo) {
		foundType = true;
		printf("<CFDictionary>={\n");
		PrintCFDictionaryInternalFormatting(value, depth+0x1);
		PrintDepth(depth,"}\n");
	}
	CFSafeRelease(dictionaryType);
	
	CFStringRef booleanType = CFCopyTypeIDDescription(CFBooleanGetTypeID());
	if (CFStringCompare(valueType, booleanType, 0x0) == kCFCompareEqualTo) {
		foundType = true;
		printf("<CFBoolean>={%s}\n",(CFBooleanGetValue(value) ? "True" : "False"));
	}
	CFSafeRelease(booleanType);
	
	CFStringRef stringType = CFCopyTypeIDDescription(CFStringGetTypeID());
	if (CFStringCompare(valueType, stringType, 0x0) == kCFCompareEqualTo) {
		foundType = true;
		printf("<CFStringRef>={%s}\n",(char *)CFStringGetCStringPtr(value,kCFStringEncodingUTF8));
	}
	CFSafeRelease(stringType);
	
	CFStringRef numberType = CFCopyTypeIDDescription(CFNumberGetTypeID());
	if (CFStringCompare(valueType, numberType, 0x0) == kCFCompareEqualTo) {
		foundType = true;
		printf("<CFNumberRef>=(");
		CFIndex numberType = CFNumberGetType(value);
		switch (numberType) {
			case kCFNumberSInt8Type: {
				SInt8 number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberSInt8Type){%hhd}\n",number);
				break;
			};
			case kCFNumberSInt16Type: {
				SInt16 number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberSInt16Type){%hd}\n",number);
				break;
			};
			case kCFNumberSInt32Type: {
				SInt32 number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberSInt32Type){%d}\n",(int32_t)number);
				break;
			};
			case kCFNumberSInt64Type: {
				SInt64 number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberSInt64Type){%lld}\n",number);
				break;
			};
			case kCFNumberFloat32Type: {
				Float32 number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberFloat32Type){%f}\n",number);
				break;
			};
			case kCFNumberFloat64Type: {
				Float64 number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberFloat64Type){%f}\n",number);
				break;
			};
			case kCFNumberCharType: {
				char number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberCharType){%c}\n",number);
				break;
			};
			case kCFNumberShortType: {
				short number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberShortType){%hd}\n",number);
				break;
			};
			case kCFNumberIntType: {
				int number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberIntType){%d}\n",number);
				break;
			};
			case kCFNumberLongType: {
				long number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberLongType){%ld}\n",number);
				break;
			};
			case kCFNumberLongLongType: {
				long long number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberLongLongType){%qd}\n",number);
				break;
			};
			case kCFNumberFloatType: {
				float number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberFloatType){%f}\n",number);
				break;
			};
			case kCFNumberDoubleType: {
				double number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberDoubleType){%f}\n",number);
				break;
			};
			case kCFNumberCFIndexType: {
				CFIndex number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberCFIndexType){%ld}\n",number);
				break;
			};
			case kCFNumberNSIntegerType: {
				NSInteger number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberNSIntegerType){%ld}\n",(long)number);
				break;
			};
			case kCFNumberCGFloatType: {
				CGFloat number;
				CFNumberGetValue(value, numberType, &number);
				printf("kCFNumberCGFloatType){%f}\n",number);
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
		printf("<CFArray>=[\n");
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
		printf("<%s>={%s}\n",(char *)CFStringGetCStringPtr(valueType,kCFStringEncodingUTF8),(char *)CFStringGetCStringPtr(description,kCFStringEncodingUTF8));
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