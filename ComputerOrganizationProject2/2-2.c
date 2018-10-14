#include <stdio.h>

unsigned int extract (unsigned int x, int i){
	//We start off by shifting the value i by 3 bits which is the equivalent of multiplying the value i by 2^3 or 8 
	// we then subtract this by 24 by this value which when we shift to the right will leave our desired byte in the most significant location  
	int shifted = x <<  (24-(i<<3)); 

	//we now shift the right(arithmetic) by 24 bits or 3 bytes which unlike a left shift, preserves the most significant bit on signed values
	//by padding the left side with this number
	//i.e. 100001 >> 3 would lead to 111100 thus preserving the sign of the value
	int final = shifted>>24;

	printf("0x%08x\n", final);

	return final;

}
void main(){
	//runs test cases
	extract(0x12345678, 0);
	extract(0xABCDEF00, 2);
}