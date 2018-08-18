#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize) {
	int rSize = 2;
	int *returned_array = (int *) malloc(sizeof(int) * rSize);
	
	if (returned_array == NULL)
		return NULL;

	for (int i=0;i<rSize;i++)
		returned_array[i] = 0;

	char *cur_S = S;
	int num_lines = 1;
	int letters_nums = 0;
	while (*cur_S != '\0') {
		char poped_letter = *cur_S;
#ifdef DEBUG
		printf("poped_letter:%c\n", poped_letter);
#endif

		int num_of_letters = widths[poped_letter - 97];
#ifdef DEBUG
		printf("num of letters:%d\n", num_of_letters);
#endif
		if (letters_nums > (100 - num_of_letters)) {
			num_lines++;
			letters_nums = 0;
		}

		letters_nums += num_of_letters;
		cur_S++;
	}

	returned_array[0] = num_lines;
	returned_array[1] = letters_nums;

	*returnSize = rSize;
    return returned_array;
}

int main(void)
{
	int widths[26] = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
	char *S= "abcdefghijklmnopqrstuvwxyz";

	//int widths[26] = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
	//char *S= "bbbcccdddaaa";

	int widthsSize = sizeof(widths)/sizeof(int);

	printf("widthsSize:%d\n", widthsSize);
	printf("widths array:\n");
	for (int i=0;i<widthsSize;i++)
		printf("%d ", widths[i]);
	printf("\n");
	printf("S:%s\n", S);

	int returnSize = 0;
	int * returned_array = numberOfLines(widths, widthsSize, S, &returnSize);
	printf("returnSize:%d\n", returnSize);
	printf("Returned array is:\n");
	for (int i=0;i<returnSize;i++)
		printf("%d\n", returned_array[i]);

	return 0;
}

/*
Example :
Input: 
widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "abcdefghijklmnopqrstuvwxyz"
Output: [3, 60]
Explanation: 
All letters have the same length of 10. To write all 26 letters,
we need two full lines and one line with 60 units.

Example :
Input: 
widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "bbbcccdddaaa"
Output: [2, 4]
Explanation: 
All letters except 'a' have the same length of 10, and 
"bbbcccdddaa" will cover 9 * 10 + 2 * 4 = 98 units.
For the last 'a', it is written on the second line because
there is only 2 units left in the first line.
So the answer is 2 lines, plus 4 units in the second line.

Note:

The length of S will be in the range [1, 1000].
S will only contain lowercase letters.
widths is an array of length 26.
widths[i] will be in the range of [2, 10].

ASCII:
a-z: 97-122
*/