#include <stdio.h>

unsigned int replace(unsigned int x, int i, unsigned char b){

	//creates a 32 Byte value with the hexi value of 00 00 00 ff
	unsigned int negatedx = (0xFF) << i; 
	//each shift to the left moves the ff 8*i bits to the left position
	negatedx = negatedx << i;
	negatedx = negatedx << i;
	negatedx = negatedx << i;
	negatedx = negatedx << i;
	negatedx = negatedx << i;
	negatedx = negatedx << i;
	negatedx = negatedx << i;
	//we have the ff in the correct location for the correct given i value
	negatedx = x & ~negatedx; 
	// we then negate the hexi value with ff so we have byte of 0's and 6 f's which we use the AND operator with the given x

	unsigned int mask = b << i; // we now take our given byte b, and again shift it to the correct location using the method above
	mask = mask << i;
	mask = mask << i;
	mask = mask << i;
	mask = mask << i;
	mask = mask << i;
	mask = mask << i;
	mask = mask << i;

	unsigned int replaced = negatedx | mask; 
	//mask is OR operated with the negated x,the byte of 0's in negatedx will be replaced with the value of b


	printf("0x%08x",negatedx);
	printf("\n");

	return replaced;
}

void main(){
	//runs test cases
	replace(0x12345678, 2, 0xAB);
	replace(0x12345678, 0, 0xAB);
}