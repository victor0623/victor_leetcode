#include <stdio.h>
#include <stdlib.h>

void printArray(int *Array, int size)
{
	printf("Array of size %d is:\n", size);
	for (int i=0;i<size;i++)
		printf("%d ", Array[i]);
	printf("\n");
}

void moveZeroes(int* nums, int numsSize) {
    int zero_index = -1, temp, i=0, j, isStop, last_nonzero_index = -1, start;

    while (1) {
    	if (nums[i] == 0) {
    		zero_index = i;

    		if (last_nonzero_index == -1)
    			start = i+1;
    		else
    			start = last_nonzero_index+1;

    		isStop = 1;
	    	for (j=start;j<numsSize;j++) {
	    		if (nums[j] != 0) {
	    			temp = nums[j];
	    			nums[j] = nums[zero_index];
	    			nums[zero_index] = temp;
	    			last_nonzero_index = j;
	    			isStop = 0;
	    			break;
	    		}
	    	}
    	}

    	if (isStop)
    		break;

    	i++;
    }
}

int main(void)
{
	int Input[] = {0,1,0,3,12};
	int InputSize = sizeof(Input)/sizeof(int);

	printf("The input array is:\n");
	printArray(Input, InputSize);

	moveZeroes(Input, InputSize);
	printf("The result is:\n");
	printArray(Input, InputSize);

	return 0;
}

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/