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

CFDataRef CFDataFromFilePath(char *path) {
	BufferRef fileBuffer = CreateBufferFromFilePath(path);
	return CFDataCreate(kCFAllocatorDefault, PtrCast(fileBuffer->data,const UInt8*), fileBuffer->length);
}


#endif