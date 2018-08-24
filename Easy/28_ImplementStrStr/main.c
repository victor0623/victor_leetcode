#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

int strStr(char* haystack, char* needle) {
	int haystack_len = strlen(haystack);
	int needle_len = strlen(needle);
#ifdef DEBUG
	printf("haystack_len:%d needle_len:%d\n", haystack_len, needle_len);
#endif

	if (needle_len == 0)
		return 0;

	int position = -1, i, rest_num, cmp_result;

	for (i=0;i<haystack_len;i++) {
#ifdef DEBUG
		printf("start char:%c\n", haystack[i]);
#endif
		rest_num = haystack_len - i;
		if (rest_num < needle_len)
			return -1;

#ifdef DEBUG
		printf("haystack+i:%s\n", haystack+i);
#endif
		cmp_result = strncmp(haystack+i, needle, needle_len);
		if (!cmp_result) {
#ifdef DEBUG
			printf("%s is found!\n", needle);
#endif
			position = i;
			break;
		}
		else {
#ifdef DEBUG
			printf("%s is not found!\n", needle);
#endif
		}
	}
	
	return position;
}

int main(void)
{
	char haystack[] = "hello";
	char needle[] = "lo";

	printf("haystack:%s\n", haystack);
	printf("needle:%s\n", needle);

	int result = strStr(haystack, needle);
	printf("The result is:%d\n", result);
	
	return 0;
}

/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/