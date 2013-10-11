//
//  Macro Utilities.h
//
//  Created by Sam Marshall
//  Copyright (c) 2013 Sam Marshall. All rights reserved.
//

#ifndef Macro_Utilities_h
#define Macro_Utilities_h

#include <float.h>
#import <Foundation/Foundation.h>

#pragma mark -
#pragma mark Float

#define FloatCompareEqual(a, b) ((float)fabs((a) - (b)) < FLT_EPSILON)

#pragma mark -
#pragma mark CGFloat

#pragma mark Trigonometric Functions
#define CGFloatCos(a) (CGFLOAT_IS_DOUBLE ? cos(a) : cosf(a))
#define CGFloatSin(a) (CGFLOAT_IS_DOUBLE ? sin(a) : sinf(a))
#define CGFloatTan(a) (CGFLOAT_IS_DOUBLE ? tan(a) : tanf(a))
#define CGFloatACos(a) (CGFLOAT_IS_DOUBLE ? acos(a) : acosf(a))
#define CGFloatASin(a) (CGFLOAT_IS_DOUBLE ? asin(a) : asinf(a))
#define CGFloatATan(a) (CGFLOAT_IS_DOUBLE ? atan(a) : atanf(a))
#define CGFloatATan2(a, b) (CGFLOAT_IS_DOUBLE ? atan2(a, b) : atan2f(a, b))

#pragma mark Hyperbolic Functions
#define CGFloatCosH(a) (CGFLOAT_IS_DOUBLE ? cosh(a) : coshf(a))
#define CGFloatSinH(a) (CGFLOAT_IS_DOUBLE ? sinh(a) : sinhf(a))
#define CGFloatTanH(a) (CGFLOAT_IS_DOUBLE ? tanh(a) : tanhf(a))
#define CGFloatACosH(a) (CGFLOAT_IS_DOUBLE ? acosh(a) : acoshf(a))
#define CGFloatASinH(a) (CGFLOAT_IS_DOUBLE ? asinh(a) : asinhf(a))
#define CGFloatATanH(a) (CGFLOAT_IS_DOUBLE ? atanh(a) : atanhf(a))

#pragma mark Exponential and Logarithmic Functions
#define CGFloatExp(a) (CGFLOAT_IS_DOUBLE ? exp(a) : expf(a))
#define CGFloatFrExp(a, b) (CGFLOAT_IS_DOUBLE ? frexp(a, b) : frexpf(a, b))
#define CGFloatLdExp(a, b) (CGFLOAT_IS_DOUBLE ? ldexp(a, b) : ldexpf(a, b))
#define CGFloatLog(a) (CGFLOAT_IS_DOUBLE ? log(a) : logf(a))
#define CGFloatLog10(a) (CGFLOAT_IS_DOUBLE ? log10(a) : log10f(a))
#define CGFloatModf(a, b) (CGFLOAT_IS_DOUBLE ? modf(a, b) : modff(a, b))
#define CGFloatExp2(a) (CGFLOAT_IS_DOUBLE ? exp2(a) : exp2f(a))
#define CGFloatExpm1(a) (CGFLOAT_IS_DOUBLE ? expm1(a) : expm1(a))
#define CGFloatiLogb(a) (CGFLOAT_IS_DOUBLE ? ilogb(a) : ilogbf(a))
#define CGFloatLog1p(a) (CGFLOAT_IS_DOUBLE ? log1p(a) : log1pf(a))
#define CGFloatLog2(a) (CGFLOAT_IS_DOUBLE ? log2(a) : log2f(a))
#define CGFloatLogb(a) (CGFLOAT_IS_DOUBLE ? logb(a) : logbf(a))
#define CGFloatScalbn(a, b) (CGFLOAT_IS_DOUBLE ? scalbn(a, b) : scalbnf(a, b))
#define CGFloatScalbln(a, b) (CGFLOAT_IS_DOUBLE ? scalbln(a, b) : scalblnf(a, b))

