#include <stdio.h>
#include <stdlib.h>

#define DEBUG

int * selectionSort(int * nums_list, int total_num)
{
	int * sorted_list = (int *) malloc(sizeof(int) * total_num);

	if (sorted_list == NULL)
		return NULL;
	
	for (int i=0;i<total_num;i++)
		*(sorted_list+i) = *(nums_list+i);

	int min_num, index, temp;
	for (int i=0;i<total_num;i++) {
		min_num = *(sorted_list+i);
		index = i;
		for (int j=i+1;j<total_num;j++) {
			if (min_num >= *(sorted_list+j)) {
				min_num = *(sorted_list+j);
				index = j;
			}
		}
		temp = *(sorted_list+i);
		*(sorted_list+i) = *(sorted_list+index);
		*(sorted_list+index) = temp;
	}

#ifdef DEBUG
	printf("The sort result of input is:\n");
	for (int i=0;i<total_num;i++) {
		printf("%d ", *(sorted_list+i));
	}
	printf("\n");
#endif

	return sorted_list;
}

int arrayPairSum(int* nums, int numsSize) {
	int * sorted_num_list = selectionSort(nums, numsSize);
	if (sorted_num_list == NULL)
		return 0;

	int max_sum = 0;
	for (int i=0;i<numsSize;i+=2) {
		max_sum += *(sorted_num_list+i);
	}

	free(sorted_num_list);
	return max_sum;    
}

int main(void)
{
	int Input[] = {1,4,3,2};
	int numsSize = sizeof(Input) / sizeof(int);//sizeof(Input) / sizeof(int) / 2;

#ifdef DEBUG
	printf("The numSize is:%d\n", numsSize);
	printf("The Input is:\n");
	for (int i=0;i<numsSize;i++)
		printf("%d ", Input[i]);
	printf("\n");
#endif

	int max_sum = arrayPairSum(Input, numsSize);
#ifdef DEBUG
	printf("The maximum of sums is:%d\n", max_sum);
#endif

	return 0;
}

/*
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
*/