#include <stdio.h>

unsigned int combine(unsigned int x, unsigned int y){
	unsigned int maskedx = 0xffff0000 & x;
	/*Since we would like to extract byte's 3 and 2 from x, I want to get rid of the bytes 0 and 1,
	which can be done by combining the given x and using the AND operation with my created bitmask 0xffff0000.
	The AND operation will combine x to the mask replacing any bytes that do not occur in both. Since 0x
	occurs in both, it occurs in the maskedx. The lowercase f's in the mask will combine with any bits and
	in x and keep not change them as desired, while finally the 0's at the 0 and 1 byte location will combine 
	with x's byte 1 and 2 causing them to turn into 0's, as desired */

	unsigned int maskedy = 0x0000ffff & y; // same logic as above, but instead extracting bytes 0 and 1

	unsigned int combined = maskedx | maskedy; //combines both to create a hex with bytes 2 and 3 from x and bytes 1 and 0 from y
	
	printf("0x%08x", combined);
	printf("\n");

	return combined;
}
 
 void main(){
	//runs test cases
	combine(0x12345678,0xABCDEF00);
	combine(0xABCDEF00,0x12345678);

}