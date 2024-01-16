/* CS261- HW1 - Program1.c*/
/* Name: Troy Lopez
 * Date: 1/14/23
 * Solution Description:
 */



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int foo(int* a, int* b, int c){
	/* Increment a */
	/* Decrement b */
	/* Assign a-b to c */
	/* Return c */
	(*a)++;
	(*b)--;
	c = (*a - *b);
	return c;
}
int main(){
	/* Declare three integers x,y and z and initialize them randomly to values in
	 * [0,10] */
	/* Print the values of x, y and z */
	/* Call foo() appropriately, passing x,y,z as parameters */
	/* Print the values of x, y and z */
	/* Print the value returned by foo */
	/* Is the return value different than the value of z? Why? */
	
	int x,y,z;
	srand(time(NULL)); /*use random arbitrary number for seed*/

	x = rand() % 11;
	y = rand() % 11;
	z = rand() % 11;

	printf("Values before foo: %d %d %d\n", x, y, z);

	printf("Foo results: %d\n", foo(&x, &y, z));
	
	printf("Values after foo:%d %d %d\n", x, y, z);
	

	return 0;
}
