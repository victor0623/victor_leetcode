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

void rotate(int* nums, int numsSize, int k) {
	int steps = k % numsSize;
	int *temp_nums;
	
	if (steps == 0) {
		return;
	} else {
		temp_nums = (int *) malloc(sizeof(int) * numsSize);
		if (temp_nums)
			memcpy(temp_nums, nums, sizeof(int) * numsSize);

		memcpy(nums+steps, temp_nums, (numsSize-steps) * sizeof(int));
		memcpy(nums, temp_nums+(numsSize-steps), steps * sizeof(int));

		if (temp_nums)
			free(temp_nums);
	}
}

void rotate2(int* nums, int numsSize, int k) {
	int steps = k % numsSize;
	
	
	if (steps == 0) {
		return;
	} else {
	}
		
}

int main(void)
{
	int Input [] = {1,2,3,4,5,6,7};
	int Input_size = sizeof(Input)/sizeof(int);
	int k = 3;

	printf("Input array:\n");
	printArray(Input, Input_size);

	rotate(Input, Input_size, k);
	
	printf("The rotated result is:\n");
	printArray(Input, Input_size);

	return 0;
}

/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/