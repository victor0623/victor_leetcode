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

int removeDuplicates(int* nums, int numsSize) {
	int i, j, temp;
	int len = 0, curr_max;
	if (numsSize != 0) {
		len = 1;
		curr_max = nums[0];
	}

	for (i=1;i<numsSize;i++) {
#ifdef DEBUG
		printf("round:%d\n", i);
		printArray(nums, numsSize);
#endif

		for (j=i;j<numsSize;j++) {
			if (nums[j] > nums[i-1] && nums[j] > curr_max) {
				temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
				curr_max = nums[i];
				len++;

#ifdef DEBUG
				printf("nums[%d]:%d curr_max:%d len:%d\n", i, nums[i], curr_max, len);
#endif
				break;
			}
		}
	}

    return len;
}

int main(void)
{
	int Input[] = {1,1,2};
	int Input_size = sizeof(Input)/sizeof(int);

	printf("Input array:\n");
	printArray(Input, Input_size);

	int result = removeDuplicates(Input, Input_size);
	printf("The result is:%d\n", result);

	return 0;
}

/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/