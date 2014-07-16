//
//  Core.h
//  Core
//
//  Created by Sam Marshall on 12/8/13.
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef Core_Core_h
#define Core_Core_h

#if __SDM_CORE_LIB

/*
 * Indicates that Core-Lib is being provided as a standalone library
 * and headers should be accessed in the exported location.
 */

#include <SDMCore/Pointer.h>
#include <SDMCore/Range.h>
#include <SDMCore/Number.h>
#include <SDMCore/Logging.h>
#include <SDMCore/Attributes.h>
#include <SDMCore/Buffer.h>
#include <SDMCore/Array.h>
#include <SDMCore/Endian.h>
#include <SDMCore/File.h>

#ifdef __COREGEOMETRY__
#include <SDMCore/Geometry/GeometryMaths.h>
#include <SDMCore/Geometry/Vector.h>
#include <SDMCore/Geometry/Matrix.h>
#endif

#ifdef __COREFOUNDATION_COREFOUNDATION__
#include <SDMCore/CoreFoundation/CFDictionaryAddition.h>
#include <SDMCore/CoreFoundation/CFTypeAddition.h>
#include <SDMCore/CoreFoundation/CFDataAddition.h>
#include <SDMCore/CoreFoundation/CFStringAddition.h>
#endif

#else

#pragma mark -
#pragma mark Standard
#include "Pointer.h"
#include "Range.h"
#include "Number.h"
#include "Logging.h"
#include "Attributes.h"
#include "Buffer.h"
#include "Array.h"
#include "Endian.h"
#include "File.h"

#pragma mark -
#pragma mark Geometry
#ifdef __COREGEOMETRY__
#include "GeometryMaths.h"
#include "Vector.h"
#include "Matrix.h"
#endif

#pragma mark -
#pragma mark CoreFoundation
#ifdef __COREFOUNDATION_COREFOUNDATION__ 
#include "CFDictionaryAddition.h"
#include "CFTypeAddition.h"
#include "CFDataAddition.h"
#include "CFStringAddition.h"
#endif

#endif // __SDM_CORE_LIB

#endif
