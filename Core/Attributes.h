//
//  Attributes.h
//  Core
//
//  Created by Sam Marshall on 12/8/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//


#ifndef Core_Attributes_h
#define Core_Attributes_h

#pragma mark -
#pragma mark Attributes
#define ATR_PACK __attribute__ ((packed))
#define ATR_FUNC(name) __attribute__ ((ifunc(name)))
#define ATR_UNUSED __attribute__ ((unused))

#endif
