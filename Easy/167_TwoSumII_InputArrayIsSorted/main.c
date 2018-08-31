#include <stdio.h>
#include <stdlib.h>

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
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	int i, j, temp_sum;

	i = 0;
	j = numbersSize-1;
	while (1) {
		temp_sum = numbers[i] + numbers[j];

		if (temp_sum == target)
			break;

		if (temp_sum < target)
			i++;
		else
			j--;
	}

	*returnSize = 2;
	int * result = (int *) malloc(sizeof(int) * 2);
	if (result != NULL) {
		result[0] = i+1;
		result[1] = j+1;	
	}

	return result;    
}

int main(void)
{
	int Input [] = {2,7,11,15};
	int Input_size = sizeof(Input)/sizeof(int);
	int target = 9;
	int returnSize;

	printf("Input array:\n");
	printArray(Input, Input_size);

	int * result = twoSum(Input, Input_size, target, &returnSize);
	printf("The result with target %d is: %d and %d\n", target, result[0], result[1]);

	return 0;
}

/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
*/