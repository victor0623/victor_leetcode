#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *Array, int size)
{
	printf("Array of size %d is:\n", size);
	for (int i=0;i<size;i++)
		printf("%d ", Array[i]);
	printf("\n");
}

int missingNumber(int* nums, int numsSize) {
	int n = numsSize + 1;
	int i, missedNum = -1;
	int * check_array = malloc(sizeof(int) * n);
	if (check_array == NULL) {
		printf("Fail to memory allocation!\n");
	}
	else {
		for (i=0;i<n;i++) {
			check_array[i] = 0;
		}

		for (i=0;i<numsSize;i++) {
			check_array[nums[i]] = 1;
		}

		for (i=0;i<n;i++) {
			if (check_array[i] == 0) {
				missedNum = i;
				break;
			}
		}
	}

	if (check_array != NULL)
		free(check_array);

	return missedNum;
}

int main(void)
{
	int Input [] = {3,0,1};
	int Input_size = sizeof(Input)/sizeof(int);

	printf("Input array:\n");
	printArray(Input, Input_size);

	int missedNum = missingNumber(Input, Input_size);
	
	printf("The missed number is: %d\n", missedNum);

	return 0;
}

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1:

Input: [3,0,1]
Output: 2
Example 2:

Input: [9,6,4,2,3,5,7,0,1]
Output: 8
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/