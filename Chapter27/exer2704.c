// Assume that the following variable declarations are in effect:
// int i; float f; double d; long double ld; 
// float complex fc; double complex dc; long double complex ldc;
// Each of the following is an invocation of a macro in <tgmath.h>. Show what it will look
// like after preprocessing, when the macro has been replaced by a function from <math.h>
// or <complex.h>

// generic parameter is complex, then a <complex.h> function is chosen
// otherwise, a <math.h> function is selected. 

// If any argument is long double, then long double version function is called. 
// If any argument is double or integer, then double version function is called. 
// otherwise, float version is called. 

#include <tgmath.h>

tan(i)								tan(i);
fabs(f)								fabsf(f);
asin(d)								asin(d);
exp(ld)								expl(ld);
log(fc)								clogf(fc);
acosh(dc)							cacosh(dc);
nexttoward(d, ld)			nexttowardl(d, ld);
remainder(f, i)				remainder(f, i);
copysign(d, ld)				copysignl(d, ld);
carg(i)								arg(i);
cimag(f)							imagf(f);
conj(ldc)							cconjl(ldc);




