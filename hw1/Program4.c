/* CS261- HW1 - Program4.c*/
/*Name: Troy Lopez
* Date: 1/15/2024
* Solution description: create and manipulate some structs for review
* */
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
struct student{
	char initials[2];
	int score;
};
struct student* allocate(int n){
	/*Allocate memory for ten students*/
	/*return the pointer*/
	struct student* stus = malloc(n * sizeof(struct student));
	return stus;
}
void generate(struct student* students, int n){
	/*Generate random initials and scores for ten students.
	 * The two initial letters must be capital and must be between A and Z.
	 * The scores must be between 0 and 100*/
	int i,s;
	char f,l;
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (i = 0; i < n; i++) {
		s = rand() % 101;
		f = letters[rand() % 26];
		l = letters[rand() % 26];
		students[i].initials[0] = f;
		students[i].initials[1] = l;
		students[i].score = s;
	}
}
void output(struct student* students, int n){
	/*Output information about the ten students in the format:
	 * 1. Initials Score
	 * 2. Initials Score
	 * ...
	 * 10. Initials Score*/

	int i;
	for (i = 0; i < n; i++) {
		printf("%d. %c%c %d\n",
				i,
				students[i].initials[0],
				students[i].initials[1],
			       	students[i].score
			);
	}	
}
void deallocate(struct student* stud){
	/*Deallocate memory from stud*/
	free(stud);
}

void sort(struct student* students, int n){
	/* sort n students by initials*/
	int i,j;
	char temp;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - 1; j++) {
			if (strcmp(students[j].initials, students[j + 1].initials) > 0) {
				temp = students[j].initials[0];
				students[j].initials[0] = students[j + 1].initials[0];
				students[j + 1].initials[0] = temp;
			
				
				temp = students[j].initials[1];
				students[j].initials[1] = students[j + 1].initials[1];
				students[j + 1].initials[1] = temp;
			}	
		}
	}

}


int main(){
	int n;
	struct student* stud = NULL;
	srand(time(NULL));
	/*n = (rand() % 27) - 1;*/
	
	printf("enter number of students: \n");
	scanf("%d", &n);
	

	/*early exit*/
	if (n < 1) {
		printf("No students were created b/c n was 0 (deteremined randomly. Please try again.");
		return 0;
	}

	/*printf("Note that number of students is decided randomly\n\n");*/
	/*call allocate*/
	stud = allocate(n);
	/*call generate*/
	generate(stud, n);
	/*call output*/
	output(stud, n);
	/*call sort */
	sort(stud, n);
	output(stud, n);
	/*call deallocate*/
	deallocate(stud);
	return 0;
}
