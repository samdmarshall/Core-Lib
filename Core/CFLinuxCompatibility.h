//
//  CFLinuxCompatibility.h
//
//
//  Created by Jeremy Agostino on 6/11/14.
//  Copyright (c) 2014 Tekserve. All rights reserved.
//

#ifndef _CFLinuxCompatibility_h
#define _CFLinuxCompatibility_h

#if __linux__

// Note: This was only necessary for cross-compiling from OS X.
// I had to symlink a copy of $SYSROOT/usr/include/endian.h to
// $SYSROOT/usr/include/endian_.h to make it really get included.
#include <endian_.h>

#include <sys/types.h>

typedef int kern_return_t;

// SDMMobileDevice uses this darwin type
typedef int32_t __darwin_suseconds_t;

#include <CoreFoundation/CoreFoundation.h>

#endif // __linux__

#endif // _CFLinuxCompatibility_h
