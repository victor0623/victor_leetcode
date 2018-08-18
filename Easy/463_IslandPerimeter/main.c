#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MATRIX_ROW 4
#define MATRIX_COLUMN 4

//#define DEBUG

bool isOutside(int x, int y, int gridRowSize, int gridColSize)
{
	if ( x<0 || x>=gridRowSize )
		return true;
	if ( y<0 || y>= gridColSize )
		return true;

	return false;
}

void printMatrix(int** matrix, int matrixRowSize, int matrixColSizes)
{
	for (int i=0;i<matrixRowSize;i++) {
		for (int j=0;j<matrixColSizes;j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return;
}

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
	int i, j, local_Perimeter, total_Perimeter = 0;
	int t_i, t_j, temp_i, temp_j;
	for (i=0;i<gridRowSize;i++) {
		for (j=0;j<gridColSize;j++) {
#ifdef DEBUG
			printf("grid[%d][%d]:%d\n", i, j, grid[i][j]);
#endif
			if (grid[i][j] == 1) {
				local_Perimeter = 0;
				for (t_i=-1;t_i<=1;t_i+=2) {
					temp_i = i+t_i;
					if (isOutside(temp_i, j, gridRowSize, gridColSize) == true ) {
						local_Perimeter++;
					}
					else {
						if (grid[temp_i][j] == 0)
							local_Perimeter++;
					}
				}
				
				for (t_j=-1;t_j<=1;t_j+=2) {
					temp_j = j+t_j;
					if (isOutside(i, temp_j, gridRowSize, gridColSize) == true ) {
						local_Perimeter++;
					}
					else {
						if (grid[i][temp_j] == 0)
							local_Perimeter++;
					}
				}
#ifdef DEBUG
				printf("local_Perimeter = %d\n", local_Perimeter);
#endif
				total_Perimeter += local_Perimeter;
#ifdef DEBUG
				printf("current perimeter:%d\n", total_Perimeter);
#endif
			}
		}
	}
    return total_Perimeter;
}

int main(void)
{
	int gridRowSize = MATRIX_ROW;
	int gridColSize = MATRIX_COLUMN;

	int M[MATRIX_ROW][MATRIX_COLUMN] = {{0,1,0,0},
										{1,1,1,0},
 										{0,1,0,0},
 										{1,1,0,0}};

	int **Input = (int **) malloc(sizeof(int *) * gridRowSize);
	for (int i=0;i<gridRowSize;i++) {
		Input[i] = (int *) malloc(sizeof(int) * gridColSize);
		for (int j=0;j<gridColSize;j++)
			Input[i][j] = M[i][j];
	}

	printf("Input matrix:\n");
	printMatrix(Input, gridRowSize, gridColSize);

	int landPerimeter = islandPerimeter(Input, gridRowSize, gridColSize);
	printf("The land perimeter is:%d\n", landPerimeter);

	return 0;
}

/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
*/