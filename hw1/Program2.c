/* CS261- HW1 - Program2.c*/
/*Name: Troy Lopez
* Date: 1/15/2024
* Solution description: create and manipulate some structs for review
* */
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct student{
	char initials[2];
	int score;
};
struct student* allocate(){
	/*Allocate memory for ten students*/
	/*return the pointer*/
	struct student* stus = malloc(10 * sizeof(struct student));
	return stus;
}
void generate(struct student* students){
	/*Generate random initials and scores for ten students.
	 * The two initial letters must be capital and must be between A and Z.
	 * The scores must be between 0 and 100*/
	int i,s;
	char f,l;
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (i = 0; i < 10; i++) {
		s = rand() % 101;
		f = letters[rand() % 26];
		l = letters[rand() % 26];
		students[i].initials[0] = f;
		students[i].initials[1] = l;
		students[i].score = s;
	}
}
void output(struct student* students){
	/*Output information about the ten students in the format:
	 * 1. Initials Score
	 * 2. Initials Score
	 * ...
	 * 10. Initials Score*/

	int i;
	for (i = 0; i < 10; i++) {
		printf("%d. %c%c %d\n",
				i,
				students[i].initials[0],
				students[i].initials[1],
			       	students[i].score
			);
	}	
}
void summary(struct student* students){
	/*Compute and print the minimum, maximum and average scores of the ten
	 * students*/
	int i, hscore = 0, lscore = 100, hstud, lstud;
	float a = 0;

	for (i = 0; i < 10; i++) {
		if (students[i].score > hscore){
			hscore = students[i].score;
			hstud = i;
		}
		if (students[i].score < lscore){
			lscore = students[i].score;
			lstud = i;
		}
		a += students[i].score;
	}
	a = a / 10;
	printf("Lowest Score: %d by student %c%c.\nHighest Score: %d by student %c%c.\nAverage Score: %f.\n",
			lscore,
			students[lstud].initials[0],
			students[lstud].initials[1],
			hscore,
			students[hstud].initials[0],
			students[hstud].initials[0],
			a
	      );
			
	
}
void deallocate(struct student* stud){
	/*Deallocate memory from stud*/
	free(stud);
}
int main(){
	struct student* stud = NULL;
	srand(time(NULL));
	/*call allocate*/
	stud = allocate();
	/*call generate*/
	generate(stud);
	/*call output*/
	output(stud);
	/*call summary*/
	summary(stud);
	/*call deallocate*/
	deallocate(stud);
	return 0;
}
