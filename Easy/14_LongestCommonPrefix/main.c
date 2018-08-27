#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 1000
//#define DEBUG

char* longestCommonPrefix(char** strs, int strsSize) {
	int min_len = 0, temp_len, min_index, i, j;
	for (i=0;i<strsSize;i++) {
		temp_len = (int) strlen(*(strs+i));
#ifdef DEBUG
		printf("strs[%d]:%s len:%d\n", i, *(strs+i), temp_len);
#endif
		if (i == 0) {
			min_len = temp_len;
			min_index = i;
		}
		else {
			if (temp_len <= min_len) {
				min_len = temp_len;
				min_index = i;
			}
		}
	}

#ifdef DEBUG
	printf("min_len=%d min_index=%d\n", min_len, min_index);
#endif

	char temp_c;
	char *prefix = (char *) malloc(sizeof(char) * (min_len+1));
	int noMatched = 0;
	if (prefix != NULL) {
		memset(prefix, '\0', min_len+1);
		for (i=0;i<min_len;i++) {
			if (noMatched != 1) {
				temp_c = strs[min_index][i];
#ifdef DEBUG
				printf("%c\n", temp_c);
#endif

				for (j=0;j<strsSize;j++) {
					if (j != min_index) {
#ifdef DEBUG
						printf("strs[%d][%d]=%c \n", j, i, strs[j][i]);
#endif
						if (strs[j][i] != temp_c) {
							noMatched = 1;
							break;
						}
					}
				}
				if (noMatched != 1)
					prefix[i] = temp_c;
			}
		}
	}

    return prefix;
}

int main(void)
{
	char *Input[STRING_LEN] = {"flower","flow","flight"};
	int strsSize = 3;
	for (int i=0;i<strsSize;i++)
		printf("Input[%d]:%s\n", i, *(Input+i));

	char *result = longestCommonPrefix(Input, strsSize);
	printf("The result is:%s\n", result);

	return 0;
}

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/