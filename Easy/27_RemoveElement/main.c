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

int removeElement(int* nums, int numsSize, int val) {
	int temp, i, j, isFound, new_len = 0;

	for (i=0;i<numsSize;i++) {
#ifdef DEBUG
		printf("round %d:\n", i);
		printArray(nums, numsSize);
		printf("I am  %d at %d\n", nums[i], i);
#endif
		if (nums[i] == val) {
			isFound = 0;
			for (j=i+1;j<numsSize;j++) {
#ifdef DEBUG
				printf("candidate:%d\n", nums[j]);
#endif
				if (nums[j] != val) {
#ifdef DEBUG
					printf("found %d at %d!\n",nums[j], j);
#endif
					temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
					new_len++;
					isFound = 1;
					break;
				}
			}

			if (isFound == 0)
				break;
		}
		else
			new_len++;
	}

	return new_len;
}

int main(void)
{
	int Input[] = {3,2,2,3};
	int Input_size = sizeof(Input)/sizeof(int);
	int val = 3;

	printf("The input is:\n");
	printArray(Input, Input_size);

	int result = removeElement(Input, Input_size, val);
	printf("The result val %d is: %d\n", val, result);
	printArray(Input, result);
	
	return 0;
}

/*
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

Note that the order of those five elements can be arbitrary.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
