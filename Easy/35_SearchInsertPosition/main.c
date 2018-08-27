#include <stdio.h>
#include <stdlib.h>

void printArray(int *Array, int size)
{
	printf("Array of size %d is:\n", size);
	for (int i=0;i<size;i++)
		printf("%d ", Array[i]);
	printf("\n");
}


int searchInsert(int* nums, int numsSize, int target) {
	int i, index;

	if (target < nums[0])
		return 0;

	if (target > nums[numsSize-1])
		return numsSize;

	for (i=0;i<numsSize;i++) {
		if (nums[i] == target) {
			index = i;
			break;
		}

		if (target > nums[i] && target < nums[i+1]) {
			index = i+1;
			break;
		}
	}

	return index;
}

int main(void)
{
	int Input[] = {1,3,5,6};
	int Input_size = sizeof(Input)/sizeof(int);
	int target = 5;

	printf("The input array is:\n");
	printArray(Input, Input_size);

	int result = searchInsert(Input, Input_size, target);
	printf("The result index with target %d is: %d\n", target, result);
	
	return 0;
}

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/
