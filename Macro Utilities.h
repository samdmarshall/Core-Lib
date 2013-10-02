//
//  Macro Utilities.h
//
//  Created by Sam Marshall
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef Macro_Utilities_h
#define Macro_Utilities_h

#import <float.h>
#import <Foundation/Foundation.h>

#define FloatCompareEqual(a, b) ((float)fabsf((a) - (b)) < FLT_EPSILON)
#define DoubleCompareEqual(a, b) ((double)fabs((a) - (b)) < DBL_EPSILON)

#define CGFloatAbs(a) (CGFLOAT_IS_DOUBLE ? fabs(a) : fabsf(a))
#define CGFloatCompareEqual(a, b) (CGFloatAbs((a) - (b)) < (CGFLOAT_IS_DOUBLE ? DBL_EPSILON : FLT_EPSILON))

#endif