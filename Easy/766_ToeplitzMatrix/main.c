#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MATRIX_ROW 3
#define MATRIX_COLUMN 4

void printMatrix(int** matrix, int matrixRowSize, int *matrixColSizes)
{
	int column_num = matrixColSizes[0];
	for (int i=0;i<matrixRowSize;i++) {
		for (int j=0;j<column_num;j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return;
}

void printDiagonal(int** matrix, int matrixRowSize, int *matrixColSizes)
{
	int column_num = matrixColSizes[0];
	int temp_i, temp_j, isSafe;

	//printf("matrixRowSize:%d column_num:%d\n", matrixRowSize, column_num);
	//for the first row
	for (int j=0;j<column_num;j++) {
		temp_i = 0;
		temp_j = j;
		isSafe = 1;
		while (isSafe) {
			printf("%d ", matrix[temp_i][temp_j]);
			temp_i++;
			temp_j++;
			if (temp_i == matrixRowSize || temp_j == column_num)
				isSafe = 0;
		}
		printf("\n");
	}

	for (int i=1;i<matrixRowSize;i++) {
		temp_i = i;
		temp_j = 0;
		isSafe = 1;
		while (isSafe) {
			printf("%d ", matrix[temp_i][temp_j]);
			temp_i++;
			temp_j++;
			if (temp_i == matrixRowSize || temp_j == column_num)
				isSafe = 0;
		}
		printf("\n");
	}	

	return;
}

bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes) {
	int isToeplitz = true;
	int column_num = matrixColSizes[0];
	int temp_i, temp_j, isSafe, current, previous;

	//process first row
	for (int j=0;j<column_num;j++) {
		temp_i = 0;
		temp_j = j;
		isSafe = 1;
		previous = matrix[temp_i][temp_j];
		while (isSafe) {
			current = matrix[temp_i][temp_j];
			if (current != previous) {
				isToeplitz = false;
				break;
			}
			
			previous = matrix[temp_i][temp_j];
			temp_i++;
			temp_j++;
			if (temp_i == matrixRowSize || temp_j == column_num)
				isSafe = 0;
		}
		if (isToeplitz == false)
			break;
	}

	//process first column
	if (isToeplitz == true) {
		for (int i=1;i<matrixRowSize;i++) {
			temp_i = i;
			temp_j = 0;
			isSafe = 1;
			previous = matrix[temp_i][temp_j];
			while (isSafe) {
				current = matrix[temp_i][temp_j];
				if (current != previous) {
					isToeplitz = false;
					break;
				}
				
				previous = matrix[temp_i][temp_j];
				temp_i++;
				temp_j++;
				if (temp_i == matrixRowSize || temp_j == column_num)
					isSafe = 0;
			}
			if (isToeplitz == false)
				break;
		}
	}
	
	return isToeplitz;
}

int main(void)
{
	int matrixRowSize = MATRIX_ROW;
	int *matrixColSizes = (int *) malloc(sizeof(int) * matrixRowSize);
	for (int i=0;i<matrixRowSize;i++)
		matrixColSizes[i] = MATRIX_COLUMN;

	int M[MATRIX_ROW][MATRIX_COLUMN] = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};

	int **Input = (int **) malloc(sizeof(int *) * matrixRowSize);
	for (int i=0;i<matrixRowSize;i++) {
		Input[i] = (int *) malloc(sizeof(int) * matrixColSizes[i]);
		for (int j=0;j<matrixColSizes[i];j++)
			Input[i][j] = M[i][j];
	}

	printf("Input matrix:\n");
	printMatrix(Input, matrixRowSize, matrixColSizes);

	bool isToeplitz = isToeplitzMatrix(Input, matrixRowSize, matrixColSizes);
	if (isToeplitz == true)
		printf("This is Toeplitz Matrix!\n");
	else
		printf("This is not Toeplitz Matrix!\n");

	return 0;
}

/*
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
 

Example 1:

Input:
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
Output: True
Explanation:
In the above grid, the diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
Example 2:

Input:
matrix = [
  [1,2],
  [2,2]
]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.

Note:

matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].

Follow up:

What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
What if the matrix is so large that you can only load up a partial row into the memory at once?
*/