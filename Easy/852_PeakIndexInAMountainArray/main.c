#include <stdio.h>
#include <stdlib.h>

int peakIndexInMountainArray(int* A, int ASize) {
	int i;

	for (i=1;i<ASize;i++)
		if (A[i-1] < A[i] && A[i] > A[i+1])
			break;

    return i;
}

int main(void)
{
	int Input[] = {0,2,1,0};
	int Input_size = sizeof(Input)/sizeof(int);

	printf("The input array is:\n");
	for (int i=0;i<Input_size;i++)
		printf("%d ", Input[i]);
	printf("\n");

	int peak_index = peakIndexInMountainArray(Input, Input_size);
	printf("The peak index is:%d\n", peak_index);

	return 0;
}