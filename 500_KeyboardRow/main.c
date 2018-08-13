#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100
//#define DEBUG

int mapping[26] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};

int map_index(char c)
{
	int index;
	if (c >= 97 && c <= 122)
		index = (int) c - 97;
	else
		index = (int) c - 65;
	
	return index;
}

/*A-Z: 65-90, a-z:97-122*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
	int fCount = 0, i, j, temp_word_len;
	int isPass = 1, pre, curr;
	char **temp_words = (char **) malloc(sizeof(char *) * wordsSize);
	for (i=0;i<wordsSize;i++)
		*(temp_words+i) = (char *) malloc(sizeof(char) * MAX_STRING_LEN);

	for (i=0;i<wordsSize;i++) {
		char temp_word[MAX_STRING_LEN];
		strcpy(temp_word, *(words+i));
		temp_word_len = (int) strlen(temp_word);
#ifdef DEBUG
		printf("temp_word:%s strlen:%d\n",  temp_word, temp_word_len);
#endif
		isPass = 1;
		for (j=1;j<temp_word_len;j++) {
			pre = map_index(temp_word[j-1]);
			curr = map_index(temp_word[j]);
#ifdef DEBUG
			printf("pre:%d curr:%d\n", pre, curr);
#endif
			if (mapping[pre] != mapping[curr]) {
				isPass *= 0;
				break;
			}
		}

		if (isPass == 1) {
#ifdef DEBUG
			printf("the same row!");
#endif
			strcpy(*(temp_words+fCount), temp_word);
			fCount++;
		}

	}

#ifdef DEBUG
	printf("Found words are:\n");
	for (i=0;i<fCount;i++)
		printf("%s\n", *(temp_words+i));
#endif

	char **result = (char **) malloc(sizeof(char *) * fCount);
	for (i=0;i<fCount;i++) {
		*(result+i) = (char *) malloc(sizeof(char) * MAX_STRING_LEN);
		strcpy(*(result+i), *(temp_words+i));
	}

#ifdef DEBUG
	printf("Found words are:\n");
	for (i=0;i<fCount;i++)
		printf("%s\n", *(result+i));
#endif

	free(temp_words);
	*returnSize = fCount;

	return result;
}

int main(void)
{
	char *Input[MAX_STRING_LEN] = {"Hello", "Alaska", "Dad", "Peace"};
	int wordsSize = 4;

	printf("Input:\n");
	for (int i=0;i<wordsSize;i++)
		printf("%s\n", *(Input+i));
	
	int returnSize;
	char **Output = findWords(Input, wordsSize, &returnSize);

	printf("Output: returnSize:%d\n", returnSize);
	for (int i=0;i<returnSize;i++)
		printf("%s\n", *(Output+i));
	
	return 0;
}

/*
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/
