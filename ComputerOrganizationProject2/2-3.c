#include <stdio.h>

int ge(float x, float y) {
	unsigned int ux = *((unsigned int*) &x); // convert x raw bits unsigned 
	int uy = *((unsigned int*) &y); // convert y raw bits 
	unsigned int sx = ux >> 31; // extract sign bit of ux 
	unsigned int sy = uy >> 31; // extract sign bit of uy
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy
	// TODO: return using sx, sy, ux, uy
	int signbitcomp = sx == sy;// compares the two sign bits of x and y and will become a 1 if they are equal or a 0 if not

	//compares the unsigned values of x and y and will return 1 if the unsigned value of x is > or = than the unsigned value of y
	int ge = ux >= uy; 

	//inverse of the above,will return 1 if the unsigned value of x is less than or equal to the unsigned value of y
	int less = ux <= uy; 

	// we add to our above definition of less to include the result of the signbit comp and use AND logical operator
	//so both signbit comp and >= have to be true to return 1, otherwise returns 0
	less = (less && !signbitcomp);

	// we add to our above definition of ge to include the result of the signbit comp and use AND logical operator
	//so both signbit comp and >= have to be true to return 1, otherwise returns 0
	ge = (ge && signbitcomp);

	int result = less || ge;//the two are compared using OR logical operator meaning if either returns a 1 the entire statement will return 1
	//otherwise will return  0
	printf("%1X\n", result);

	return result;

}

void main(){
	//runs test cases
	ge(0.0f, 0.0f);
	ge(-0.0f, 0.0f);
	ge(-1.0f, 0.0f);
	ge(0.0f, 1.0f);
	ge(1.0f, 0.0f);
	ge(0.0f, -1.0f);
}