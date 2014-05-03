//
//  CFDataAddition.c
//  Core
//
//  Created by Sam Marshall on 1/31/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef Core_CFDataAddition_c
#define Core_CFDataAddition_c

#include "CFDataAddition.h"
#include "Pointer.h"
#include "Buffer.h"
#include "CFStringAddition.h"

CFDataRef CFDataCreateFromPath(CFStringRef path) {
	CFIndex alloclen = CFStringGetMaximumSizeForEncoding(CFStringGetLength(path), kCFStringEncodingUTF8) + 1;
	char * cstr_path = calloc(1, alloclen);
	CFStringGetCString(path, cstr_path, alloclen, kCFStringEncodingUTF8);
	CFDataRef data = CFDataCreateFromFilePath(cstr_path);
	Safe(free,cstr_path);
	return data;
}

CFDataRef CFDataCreateFromFilePath(char * path) {
	BufferRef fileBuffer = CreateBufferFromFilePath(path);
	CFDataRef dataBuffer = CFDataCreate(kCFAllocatorDefault, PtrCast(fileBuffer->data,const UInt8*), (CFIndex)fileBuffer->length);
	Safe(BufferRefRelease, fileBuffer);
	return dataBuffer;
}

CFDataRef CFDataCreateFromSubrangeOfData(CFDataRef data, CFRange range) {
	CFMutableDataRef sub_data = CFDataCreateMutable(kCFAllocatorDefault, 0);
	UInt8 bytes[range.length];
	CFDataGetBytes(data, range, bytes);
	CFDataAppendBytes(sub_data, bytes, range.length);
	return sub_data;
}

Boolean CFDataWriteToPath(CFDataRef data, CFStringRef path) {
	char *c_path = CreateCStringFromCFStringRef(path);
	Boolean result = CFDataWriteToFilePath(data, c_path);
	free(c_path);
	return result;
}

Boolean CFDataWriteToFilePath(CFDataRef data, char * path) {
	Boolean result = true;
	mode_t fileMode = (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	int ref = open(path, O_CREAT | O_EXCL | O_WRONLY, fileMode);
	if (ref != -1) {
		CFIndex length = CFDataGetLength(data);
		CFIndex write_length = write(ref, CFDataGetBytePtr(data), length);
		result = ((write_length == length) ? true : false);
		close(ref);
	}
	else {
		result = false;
	}
	return result;
}


#endif