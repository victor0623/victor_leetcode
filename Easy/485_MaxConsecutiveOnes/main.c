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

int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int max = 0, local_max = 0, i;
	for (i=0;i<numsSize;i++) {
#ifdef DEBUG
		printf("num[%d]:%d\n", i, nums[i]);
#endif

		if (nums[i] == 0 || i == (numsSize-1)) {
			if (nums[i] == 1)
				local_max++;

#ifdef DEBUG
			printf("local_max=%d\n", local_max);
#endif
			if (local_max >= max)
				max = local_max;
			local_max = 0;

			continue;
		}

		if (nums[i] == 1) {
			local_max++;
		}	
	}

    return max;
}

int main(void)
{
	int Input[] = {0,0,0,1,1,1,0};
	int Input_len = sizeof(Input)/sizeof(int);

	printf("The Input array is:\n");
	printArray(Input, Input_len);

	int result = findMaxConsecutiveOnes(Input, Input_len);
	printf("The result is:%d\n", result);

	return 0;
}

/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/