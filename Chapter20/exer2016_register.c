// Starting with the 386 processor, x86 CPUs have 32-bit registers named EAX, EBX, ECX,
// and EDX. The second half (the least significant bits) of these registers is the same as AX,
// BX, CX, and DX, respectively. Modify the regs union so that it includes these registers as
// well as the older ones. Your union should be set up so that modifying EAX changes AX and
// modifying AX changes the second half of EAX. (The other new registers will work in a 
// similar fashion) You'll need to add some "dummy" members to the word and byte structures,
// corresponding to the other half of EAX, EBX, ECX, and EDX. Declare the type of the new
// registers to be DWORD (double word), which should be defined as unsigned long. Don't
// forget that the x86 architecture is little-endian.

#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

union {
	struct {
		DWORD EAX, EBX, ECX, EDX;
	} dword;
	struct {
		WORD dummy0, AX, dummy1, BX, dummy2, CX, dummy3, DX;
	} word;
} regs;

int main(void)
{
	regs.dword.EAX = 0x12345678;
	printf("EAX = %X\n", regs.dword.EAX);
	regs.word.AX = 0xabcd;
	printf("AX = %X\n", regs.word.AX);
	printf("After processing EAX = %X\n", regs.dword.EAX);
	
	regs.word.CX = 0x4567;
	printf("CX = %X\n", regs.word.CX);
	regs.dword.ECX = 0x98765432;
	printf("ECX = %X\n", regs.dword.ECX);
	printf("After processing CX = %X\n", regs.word.CX);
	
	return 0;
}


	
	
	
	 
