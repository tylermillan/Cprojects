#include <stdio.h>

void printBytes(unsigned char *start, int len) {
    for (int i = 0; i < len; ++i) {
        printf(" %.2x", start[i]);
}
    printf("\n");
}
void printInt(int x) {
    printBytes((unsigned char *) &x, sizeof(int));
}
void printFloat(float x) {
    printBytes((unsigned char *) &x, sizeof(float));
}
void printShort(short x){
	printBytes((unsigned char *) &x, sizeof(short));
}
void printLong(long x){
	printBytes((unsigned char *) &x, sizeof(long));
}
void printDouble(double x){
	printBytes((unsigned char *) &x, sizeof(double));
}
/*When adding the printShort,printLong, and printDouble, I copied 
the format of the already given printInt and printFloat functions and
replaced to the desired data type */

int main() 
{   int intx = 5;
	float floatx = intx;  /*Converted the test value of 5 for all tested
	data types to match the data type parameters for each of the functions  */
	short shortx = intx;
	long longx = intx;
	double doublex = intx;


	/*Passed all of the functions the previously defined 
	test value of 5  */
	
	printInt(intx); //output the correct hex representation of 5 as an int,also noticed it is stored as 4 bytes

	printFloat(floatx);  //output the correct hex representation of 5 as a float, also noticed it is stored as 4 bytes

	printShort(shortx);  //output the correct hex representation of 5 as a short, also noticed it is stored as 2 bytes

	printLong(longx); //output the correct hex representation of 5 as a long, also noticed it is stored as 8 bytes

	printDouble(doublex); //output the correct hex representation of 5 as a double, also noticed it is stored as 8 bytes

	/* A observation I made when it came to the outputs for all of the above test
	functions was that the hexidecimal output that represented 5 looked to be flipped
	i.e. I was expecting the int representation of 5 to be 00 00 00 05 instead it was
	output as 05 00 00 00, which signifies the least significant digit first. This is 
	attributed to what we learned in class about endianness with my CPU being little
	endian.*/ 
}