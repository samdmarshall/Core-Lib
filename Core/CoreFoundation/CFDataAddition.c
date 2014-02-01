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
#include <sys/stat.h>

CFDataRef CFDataFromFilePath(char *path) {
	CFDataRef dataBuffer = NULL;
	if (path) {
		struct stat pathStat;
		ssize_t result = lstat(path, &pathStat);
		if (result == -1) {
			return dataBuffer;
		}
		
		int ref = open(path, O_RDONLY);
		if (ref == -1) {
			return dataBuffer;
		}
		
		struct stat fileStat;
		result = fstat(ref, &fileStat);
		if (result == -1) {
			return dataBuffer;
		}
		
		unsigned char *data = calloc(1, (unsigned long)fileStat.st_size);
		result = read(ref, data, (size_t)fileStat.st_size);
		if (result == fileStat.st_size) {
			dataBuffer = CFDataCreate(kCFAllocatorDefault, data, result);
		}
		Safe(free,data);
	}
	return dataBuffer;
}


#endif