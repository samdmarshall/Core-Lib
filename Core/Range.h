//
//  Range.h
//  Core
//
//  Created by Sam Marshall on 12/8/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef Core_Range_h
#define Core_Range_h

#include <stdint.h>
#include <stdbool.h>

struct Range {
	uint64_t offset;
	uint64_t length;
} ATR_PACK;

typedef Range CoreRange;

#define CoreRangeCreate(offset, length) (CoreRange){offset, length}
#define CoreRangeContainsValue(range, value) (value >= range.offset && value < (range.offet + range.length))


#endif
