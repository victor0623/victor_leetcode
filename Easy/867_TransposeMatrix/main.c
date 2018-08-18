#include <stdio.h>
#include <stdlib.h>

#define DEBUG

void printMarix(int** A, int RowSize, int ColumnSize)
{
	for (int i=0;i<RowSize;i++) {
		for (int j=0;j<ColumnSize;j++)
			printf("A[%d][%d]:%d ", i, j, A[i][j]);
		printf("\n");
	}
	return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
	int i,j;
	int TRowSize = AColSizes[0];
	int TColumeSize = ARowSize;

	int ** T = (int **) malloc(sizeof(int *) * TRowSize);
	for (i=0;i<TRowSize;i++) {
		*(T+i) = (int *) malloc(sizeof(int) * TColumeSize);
	}

#ifdef DEBUG
	printf("A matrix is:\n");
	printMarix(A, ARowSize, AColSizes[0]);
	printf("\n");
#endif

	for (i=0;i<TRowSize;i++) {
    	for(j=0;j<TColumeSize;j++) {
    		T[i][j] = A[j][i];
    	}
    }

#ifdef DEBUG
    printf("The transpose of A is:\n");
    printMarix(T, TRowSize, TColumeSize);
    printf("\n");
#endif

    *returnSize = TRowSize;
    *columnSizes = malloc(sizeof(int) * TRowSize);
    for (i=0;i<TRowSize;i++)
    	(*columnSizes)[i] = TColumeSize;

    return T;
}

int main(void)
{
	int ARowSize = 2;
	int *AColSizes = (int *) malloc(sizeof(int)*ARowSize);
	for (int i=0;i<ARowSize;i++)
		*(AColSizes+i) = 3;

	//int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

	int ** A = (int **) malloc(sizeof(int *) * ARowSize);
	int count = 1;
	for (int i=0;i<ARowSize;i++) {
		*(A+i) = (int *) malloc(sizeof(int) * AColSizes[i]);
		for(int j=0;j < *(AColSizes+i);j++) {
			*(*(A+i)+j) = count;
			count++;
		}
	}

	int *columnSizes, returnSize;
	int **R = transpose(A, ARowSize, AColSizes, &columnSizes, &returnSize);

#ifdef DEBUG
	printf("returnSize:%d\n", returnSize);

	for (int i=0;i<returnSize;i++)
		printf("columnSizes[%d]:%d\n", i, columnSizes[i]);

	printf("The result is:\n");
	printMarix(R, returnSize, columnSizes[0]);
#endif

	free(A);
	return 0;
}

/*
Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Note:

1 <= A.length <= 1000
1 <= A[0].length <= 1000

[[1,2,3],[4,5,6]]
*/