#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DEFAULT_MAX 1000000
//#define DEBUG

int findClosestC(int curr, int length, int * table)
{
	int dist, i = 0, previous, next;
	int *t = table;

	while (*(t+i) != DEFAULT_MAX) {
		dist = abs(curr - *(t+i));

		if (i == 0)
			previous = DEFAULT_MAX;
		else
			previous = abs(curr - *(t+i-1));

		if (i == (length-1))
			next = DEFAULT_MAX;
		else
			next = abs(curr - *(t+i+1));
		
#ifdef DEBUG
		printf("previous:%d dist:%d next:%d\n", previous, dist, next);
#endif
		if (dist <= previous && dist <= next )
			break;

		i++;
	}

#ifdef DEBUG
	printf("dist:%d\n", dist);
#endif

	return dist;
}

void findCinS(char* S, char C, int S_len, int *table)
{
	int matched_index = 0;
	for (int i=0;i<S_len;i++) {
		if (*(S+i) == C) {
			*(table+matched_index) = i;
			matched_index++;
		}
	}
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* S, char C, int* returnSize) {
	int S_len = strlen(S);
#ifdef DEBUG
	printf("S len=%d\n", S_len);
#endif

	int *result = malloc(sizeof(int) * S_len);
	int *index_array = malloc(sizeof(int) * S_len);
	int i;

	for (i=0;i<S_len;i++)
		index_array[i] = DEFAULT_MAX;

	findCinS(S, C, S_len, index_array);	

#ifdef DEBUG
	for (i=0;i<S_len;i++)
		printf("index_array[%d]:%d\n", i, index_array[i]);
#endif

	if(result != NULL) {
		for (i=0;i<S_len;i++) {
#ifdef DEBUG
			printf("current index:%d\n", i);
#endif
			*(result+i) = findClosestC(i, S_len, index_array);
		}
	}

	free(index_array);

	*returnSize = S_len;
    return result;
}

int main(void)
{
	char *S = "loveleetcode";
	char C = 'e';
	int returnSize = 0;
	int *Output = shortestToChar(S, C, &returnSize);
	printf("S=%s C=%c\n", S, C);
	for (int i=0;i<returnSize;i++)
		printf("%d ", *(Output+i));
	printf("\n");

	return 0;
}

/*
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 

Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.
*/