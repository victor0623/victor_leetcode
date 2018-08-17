#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

void printArray(int *Array, int size)
{
	int i;
	for (i=0;i<size;i++)
		printf("%d ", Array[i]);
	printf("\n");
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
	int i, j;
	int *result = (int *) malloc(sizeof(int) * numsSize);
	*returnSize = 0;
	
	memset(result, 0, sizeof(int) * numsSize);
#ifdef DEBUG
	printArray(result, numsSize);
#endif

	for (i=0;i<numsSize;i++) {
		result[nums[i]-1]++;
		if (result[nums[i]-1] > 1)
			(*returnSize)++;
	}

#ifdef DEBUG
	printArray(result, numsSize);
#endif

	int *final_list = (int *) malloc(sizeof(int) * (*returnSize));
	for (i=0, j=0;i<numsSize;i++) {
		if (result[i] > 1) {
			final_list[j] = i+1;
			j++;
		}
	}

#ifdef DEBUG
	printArray(final_list, *returnSize);
#endif

	free(result);
	

    return final_list;
}

int main(void)
{
	int Input[] = {4,3,2,7,8,2,3,1};
	int InputSize = sizeof(Input)/sizeof(int);

	printf("The input is:\n");
	printArray(Input, InputSize);
	
	int returnSize;
	int *result = findDuplicates(Input, InputSize, &returnSize);

	printf("The duplicated numbers are:\n");
	printArray(result, returnSize);


	return 0;
}

/*
Given an array of integers, 1 < a[i] < n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/