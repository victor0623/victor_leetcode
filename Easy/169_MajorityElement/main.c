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

int majorityElement(int* nums, int numsSize) {
	int major, i;
	if (numsSize < 2)
		return nums[0];

	major = nums[0];
	int major_count = 1;

	for (i=1;i<numsSize;i++) {
		if (nums[i] == major)
			major_count++;
		else
			major_count--;
			if (major_count == 0) {
				major = nums[i];
				major_count = 1;
			}
	}

#ifdef DEBUG
	printf("major=%d major_count=%d\n", major, major_count);
#endif

    return major;
}

int main(void)
{
	int Input[] = {3,2,3};
	int Input_size = sizeof(Input)/sizeof(int);

	printf("The input array is:\n");
	printArray(Input, Input_size);

	int result = majorityElement(Input, Input_size);
	printf("The majority element is: %d\n", result);

	return 0;
}

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/