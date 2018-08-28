#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

void printArray(int *Array, int size)
{
	printf("Array of size %d is:\n", size);
	for (int i=0;i<size;i++)
		printf("%d ", Array[i]);
	printf("\n");
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
	int i, j, temp1, temp2;
	int *result = (int *) malloc(sizeof(int) * (rowIndex+1));
	if (result != NULL) {
		for (i=0;i<(rowIndex+1);i++) {
			for (j=0;j<(i+1);j++) {
				if (j == 0) {
					result[j] = 1;
					temp2 = 1;
				} else if(j == i) {
					result[j] = 1;
					result[j-1] = temp2;
				}
				else {
					temp1 = result[j-1] + result[j];
					result[j-1] = temp2;
					temp2 = temp1;
				}
			}
#ifdef DEBUG
			printArray(result, i+1);
#endif
		}
	}

	*returnSize = rowIndex + 1;
    return result;
}

int main(void)
{
	int rowIndex = 3;
	printf("The rowIndex is: %d\n", rowIndex);

	int returnSize;
	int *result = getRow(rowIndex, &returnSize);

	printf("The result with returnSize %d is:\n", returnSize);
	printArray(result, returnSize);

	return 0;
}

/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/