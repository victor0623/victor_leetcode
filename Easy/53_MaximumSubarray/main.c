#include <stdio.h>
#include <stdlib.h>

void printArray(int *Array, int size)
{
	printf("Array of size %d is:\n", size);
	for (int i=0;i<size;i++)
		printf("%d ", Array[i]);
	printf("\n");
}


int maxSubArray(int* nums, int numsSize) {
	int i, sum = 0, max_sum = 0;

	if (numsSize == 1)
		return nums[0];

	max_sum = nums[0];
	for (i=0;i<numsSize;i++) {
		if (sum < 0) {
			sum = 0;
		}

		sum += nums[i];
		if (sum >= max_sum)
			max_sum = sum;
		
	}

	return max_sum;
}

int main(void)
{
	int Input[] = {-2,1,-3,4,-1,2,1,-5,4};
	
	int Input_size = sizeof(Input)/sizeof(int);

	printArray(Input, Input_size);
	int result = maxSubArray(Input, Input_size);
	printf("The max sum is:%d\n", result);
	
	return 0;
}

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/