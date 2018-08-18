#include <stdio.h>
#include <stdlib.h>

#define DEBUG

int calculateCount(int value)
{
	int count;
	if (value < 10)
		count = 1;
	else if (value >= 10 && value < 100)
		count = 2;
	else if (value >= 100 && value < 1000)
		count = 3;
	else if (value >= 1000 && value < 10000)
		count = 4;
	else if (value >= 10000 && value < 100000)
		count = 5;
	else
		count = 0;

	return count;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
	int i, j, count, pass, temp_total_count;
	int max_num = right - left + 1;
	int * temp_list = (int *) malloc(sizeof(int) * max_num);
	for (i=0;i<max_num;i++)
		*(temp_list+i) = -1;

#ifdef DEBUG
	for (i=0;i<max_num;i++)
		printf("temp_list[%d]:%d\n", i, *(temp_list+i));

	printf("left:%d\tright:%d\n", left, right);
#endif

	*returnSize = 0;
	temp_total_count = 0;

	for (i=left;i<=right;i++) {
		count = calculateCount(i);
		pass = 0;
		while (count > 0) {
			int DividingNumber;
			switch (count) {
				case 1:
					DividingNumber = i / 1 % 10;
					break;
				case 2:
					DividingNumber = i / 10 % 10;
					break;
				case 3:
					DividingNumber = i / 100 % 10;
					break;
				case 4:
					DividingNumber = i / 1000 % 10;
					break;
				case 5:
					DividingNumber = i / 10000 % 10;
					break;
				default:
					break;
			}
			if (DividingNumber == 0) {
				pass = 0;
				break;
			}
			else {
				if ((i % DividingNumber) == 0)
					pass = 1;
				else {
					pass = 0;
					break;
				}
			}
			count--;
		}
		if (pass == 1) {
			*(temp_list + temp_total_count) = i;
			temp_total_count++;
		}

	}

	int *returnedArray = (int *) malloc(sizeof(int) * temp_total_count);
	*returnSize = temp_total_count;

#ifdef DEBUG
	printf("The temp_total_count is:%d\n", temp_total_count);
#endif
	for (i=0;i<temp_total_count;i++) {
#ifdef DEBUG
		printf("temp_list[%d]:%d\n", i, *(temp_list+i));
#endif
		*(returnedArray+i) = *(temp_list+i);
	}

	free(temp_list);

    return returnedArray;
}

int main(void)
{
	int returnSize;
	int left = 1, right = 22;
	int * result = selfDividingNumbers(left, right, &returnSize);

#ifdef DEBUG
	printf("The returned array is:\n");
	for (int i=0;i<returnSize;i++) {
		printf("%d ", *(result + i));
	}
	printf("\n");
#endif

	return 0;
}