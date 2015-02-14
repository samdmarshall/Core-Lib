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
#define ATR_PACK __attribute__((packed))
#define ATR_FUNC(name) __attribute__((ifunc(name)))
#define ATR_UNUSED __attribute__((unused))

#ifndef __clang__
#define __has_feature(x) /* empty */
#endif

#if !__has_feature(objc_arc)
#define __unsafe_unretained /* empty */
#endif

#endif
