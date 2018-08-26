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

void merge(int* nums1, int m, int* nums2, int n) {
	int *result = (int *) malloc(sizeof(int) * (m+n));

	int i, n1_index = 0, n2_index = 0;
	int n1, n2, n1_empty = 0, n2_empty = 0;
	for (i=0;i<(m+n);i++) {
		if (n1_index < m) {
			n1 = nums1[n1_index];
			n1_empty = 0;
		}
		else {
			n1_empty = 1;
		}

		if (n2_index < n) {
			n2 = nums2[n2_index];
			n2_empty = 0;
		}
		else {
			n2_empty = 1;
		}

		if (n1_empty == 0 && n2_empty == 0) {
			if (n1 <= n2) {
				result[i] = n1;
				n1_index++;
			}
			else {
				result[i] = n2;
				n2_index++;
			}
		}
		else if (n1_empty == 0 && n2_empty == 1) {
			result[i] = n1;
			n1_index++;
		}
		else if (n1_empty == 1 && n2_empty == 0) {
			result[i] = n2;
			n2_index++;
		}
	}

#ifdef DEBUG
	printf("result:\n");
	printArray(result, m+n);
#endif

	for (i=0;i<(m+n);i++)
		nums1[i] = result[i];

	free(result);

#ifdef DEBUG
	printf("new nums1:\n");
	printArray(nums1, m+n);
#endif
}

int main(void)
{
	int nums1[] = {1,2,3};
	int nums2[] = {2,5,6};

	int nums1_len = sizeof(nums1)/sizeof(int);
	int nums2_len = sizeof(nums2)/sizeof(int);

	int *N1 = (int *) malloc(sizeof(int) * (nums1_len+nums2_len));

	for (int i=0;i<(nums1_len+nums1_len);i++) {
		if (i < nums1_len)
			N1[i] = nums1[i];
		else
			N1[i] = 0;
	}

	//printArray(N1, nums1_len+nums1_len);


	printf("nums1 and nums2 are:\n");
	printArray(nums1, nums1_len);
	printArray(nums2, nums2_len);

	merge(N1, nums2_len, nums2, nums2_len);
	printf("result:\n");
	printArray(N1, nums1_len+nums2_len);

	return 0;
}

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/