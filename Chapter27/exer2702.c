// Write the parameterized macros INT32_C(n), UINT32_C(n), INT64_C(n), 
// and UINT64_C(n), assuming that the int type and long int types are 32btis wide and
// the long long int type is 64 bits wide. Hint: Use the ## preprocessor operator to attach
// a suffix to n containing a combination of L and/or U characters. (see Section 7.1 for a 
// discussion of how to use the L and U suffixes with integer constants.)

#define INT32_C(n) ##nL
#define UINT32_C(n) ##nUL
#define INT64_C(n) ##nLL
#define UINT64_C(n) ##nULL
