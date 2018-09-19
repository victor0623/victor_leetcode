#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum monotonic_status {
	MONOTONIC_EQUAL = 0,
	MONOTONIC_INCREASING = 1,
	MONOTONIC_DECREASING = 2,
};

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
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
	*returnSize = ASize;
	if (A == NULL || ASize <= 1)
		return A;

	int i, j, isFoundEven, last_even_index = -1, temp, start;
	int *result = (int *) malloc(sizeof(int) * ASize);
	if (result != NULL) {
		for (i=0;i<ASize;i++)
			result[i] = A[i];

		i = 0;
		while (1) {
			if (result[i] % 2 == 1) {
				if (last_even_index == -1)
					start = i + 1;
				else
					start = last_even_index + 1;

				isFoundEven = 0;
				for (j=start;j<ASize;j++) {
					if (result[j] % 2 == 0) {
						temp = result[j];
						result[j] = result[i];
						result[i] = temp;
						isFoundEven = 1;
						last_even_index = j;
						break;
					}
				}
				if (isFoundEven == 0)
					break;
			}

			i++;
		}
	}

    return result;
}

int main(void)
{
	int Input[] = {3,1,2,4};
	int InputSize = sizeof(Input)/sizeof(int);

	printf("The input array is:\n");
	printArray(Input, InputSize);

	int returnSize;

	int *result = sortArrayByParity(Input, InputSize, &returnSize);
	printArray(result, returnSize);

	return 0;
}

/*
Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/