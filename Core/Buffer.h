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

#define S(type) sizeof(type)

struct CoreInternalBuffer {
	char *data;
	uint64_t length;
};

typedef struct CoreInternalBuffer* BufferRef;

BufferRef CreateBufferFromFilePath(char *path);

#endif
