#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW_SIZE 5
#define COLUMN_SIZE 2

//#define DEBUG

void printMatrix(int **A, int r, int c)
{
	int i, j;
	for (i=0;i<r;i++) {
		for (j=0;j<c;j++) {
			printf("%d ", A[i][j]);
			//printf("A[%d][%d]:%d ", i, j, A[i][j]);
		}
		printf("\n");
	}
}

double calculateTriangleArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int sum = abs((x1*y2-x2*y1) + (x2*y3-x3*y2)+(x3*y1-x1*y3));
	double t_area = ((double) sum) / 2;
	return t_area;
}

double largestTriangleArea(int** points, int pointsRowSize, int *pointsColSizes) {
	int ColSizes = pointsColSizes[0];
#ifdef DEBUG
	printMatrix(points, pointsRowSize, ColSizes);
#endif

	
	double largest_t_area = 0;
	double t_area;

	int i, j, k;
	int x1, y1, x2, y2, x3, y3;
	int group_num = 0;
	for (i=0;i<pointsRowSize-2;i++) {
		x1 = points[i][0];
		y1 = points[i][1];

		for (j=i+1;j<pointsRowSize-1;j++) {
			x2 = points[j][0];
			y2 = points[j][1];
			for (k=j+1;k<pointsRowSize;k++) {
				x3 = points[k][0];
				y3 = points[k][1];
				group_num++;
				/*
				printf("(x1,y1)=(%d,%d)\n", x1, y1);
				printf("(x2,y2)=(%d,%d)\n", x2, y2);
				printf("(x3,y3)=(%d,%d)\n", x3, y3);
				*/
				t_area = calculateTriangleArea(x1,y1,x2,y2,x3,y3);
#ifdef DEBUG
				printf("t_area = %f\n", t_area);
#endif
				if (t_area >= largest_t_area)
					largest_t_area = t_area;
			}
		}
	}

#ifdef DEBUG
	printf("group_num = %d\n", group_num);
#endif
	
	return largest_t_area;
}

int main(void)
{
	int Points[ROW_SIZE][COLUMN_SIZE] = {{0,0},{0,1},{1,0},{0,2},{2,0}};

	int **A = (int **) malloc(sizeof(int *) * ROW_SIZE);
	for (int i=0;i<ROW_SIZE;i++) {
		*(A+i) = (int *) malloc(sizeof(int) * COLUMN_SIZE);
		for (int j=0;j<COLUMN_SIZE;j++)
			A[i][j] = Points[i][j];
	}

	int *colume_size = (int *) malloc(sizeof(int) * ROW_SIZE);
	for (int i=0;i<ROW_SIZE;i++) 
		colume_size[i] = COLUMN_SIZE;
		
	printMatrix(A, ROW_SIZE, COLUMN_SIZE);

	double result = largestTriangleArea(A, ROW_SIZE, colume_size);
	printf("The largest triangle area is:%f\n", result);
	return 0;
}

/*
You have a list of points in the plane. Return the area of the largest triangle that can be formed by any 3 of the points.

Example:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2
Explanation: 
The five points are show in the figure below. The red triangle is the largest.


Notes:

3 <= points.length <= 50.
No points will be duplicated.
 -50 <= points[i][j] <= 50.
Answers within 10^-6 of the true value will be accepted as correct.
*/
