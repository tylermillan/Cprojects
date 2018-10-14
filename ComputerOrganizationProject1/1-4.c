#include <stdio.h>

int oddBit(unsigned int x){
	//a hex value of a is represented in binary as 1010 so we scale this to be 8 of these which represents the desired 32 bits
	unsigned int mask = 0xAA; //the mask uses the pattern above which has all odd position bits set to one i.e. (1010 1010 1010 1010)
	mask = !(!(mask & x));
	/*when we combine the mask using the AND operator with the given 32 bit word x,
	 any one's that appear would indicate at least one 1 in the odd position.
	 We then use the ! logical operation that when applied to an int will return 0x00000001 if the number is equal to 0,
	 and will return 0x00000000 if it is not equal to 0, we do this a second time because we want reverse this logic it so
	  that we can have it return 0x00000000 when it is equal to 0 */
	printf("%1X\n", mask);// returns the last number of the above  
	return mask;
	}

int main(){
	//runs test cases	
	oddBit(0x1);
	oddBit(0x2);
	oddBit(0x3);
	oddBit(0x4);
	oddBit(0xFFFFFFFF);
	oddBit(0xAAAAAAAA);
	oddBit(0x55555555);
}