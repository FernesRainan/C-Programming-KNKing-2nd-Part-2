// In each of the following statements, assume that the variable i has the indicated original
// type. Using macros from the <inttypes.h> header, modify each statement so that it
// will work correctly if the type of i is changed to the indicated new type. 

// (a) printf("%d", i); 							 original type: int             new type: int8_t
// (b) printf("%12.4d", i);            original type: int             new type: int32_t
// (c) printf("%-6o", i);              original type: unsigned int    new type: uint16_t
// (d) printf("%#x", i);               original type: unsigned int    new type: uint64_t

// printf("i = %" PRIdLEAST32 "\n", i);
// printf("i = %" PRIdN "\n", i);
// PRIoN, PRIxN...
#include <inttypes.h>

printf("%" PRId8 "", i);
printf("%12.4" PRId32 "", i);
printf("%-6" PRIo16 "", i);
printf("%#" PRIx64 "", i);

