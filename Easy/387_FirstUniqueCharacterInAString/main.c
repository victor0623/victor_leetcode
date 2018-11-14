#include <stdio.h>
#include <string.h>

#define HT_SIZE 26
//#define DEBUG

int firstUniqChar(char* s) {
	int record[HT_SIZE];
	int i, str_len, index;

	for (i=0;i<HT_SIZE;i++)
		record[i] = 0;

	str_len = (int) strlen(s);
	for (i=0;i<str_len;i++) {
		index = (int) (s[i] - 97);

		record[index] = record[index] + 1;
	}

	for (i=0;i<str_len;i++) {
		index = (int) (s[i] - 97);
		if (record[index] == 1)
			return i;
	}

    return -1;
}

int main(void)
{
	char s[] = "loveleetcode";

	printf("s:%s\n", s);

	int result = firstUniqChar(s);
	printf("result = %d\n", result);

	return 0;
}

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/