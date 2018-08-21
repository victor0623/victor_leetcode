#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize) {
	int sum_A = 0, sum_B = 0;
	int selected_A, selected_B, i, j, isFound = 0;
	for (i=0;i<ASize;i++)
		sum_A += A[i];

	for (i=0;i<BSize;i++)
		sum_B += B[i];

	int diff = abs((sum_A-sum_B));
#ifdef DEBUG
	printf("sum_A=%d sum_B=%d diff=%d\n", sum_A, sum_B, diff);
#endif
	if (sum_A < sum_B) {
		for (i=0;i<ASize;i++) {
			selected_A = A[i];
			for (j=0;j<BSize;j++) {
				if ((selected_A + diff/2) == B[j]) {
					selected_B = B[j];
					isFound = 1;
					break;
				}
			}
			if (isFound)
				break;
		}
	}
	else {
		for (i=0;i<BSize;i++) {
			selected_B = B[i];
			for (j=0;j<ASize;j++) {
				if ((selected_B + diff/2) == A[j]) {
					selected_A = A[j];
					isFound = 1;
					break;
				}
			}
			if (isFound)
				break;
		}
	}

#ifdef DEBUG
	printf("selected_A=%d selected_B=%d\n",selected_A, selected_B);
#endif

	*returnSize = 2;
	int *result = (int *) malloc(sizeof(int) * 2);
	if (result) {
		result[0] = selected_A;
		result[1] = selected_B;
	}

	return result;    
}

int main(void)
{
	int A[] = {1,2,5};
	int B[] = {2,4};

	int len_A = sizeof(A)/sizeof(int);
	int len_B = sizeof(B)/sizeof(int);

	printArray(A, len_A);
	printArray(B, len_B);

	int returnSize;
	int *result = fairCandySwap(A, len_A, B, len_B, &returnSize);
	for (int i=0;i<returnSize;i++)
		printf("result[%d]:%d\n", i, result[i]);

	return 0;
}

/*
Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, they both have the same total amount of candy.  (The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

 

Example 1:

Input: A = [1,1], B = [2,2]
Output: [1,2]
Example 2:

Input: A = [1,2], B = [2,3]
Output: [1,2]
Example 3:

Input: A = [2], B = [1,3]
Output: [2,3]
Example 4:

Input: A = [1,2,5], B = [2,4]
Output: [5,4]
*/