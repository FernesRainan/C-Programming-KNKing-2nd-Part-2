// Write a macro that has the same effect as try_math_fcn but builds the error 
// message from the function's name:
// y = TRY_MATH_FCN(sqrt, x);
// If the call of sqrt fails, the message will be Error in call of sqrt. 
// Hint: Have TRY_MATH_FCN call try_math_fcn.

#define TRY_MATH_FCN(f,x) try_math_fcn(f, x, "Error in call of" #f)
