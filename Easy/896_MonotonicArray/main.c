#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum monotonic_status {
	MONOTONIC_EQUAL = 0,
	MONOTONIC_INCREASING = 1,
	MONOTONIC_DECREASING = 2,
};

void printArray(int *Array, int size)
{
	printf("Array of size %d is:\n", size);
	for (int i=0;i<size;i++)
		printf("%d ", Array[i]);
	printf("\n");
}

bool isMonotonic(int* A, int ASize) {
	bool result = true;
	int m_status = MONOTONIC_EQUAL;
	for (int i=1;i<ASize;i++) {
		if (m_status == MONOTONIC_INCREASING) {
			if (A[i-1] > A[i]) {
				result = false;
				break;
			}
		}
		else if (m_status == MONOTONIC_DECREASING) {
			if (A[i-1] < A[i]) {
				result = false;
				break;
			}
		}
		else {
			if (A[i-1] < A[i])
				m_status = MONOTONIC_INCREASING;

			if (A[i-1] > A[i])
				m_status = MONOTONIC_DECREASING;
		}
	}

    return result;
}

int main(void)
{
	int Input[] = {1,2,2,3};
	int InputSize = sizeof(Input)/sizeof(int);

	printf("The input array is:\n");
	printArray(Input, InputSize);

	bool result = isMonotonic(Input, InputSize);
	if (result)
		printf("The array is monotonic!\n");
	else
		printf("The array is not monotonic!\n");

	return 0;
}

/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

 

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true
 

Note:

1 <= A.length <= 50000
-100000 <= A[i] <= 100000
*/