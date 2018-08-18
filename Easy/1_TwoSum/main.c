#include <stdio.h>
#include <stdlib.h>

#define DEBUG

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	int i, j;
    int * index_array = (int *) malloc(sizeof(int) * 2);
    int total_possible_num = (numsSize)*(numsSize-1)/2;
    int isFound = 0;
#ifdef DEBUG
    printf("The total_possible_num is:%d\n", total_possible_num);
    printf("numSize:%d\ttarget=%d\n", numsSize, target);
#endif

    //Initialization
    if (index_array == NULL) {
    	return NULL;
    } 
    else {
    	*index_array = 0;
    	*(index_array+1) = 0;
    }

    for (i=0;i<numsSize;i++) {
    	for(j=i+1;j<numsSize;j++) {
    		if ((nums[i] + nums[j]) == target) {
    			*index_array = i;
    			*(index_array+1) = j;
    			break;
    		}
    	}
    }

    return index_array;
}

int main(void)
{
	int i;
	int Input[] = {2, 7, 11, 15};
	int target = 9;
	
	//int Input[] = {230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789,542};
	//int target = 542;

	//int Input[] = {-10,-1,-18,-19};
	//int target = -19;
	int InputLength = sizeof(Input)/sizeof(int);
#ifdef DEBUG
	printf("Input:\n");
	for (i=0;i<InputLength;i++)
		printf("%d ", Input[i]);
	printf("\n");
#endif
	//printf("Input[28]:%d Input[45]:%d\n", Input[28], Input[45]);

	int * returned_index = twoSum(Input, InputLength, target);

#ifdef DEBUG
	printf("The return indices are: %d and %d\n", returned_index[0], returned_index[1]);
#endif

	return 0;
}