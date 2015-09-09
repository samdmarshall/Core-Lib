//
//  File.h
//  Core
//
//  Created by Samantha Marshall on 4/17/14.
//
//

#ifndef Core_File_h
#define Core_File_h

#include <stdlib.h>
#include <stdbool.h>

bool FileExistsAtPath(char *path);
bool FileExistsAtPathIsDir(char *path, bool *dir);

#endif
