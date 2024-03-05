#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <limits.h>
#include "avl.h"



int FindMinPath(struct AVLTree *tree, TYPE *path);
void printBreadthFirstTree(struct AVLTree *tree);
int _findMin(struct AVLnode * cur, TYPE *path, int i);

/* -----------------------
The main function
  param: argv = pointer to the name (and path) of a file that the program reads for adding elements to the AVL tree
*/
int main(int argc, char** argv) {

	FILE *file;
	int len, i;
	TYPE num; /* value to add to the tree from a file */
	struct timeval stop, start; /* variables for measuring execution time */
	int pathArray[100];  /* static array with values of nodes along the min-cost path of the AVL tree. The means that the depth of the AVL tree cannot be greater than 100 which is  sufficient for our purposes*/

	struct AVLTree *tree;
	
	tree = newAVLTree(); /*initialize and return an empty tree */
	
	file = fopen(argv[1], "r"); 	/* filename is passed in argv[1] */
	assert(file != 0);
	printf("Successfully opened file %s\n", argv[1]);

	/* Read input file and add numbers to the AVL tree */
	while((fscanf(file, "%i", &num)) != EOF){
		addAVLTree(tree, num);		
	}
	/* Close the file  */
	fclose(file);
    printf("\nThe AVL tree has %d nodes.\n",tree->cnt);


	/*
	printf("\nPrinting the AVL tree breadth-first : \n");
	printBreadthFirstTree(tree);
	*/
	printf("\n\nStarting traverse: \n");
	gettimeofday(&start, NULL);

	/* Find the minimum-cost path in the AVL tree*/
	len = FindMinPath(tree, pathArray);	
	gettimeofday(&stop, NULL);

	/* Print out all numbers on the minimum-cost path */
	printf("\n\nThe minimum-cost path has %d nodes printed top-down from the root to the leaf: \n", len);
	for(i = 0; i < len; i++)
		printf("%d ", pathArray[i]);
	printf("\n");

	printf("\nYour execution time to find the mincost path is %f microseconds\n", (double) (stop.tv_usec - start.tv_usec));

        /* Free memory allocated to the tree */
	deleteAVLTree(tree); 
	
	return 0;
}


  
/* --------------------
Finds the minimum-cost path in an AVL tree
   Input arguments: 
        tree = pointer to the tree,
        path = pointer to array that stores values of nodes along the min-cost path, 
   Output: return the min-cost path length 

   pre: assume that
       path is already allocated sufficient memory space 
       tree exists and is not NULL
*/
int FindMinPath(struct AVLTree *tree, TYPE *path)
{
			/* FIX ME */
	/* theoretically should be all the way left or all the way left with one right at end*/
	struct AVLnode *current = tree->root;
	return _findMin(current, path, 0);

}

/* the path array isn't ever utilised and can be pruned for optimization if needed*/
int _findMin(struct AVLnode * cur, TYPE *path, int i) {
    
    int deltaL = INT_MAX;
    int deltaR = INT_MAX;

    if (cur == NULL) {
        return 0;
    }

    if (cur->left != NULL) {
        deltaL = abs(cur->left->val - cur->val);
    }

    if (cur->right != NULL) {
        deltaR = abs(cur->right->val - cur->val);
    }

	printf("\ncleared the if trees\n");
	printf("deltaL: %d\n", deltaL);
	printf("left: %d\n", cur->left->val);
	printf("deltaR: %d\n", deltaR);
	printf("right: %d\n", cur->right->val);
	deltaL = abs(cur->left->val - cur->val);
	deltaR = abs(cur->right->val - cur->val);

	if (deltaL <= deltaR) {
		path[i] = deltaL;
		printf("%d\n", deltaL);
		return deltaL + _findMin(cur->left, path, i + 1);
	} else {
		path[i] = deltaR;
		printf("%d\n", deltaR);
		return deltaR + _findMin(cur->right, path, i + 1);
	}
}


/* -----------------------
Printing the contents of an AVL tree in breadth-first fashion
  param: pointer to a tree
  pre: assume that tree was initialized well before calling this function
*/
void printBreadthFirstTree(struct AVLTree *tree)
{
   
    /* FIX ME */


}



