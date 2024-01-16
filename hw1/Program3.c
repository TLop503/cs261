/* CS261- HW1 - Program3.c
 * Name: Troy Lopez
 * Date: 1/16/24
 * Solution Description: Simple selection sort b/c n is small enough to not need efficiency
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void sort(int* number, int n){
	/*Sort the array of integeres of length n*/
	int i,j;
	
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (number[j] > number[j + 1]) {
				/* fun xor trick to swap numbers */
				number[j] = number[j] ^ number[j+1];
				number[j+1] = number[j] ^ number[j+1];
				number[j] = number[j] ^ number[j+1];
			}
		}
	}
}
int main(){
	/*Declare an integer n and assign it a value of 20.*/
	/*Allocate memory for an array of n integers using malloc.*/
	/*Fill this array with random numbers, using rand().*/
	/*Print the contents of the array.*/
	/*Pass this array along with n to the sort() function of part a.*/
	/*Print the contents of the array.*/
	
	int n = 20;
	int i;
	int* arr = (int*)malloc(n * sizeof(int));

	srand(time(NULL));

	for (i = 0; i < n; i++){
		arr[i] = rand() % 1000;
		printf("%d  ", arr[i]);
	}
	printf("\n\n"); /*newline after printing unsorted */
	
	sort(arr, n);

	for (i = 0; i < n; i++){
		printf("%d  ", arr[i]);
	}	
	                
	printf("\n");
	free(arr);
	return 0;
}
