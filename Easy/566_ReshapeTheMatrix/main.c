#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 2
#define COLUMN_SIZE 2

//#define DEBUG

void printMatrix(int **A, int r, int c)
{
	int i, j;
	for (i=0;i<r;i++) {
		for (j=0;j<c;j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
	//printMatrix(nums, numsRowSize, numsColSize);
	int i, j;
	int total_element_num = numsRowSize*numsColSize;
#ifdef DEBUG
	printf("total_element_num=%d\n", total_element_num);
#endif

	if (r*c == numsRowSize*numsColSize) {
		*returnSize = r;
		*columnSizes = (int *) malloc(sizeof(int) * r);
		for (i=0;i<r;i++)
			(*columnSizes)[i] = c;
	}
	else {
		*returnSize = numsRowSize;
		*columnSizes = malloc(sizeof(int) * numsRowSize);
		for (i=0;i<numsRowSize;i++)
			(*columnSizes)[i] = numsColSize;
	}

	int *flat_array = (int *) malloc(sizeof(int) * total_element_num);
#ifdef DEBUG
	printf("numsRowSize=%d numsColSize=%d\n", numsRowSize, numsColSize);
#endif
	for (i=0;i<numsRowSize;i++) {
		for (j=0;j<numsColSize;j++) {
			flat_array[j+i*numsColSize] = nums[i][j];
		}
	}

#ifdef DEBUG
	for (i=0;i<total_element_num;i++)
		printf("flat_array[%d]:%d\n", i, flat_array[i]);
#endif

	int **result = (int **) malloc(sizeof(int *) * (*returnSize));
	for (i=0;i<(*returnSize);i++)
		*(result+i) = (int *) malloc(sizeof(int) * ((*columnSizes)[0]));

	for (i=0;i<(*returnSize);i++) {
		for (j=0;j<(*columnSizes)[0];j++) {
			result[i][j] = flat_array[j+i*((*columnSizes)[0])];
		}
	}

#ifdef DEBUG
	printMatrix(result, *returnSize, (*columnSizes)[0]);
#endif

	free(flat_array);

    return result;
}

int main(void)
{
	int Input[ROW_SIZE][COLUMN_SIZE] = {{1,2},{3,4}};
	//int Input[ROW_SIZE][COLUMN_SIZE] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int **A = (int **) malloc(sizeof(int *) * ROW_SIZE);
	for (int i=0;i<ROW_SIZE;i++) {
		*(A+i) = (int *) malloc(sizeof(int) * COLUMN_SIZE);
		for (int j=0;j<COLUMN_SIZE;j++)
			A[i][j] = Input[i][j];
	}

	printf("The input matrix is:\n");
	printMatrix(A, ROW_SIZE, COLUMN_SIZE);

	int *columnSizes, returnSize;
	int r = 1;
	int c = 4;
	int **reshapedMatrix = matrixReshape(A, ROW_SIZE, COLUMN_SIZE, r, c, &columnSizes, &returnSize);

	printf("The reshaped result is:\n");
	printMatrix(reshapedMatrix, returnSize, columnSizes[0]);

	return 0;
}

/*
In MATLAB, there is a very useful function called 'reshape', which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, respectively.

The reshaped matrix need to be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

Example 1:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 1, c = 4
Output: 
[[1,2,3,4]]
Explanation:
The row-traversing of nums is [1,2,3,4]. The new reshaped matrix is a 1 * 4 matrix, fill it row by row by using the previous list.
Example 2:
Input: 
nums = 
[[1,2],
 [3,4]]
r = 2, c = 4
Output: 
[[1,2],
 [3,4]]
Explanation:
There is no way to reshape a 2 * 2 matrix to a 2 * 4 matrix. So output the original matrix.
Note:
The height and width of the given matrix is in range [1, 100].
The given r and c are all positive.
*/