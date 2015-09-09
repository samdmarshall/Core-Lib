//
//  Buffer.c
//  Core
//
//  Created by Samantha Marshall on 1/31/14.
//  Copyright (c) 2014 Samantha Marshall. All rights reserved.
//

#ifndef Core_Buffer_c
#define Core_Buffer_c

#include "Buffer.h"
#include "Pointer.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <string.h>

BufferRef CreateBufferRef()
{
	BufferRef buffer = calloc(1, sizeof(struct CoreInternalBuffer));
	buffer->data = calloc(1, sizeof(char));
	buffer->length = 1;
	return buffer;
}

uint64_t IncrementBufferRefBySize(BufferRef buffer, uint64_t size)
{
	uint64_t oldSize = buffer->length;
	buffer->length = oldSize + size;
	buffer->data = realloc(buffer->data, (unsigned long)buffer->length);
	memset(&(buffer->data[oldSize]), 0, size);
	return oldSize;
}

void AppendStringToBuffer(BufferRef buffer, char *append)
{
	BufferRef appendBuffer = CreateBufferRef();
	IncrementBufferRefBySize(appendBuffer, strlen(append) - 1);
	memcpy(appendBuffer->data, append, strlen(append));
	AppendBufferToBuffer(buffer, appendBuffer);
	BufferRefRelease(appendBuffer);
}

void AppendBufferToBuffer(BufferRef buffer, BufferRef append)
{
	uint64_t offset = IncrementBufferRefBySize(buffer, append->length);
	memcpy(&(buffer->data[offset]), append->data, append->length);
}

BufferRef CreateBufferFromBufferWithRange(BufferRef buffer, Range subRange)
{
	BufferRef sub = CreateBufferRef();
	IncrementBufferRefBySize(sub, subRange.length - 1);
	memcpy(sub->data, &(buffer->data[subRange.offset]), subRange.length);
	return sub;
}

BufferRef CreateBufferFromFilePath(char *path)
{
	BufferRef fileBuffer = calloc(1, sizeof(struct CoreInternalBuffer));
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

		fileBuffer->data = calloc((uint32_t)fileStat.st_size, sizeof(char));
		fileBuffer->length = read(ref, fileBuffer->data, (size_t)fileStat.st_size);

		close(ref);
	}
	return fileBuffer;
}

void BufferRefRelease(BufferRef buffer)
{
	if (buffer) {
		free(buffer->data);
	}
	free(buffer);
}

#endif