//
//  Buffer.h
//  Core
//
//  Created by Sam Marshall on 1/31/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef Core_Buffer_h
#define Core_Buffer_h

#include <stdlib.h>
#include <stdint.h>
#include "Range.h"

#define S(type) sizeof(type)

struct CoreInternalBuffer {
	char * data;
	uint64_t length;
};

typedef struct CoreInternalBuffer * BufferRef;

BufferRef CreateBufferRef();
// returns old size
uint64_t IncrementBufferRefBySize(BufferRef buffer, uint64_t size);

void AppendStringToBuffer(BufferRef buffer, char * append);
void AppendBufferToBuffer(BufferRef buffer, BufferRef append);

BufferRef CreateBufferFromBufferWithRange(BufferRef buffer, Range subRange);

BufferRef CreateBufferFromFilePath(char * path);
void BufferRefRelease(BufferRef buffer);

#endif
