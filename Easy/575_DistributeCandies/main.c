#include <stdio.h>
#include <stdlib.h>

//#define DEBUG
#define DEFAULT_VALUE -999999

void printArray(int *Array, int ArraySize)
{
	int i;
	for (i=0;i<ArraySize;i++)
		printf("%d ", Array[i]);
	printf("\n");
}

int isFound(int *candy_kind, int candy_kind_max_size, int candy)
{
	int isFound = 0, i;
	for (i=0;i<candy_kind_max_size;i++) {
		if (candy_kind[i] == DEFAULT_VALUE)
			break;

		if (candy_kind[i] == candy) {
			isFound = 1;
			break;
		}
	}

	return isFound;
}

int distributeCandies(int* candies, int candiesSize) {
	int kind_num = 0, i, Found, max_kind_num = 0;
	int *candy_kind = (int *) malloc(sizeof(int) * candiesSize);

	for (i=0;i<candiesSize;i++)
		candy_kind[i] = DEFAULT_VALUE;
#ifdef DEBUG
	printf("Default candy kind array...\n");
	printArray(candy_kind, candiesSize);
#endif
	
	if (candy_kind != NULL) {
		for (i=0;i<candiesSize;i++) {
			if (i== 0) {
				candy_kind[i] = candies[i];
				kind_num++;
			}
			else {
				Found = isFound(candy_kind, candiesSize, candies[i]);
				if(Found == 0) {
					candy_kind[kind_num] = candies[i];
					kind_num++;
				}
			}
		}
	}

#ifdef DEBUG
	printf("kind num=%d\n", kind_num);
	printf("Final candy kind array...\n");
	printArray(candy_kind, candiesSize);
#endif

	if (kind_num >= candiesSize/2)
		max_kind_num = candiesSize/2;
	else
		max_kind_num = kind_num;
	
	return max_kind_num;
}

int main(void)
{
	//int Input[] = {1,1,2,2,3,3};
	int Input[] = {1,1,2,3};
	int InputSize = sizeof(Input)/sizeof(int);

	printf("Input array is:\n");
	printArray(Input, InputSize);

	int result = distributeCandies(Input, InputSize);
	printf("The max number of candy kind sister can hold is:%d\n", result);
	return 0;
}

/*
Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Return the maximum number of kinds of candies the sister could gain.
Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 
Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
Note:

The length of the given array is in range [2, 10,000], and will be even.
The number in given array is in range [-100,000, 100,000].
*/