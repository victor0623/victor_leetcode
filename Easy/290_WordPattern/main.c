#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HT_SIZE 26
#define WORD_LEN 1000
//#define DEBUG

bool checkPatternUnique(char **HashTable, char * word, int * pattern_list, int pattern_num) {
	bool isUnique = true;
	int i, p_index;
	for (i=0;i<pattern_num;i++) {
		p_index = pattern_list[i];
		if (strcmp(HashTable[p_index], word) == 0) {
			isUnique = false;
			break;
		}
	}

	return isUnique;
}

char *getWord(char *str, int offset, int len) {
	//int len = shift+1;
	int i;
	char *word = malloc(sizeof(char) * len);
	for (i=0; i<len; i++) {
		if (i== len-1)
			word[i] = '\0';
		else
			word[i] = str[offset+i];
	}

	return word;
}

int countWord(char *str) {
	int num = 0, i;
	int len = (int) strlen(str);
	for (i=0;i<len;i++) {
		if (str[i] == ' ')
			num++;
	}

	return num+1;
}

bool wordPattern(char* pattern, char* str) {
	bool isMatched = true;
	int i, index, len, shift=0, offset = 0;
	int pattern_num = 0;
	int p_size = strlen(pattern);
#ifdef DEBUG
	printf("p_size=%d\n", p_size);
#endif

	int num_word = countWord(str);
#ifdef DEBUG
	printf("num_word=%d\n", num_word);
#endif

	if (p_size != num_word)
		return false;

	char **HashTable = (char **) malloc(sizeof(char *) * HT_SIZE);
	if (HashTable != NULL) {
		for (i=0;i<HT_SIZE;i++) {
			HashTable[i] = malloc(sizeof(char) * WORD_LEN);
			if (HashTable[i] != NULL) {
				HashTable[i][0] = '\0';
			}
		}
	}

	int *pattern_list = (int *) malloc(sizeof(int) * HT_SIZE);
	if (pattern_list != NULL) {
		for (i=0;i<HT_SIZE;i++) {
			pattern_list[i] = -1;
		}
	}

	for (i=0;i<p_size;i++) {
		index = (int) (pattern[i] - 97);
#ifdef DEBUG
		printf("index=%d\n", index);
#endif

		if (i == p_size-1) {
			len = ((int) strlen(str)) - offset + 1;
		}
		else {
			char *pch = strchr(str+offset,' ');
			shift = (int) (pch-str+1);
			len = shift - offset;
		}
#ifdef DEBUG
		printf("offset=%d len=%d\n", offset, len);
#endif
			
		char *word = getWord(str, offset, len);
#ifdef DEBUG
		printf("word:%s\n", word);
#endif

		if (HashTable[index][0] == '\0') {
#ifdef DEBUG
			printf("HashTable[%d] is empty!Add %s to hash table\n", index, word);
#endif
			bool isUnique = checkPatternUnique(HashTable, word, pattern_list, pattern_num);
			if (isUnique == true) {
				strcpy(HashTable[index], word);
				pattern_list[pattern_num] = index;
				pattern_num++;
			}
			else {
#ifdef DEBUG
				printf("Word %s is not uniqle!\n", word);
#endif
				isMatched = false;
				break;
			}
		}
		else {
#ifdef DEBUG
			printf("HashTable[%d] is not empty!\n", index);
#endif
			if (strcmp(HashTable[index], word) == 0) {
#ifdef DEBUG
				printf("HashTable[%d]:%s is matched to word:%s!\n", index, HashTable[index], word);
#endif
			}
			else {
#ifdef DEBUG
				printf("HashTable[%d]:%s\tword:%s not matched!\n", index, HashTable[index], word);
#endif
				isMatched = false;
				break;
			}
		}

		offset = shift;
	}

	if (pattern_list != NULL)
		free(pattern_list);

	for (i=0;i<HT_SIZE;i++) {
		if (HashTable[i] != NULL) {
			free(HashTable[i]);
		}
	}

	if (HashTable != NULL)
		free(HashTable);

	return isMatched;
}

int main(void)
{
	char pattern[] = "adda";
	char str[] = "dog cat cat dog";

	printf("pattern:%s\n", pattern);
	printf("str:%s\n", str);

	bool result = wordPattern(pattern, str);
	if (result)
		printf("Yes!\n");
	else
		printf("No!\n");

	return 0;
}

/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/
