#include <stdio.h>
#include <stdlib.h>

void printArray(int *Array, int size)
{
	printf("Array of size %d is:\n", size);
	for (int i=0;i<size;i++)
		printf("%d ", Array[i]);
	printf("\n");
}

int singleNumber(int* nums, int numsSize) {
	int single_num = 0;

	for (int i=0;i<numsSize;i++)
		single_num = single_num ^ nums[i];

    return single_num;
}

int main(void)
{
	//int Input[] = {4,1,2,1,2};
	int Input[] = {2,2,1,4,4,5,5};
	int InputSize = sizeof(Input)/sizeof(int);

	printf("The input array is:\n");
	printArray(Input, InputSize);

	int result = singleNumber(Input, InputSize);
	printf("The single number is:%d \n", result);

	return 0;
}

/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/