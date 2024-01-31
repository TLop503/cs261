/* bag2set.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"
/* Converts the input bag into a set using dynamic arrays
param: da -- pointer to a bag
return value: void
result: after exiting the function da points to a set
*/
void bag2set(struct DynArr *da)
{
	
	struct DynArr set;
	int flag = 0;
	int i, j;

	
	initDynArr(&set, da->size);
	set.size = 0;
	
	set.data[0] = da->data[0];
	set.size = 1;

	for (i = 1; i < da->size; i++) {
		flag = 0;
		for (j = 0; j < set.size; j++) {
			if (set.data[j] == da->data[i]) {
				flag = 1;
			}
		}
		if (flag == 0) {
			set.data[set.size] = da->data[i];
			/*printf("Added %g\n", set.data[set.size]);*/
			set.size++;
		}
	}
	
	/*	
	printf("Printing set:\n");
	for (i = 0; i < set.size; i++) {
		printf("%g\n", set.data[i]);
	}
	*/

	/* everything above this line is known to work*/

	freeDynArr(da);
	initDynArr(da, set.capacity);

	for (i = 0; i < set.size; i++) {
		da->data[i] = set.data[i];
	}
	da->size = set.size;
	
	freeDynArr(&set);	

}

/* An example how to test your bag2set() */
int main(int argc, char* argv[]){
	int i;
	struct DynArr da; /* bag */
	initDynArr(&da, 100);

	da.size = 11;
	da.data[0] = 1.3;
	for (i=1;i<da.size-1;i++){
		da.data[i] = 1.2;
	}

	da.data[da.size-1] = 1.4;
	printf("Bag:\n\n");
	for (i=0;i<da.size;i++){
		printf("%g \n", da.data[i]);
	}

	printf("\n\n\n");
	printf("Set:\n\n");
	
	bag2set(&da);
	/*printf("%d", da.size);*/
	for (i=0;i<da.size;i++){
		printf("%g ", da.data[i]);
	}
	printf("\n");
	return 0;
}

