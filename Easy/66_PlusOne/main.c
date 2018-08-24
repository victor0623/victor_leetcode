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

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int *temp = (int *) malloc(sizeof(int) * digitsSize);

	int i, isExtend = 0, bonus = 0, sum, final_size;

	for (i=0;i<digitsSize;i++)
		temp[i] = digits[i];

	for (i=digitsSize-1;i>=0;i--) {
#ifdef DEBUG
		printf("temp[%d]:%d bonus:%d\n", i, temp[i], bonus);
#endif
		if (i == (digitsSize-1))
			sum = temp[i] + bonus + 1;
		else
			sum = temp[i] + bonus;

		if (sum == 10) {
			bonus = 1;
			temp[i] = 0;
		}
		else {
			bonus = 0;
			temp[i] = sum;
		}
	}

#ifdef DEBUG
	printArray(temp, digitsSize);
#endif

	if (bonus == 1)
		final_size = digitsSize + 1;
	else
		final_size = digitsSize;

#ifdef DEBUG
	printf("final_size:%d\n", final_size);
#endif

	int *result = (int *) malloc(sizeof(int) * final_size);
	if (result != NULL) {
		if (bonus == 1) {
			for (i=0;i<final_size;i++) {
				if (i == 0)
					result[i] = 1;
				else
					result[i] = temp[i-1];
			}
		}
		else {
			for (i=0;i<final_size;i++)
				result[i] = temp[i];
		}
	}

	free(temp);

	*returnSize = final_size;

	return result;
}

int main(void)
{
	int Input[] = {4,3,2,1};
	int Input_size = sizeof(Input)/sizeof(int);
	int returnSize;

	printf("Input is:\n");
	printArray(Input, Input_size);

	int *result = plusOne(Input, Input_size, &returnSize);
	printf("Output is:\n");
	printArray(result, returnSize);
	
	return 0;
}

/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/