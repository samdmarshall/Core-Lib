//
//  Buffer.c
//  Core
//
//  Created by Sam Marshall on 1/31/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef Core_Buffer_c
#define Core_Buffer_c

#include "Buffer.h"
#include "Pointer.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>

BufferRef CreateBufferFromFilePath(char *path) {
	BufferRef fileBuffer = calloc(0x1, sizeof(struct CoreInternalBuffer));
	if (path) {
		struct stat pathStat;
		ssize_t result = lstat(path, &pathStat);
		if (result == -1) {
			return fileBuffer;
		}
		
		int ref = open(path, O_RDONLY);
		if (ref == -1) {
			return fileBuffer;
		}
		
		struct stat fileStat;
		result = fstat(ref, &fileStat);
		if (result == -1) {
			return fileBuffer;
		}
		
		fileBuffer->length = read(ref, fileBuffer->data, (size_t)fileStat.st_size);
		
		close(ref);
	}
	return fileBuffer;
}

#endif