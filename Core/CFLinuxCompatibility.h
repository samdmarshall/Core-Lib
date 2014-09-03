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

#include <sys/types.h>

typedef int kern_return_t;

// SDMMobileDevice uses this darwin type
typedef int32_t __darwin_suseconds_t;

#include <CoreFoundation/CoreFoundation.h>

#endif // __linux__

#endif // _CFLinuxCompatibility_h
