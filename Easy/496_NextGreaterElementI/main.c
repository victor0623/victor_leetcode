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

int findPosition(int *num, int size, int item)
{
	int i, pos = 0;
	for (i=0;i<size;i++) {
		if(num[i] == item)
			pos = i;
	}

	return pos;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
	int i, j, pos, offset, isFound;
	*returnSize = findNumsSize;
	int *result = (int *) malloc(sizeof(int) * findNumsSize);
	if (result != NULL) {
		for (i=0;i<findNumsSize;i++) {
			pos = findPosition(nums, numsSize, findNums[i]);
#ifdef DEBUG
			printf("pos:%d\n", pos);
#endif

			offset = pos;
			isFound = 0;
			for (j=pos+1;j<numsSize;j++) {
				if (nums[j] > findNums[i]) {
					result[i] = nums[j];
					isFound = 1;
					break;
				}
			}

			if (isFound == 0)
				result[i] = -1;
		}
	}

    return result;
}

int main(void)
{
	//int num1[] = {4,1,2};
	//int num2[] = {1,3,4,2};

	int num1[] = {2,4};
	int num2[] = {1,2,3,4};

	int num1_len = sizeof(num1)/sizeof(int);
	int num2_len = sizeof(num2)/sizeof(int);

	printf("num1 is:\n");
	printArray(num1, num1_len);
	printf("num2 is:\n");
	printArray(num2, num2_len);

	int returnSize;

	int *result = nextGreaterElement(num1, num1_len, num2, num2_len, &returnSize);
	printf("The result is:\n");
	printArray(result, returnSize);

	return 0;
}

/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
*/