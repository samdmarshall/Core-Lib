//
//  File.c
//  Core
//
//  Created by Sam Marshall on 4/17/14.
//
//

#ifndef Core_File_c
#define Core_File_c

#include "File.h"
#include <sys/stat.h>
#include <sys/types.h>

bool FileExistsAtPath(char * path) {
	bool isDir;
	return FileExistsAtPathIsDir(path, &isDir);
}

bool FileExistsAtPathIsDir(char * path, bool * dir) {
	bool result = false;
	if (path) {
		struct stat pathStat;
		ssize_t stat_result = lstat(path, &pathStat);
		if (stat_result != -1) {
			result = true;
			*dir = S_ISDIR(pathStat.st_mode);
		}
	}
	return result;
}

#endif