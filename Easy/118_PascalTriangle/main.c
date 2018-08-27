#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
	int i, j;

	*columnSizes = (int *) malloc(sizeof(int *) * numRows);
	int **result = (int **) malloc(sizeof(int *) * numRows);
	if (result != NULL) {
		for (i=0;i<numRows;i++) {
			(*columnSizes)[i] = i+1;
			*(result+i) = (int *) malloc(sizeof(int) * (i+1));
			for (j=0;j<(i+1);j++) {
#ifdef DEBUG
				printf("i:%d j:%d\n", i, j);
#endif
				if (j == 0 || j == i)
					*(*(result+i)+j) = 1;
				else
					*(*(result+i)+j) = *(*(result+i-1)+j-1) + *(*(result+i-1)+j);
			}
			
		}
	} 

    return result;
}

int main(void)
{
	int numRows = 5;
	int *columnSizes;

	printf("numRows:%d\n", numRows);

	int **result = generate(numRows, &columnSizes);
	printf("The result is:\n");
	for (int i=0;i<numRows;i++) {
		for (int j=0;j<columnSizes[i];j++) {
			printf("%d ", *(*(result+i)+j));
		}
		printf("\n");
	}

	return 0;
}

/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/