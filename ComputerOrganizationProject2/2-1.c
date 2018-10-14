#include <stdio.h>

int mask(int n){
	unsigned int allone = 0xffffffff; //Creates a hex value that represents 32 bits of all 1's
	unsigned int onemask = allone << n; //creates a mask of all ones that gets shifted by the amount the parameter takes
	//creates the final mask by first negating both byte strings so our allone now becomes all a byte string of 0's
	//we also negate our all one mask so the amount we shift left becomes ones from the least significant side
	//i.e. if we are passed n=1, one mask's least significant byte becomes 1110 which when negated becomes 0001
	// when we subtract the negated one mask bits from the negated all one bits, all carry down since ~allone is all 0's
	unsigned int finalmask = (~onemask)-(~allone); 


	printf("0x%X\n", finalmask);
}

void main(){
	//runs test cases	
	mask(0);
	mask(1);
	mask(2);
	mask(3);
	mask(5);
	mask(8);
	mask(16);
	mask(31);
}