#pragma mark Power Functions
#define CGFloatPow(a, b) (CGFLOAT_IS_DOUBLE ? pow(a, b) : powf(a, b))
#define CGFloatSqrt(a) (CGFLOAT_IS_DOUBLE ? sqrt(a) : sqrtf(a))
#define CGFloatCbrt(a) (CGFLOAT_IS_DOUBLE ? cbrt(a) : cbrtf(a))
#define CGFloatHypot(a) (CGFLOAT_IS_DOUBLE ? hypot(a) : hypotf(a))

#pragma mark Error and Gamma Functions
#define CGFloatErf(a) (CGFLOAT_IS_DOUBLE ? erf(a) : erff(a))
#define CGFloatErfc(a) (CGFLOAT_IS_DOUBLE ? erfc(a) : erfcf(a))
#define CGFloatTGamma(a) (CGFLOAT_IS_DOUBLE ? tgamma(a) : tgammaf(a))
#define CGFloatLGamma(a) (CGFLOAT_IS_DOUBLE ? lgamma(a) : lgammaf(a))

#pragma mark Rounding and Remainder Functions
#define CGFloatCeil(a) (CGFLOAT_IS_DOUBLE ? ceil(a) : ceilf(a))
#define CGFloatFloor(a) (CGFLOAT_IS_DOUBLE ? floor(a) : floorf(a))
#define CGFloatFmod(a, b) (CGFLOAT_IS_DOUBLE ? fmod(a, b) : fmodf(a, b))
#define CGFloatTrunc(a) (CGFLOAT_IS_DOUBLE ? trunc(a) : truncf(a))
#define CGFloatRound(a) (CGFLOAT_IS_DOUBLE ? round(a) : roundf(a))
#define CGFloatLRound(a) (CGFLOAT_IS_DOUBLE ? lround(a) : lroundf(a))
#define CGFloatLLRound(a) (CGFLOAT_IS_DOUBLE ? llround(a) : llroundf(a))
#define CGFloatRint(a) (CGFLOAT_IS_DOUBLE ? rint(a) : rintf(a))
#define CGFloatLRint(a) (CGFLOAT_IS_DOUBLE ? lrint(a) : lrintf(a))
#define CGFloatLLRint(a) (CGFLOAT_IS_DOUBLE ? llrint(a) : llrint(a))
#define CGFloatNearbyInt(a) (CGFLOAT_IS_DOUBLE ? nearbyint(a) : nearbyintf(a))
#define CGFloatRemainder(a, b) (CGFLOAT_IS_DOUBLE ? remainder(a, b) : remainderf(a, b))
#define CGFloatRemQuo(a, b) (CGFLOAT_IS_DOUBLE ? remquo(a, b) : remquof(a, b))

#pragma mark Floating-Point Manipulation Functions
#define CGFloatCopySign(a, b) (CGFLOAT_IS_DOUBLE ? copysign(a, b) : copysignf(a, b))
#define CGFloatNextAfter(a, b) (CGFLOAT_IS_DOUBLE ? nextafter(a, b) : nextafterf(a, b))
#define CGFloatNextToward(a, b) (CGFLOAT_IS_DOUBLE ? nexttoward(a, b) : nexttowardf(a, b))

#pragma mark Minimum, Maximum, Difference Functions
#define CGFloatFDim(a, b) (CGFLOAT_IS_DOUBLE ? fdim(a, b) : fdimf(a, b))
#define CGFloatFMax(a, b) (CGFLOAT_IS_DOUBLE ? fmax(a, b) : fmaxf(a, b))
#define CGFloatFMin(a, b) (CGFLOAT_IS_DOUBLE ? fmin(a, b) : fminf(a, b))

#pragma Misc Functions
#define CGFloatAbs(a) (CGFLOAT_IS_DOUBLE ? fabs(a) : fabsf(a))
#define CGFloatFMA(a, b, c) (CGFLOAT_IS_DOUBLE ? fma(a, b, c) : fmaf(a, b, c))

#pragma mark Additional Useful Comparisons

#define CGFloatCompareEqual(a, b) (CGFloatAbs((a) - (b)) < (CGFLOAT_IS_DOUBLE ? DBL_EPSILON : FLT_EPSILON))

#pragma mark -
#pragma mark NS(U)Integer

#define MakeNSIntegerUnsigned(a) a = (a < 0 ? 0 : a)

#endif