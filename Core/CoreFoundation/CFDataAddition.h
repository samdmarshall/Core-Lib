//
//  CFDataAddition.h
//  Core
//
//  Created by Sam Marshall on 1/31/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef Core_CFDataAddition_h
#define Core_CFDataAddition_h

#include <CoreFoundation/CoreFoundation.h>

CFDataRef CFDataCreateFromPath(CFStringRef path);
CFDataRef CFDataCreateFromFilePath(char * path);

CFDataRef CFDataCreateFromSubrangeOfData(CFDataRef data, CFRange range);

Boolean CFDataWriteToPath(CFDataRef data, CFStringRef path);
Boolean CFDataWriteToFilePath(CFDataRef data, char * path);

#endif
