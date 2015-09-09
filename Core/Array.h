//
//  Array.h
//  Core
//
//  Created by Samantha Marshall on 2/15/14.
//  Copyright (c) 2014 Samantha Marshall. All rights reserved.
//

#ifndef Core_Array_h
#define Core_Array_h

#include "Pointer.h"

struct CoreInternalArray {
	Pointer items;
	uint64_t count;
} ATR_PACK;

typedef struct CoreInternalArray *ArrayRef;

#endif
