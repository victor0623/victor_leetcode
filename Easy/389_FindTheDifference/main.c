#include <stdio.h>
#include <string.h>

#define HT_SIZE 26
//#define DEBUG

char findTheDifference(char* s, char* t) {
	int record[HT_SIZE];
	int i, str_len_t, index_s, index_t;
	char unique_c;

	for (i=0;i<HT_SIZE;i++)
		record[i] = 0;

	str_len_t = (int) strlen(t);
	for (i=0;i<str_len_t;i++) {
		if (i < str_len_t-1) {
			index_s = (int) (s[i] - 97);
			record[index_s] = record[index_s] + 1;
		}

		index_t = (int) (t[i] - 97);
		record[index_t] = record[index_t] + 1;
	}

	for (i=0;i<HT_SIZE;i++) {
		if (record[i] % 2 == 1) {
			unique_c = (char) (i + 97);
		}
	}

    return unique_c;
}

int main(void)
{
	char s[] = "abcd";
	char t[] = "abcde";

	printf("s:%s\n", s);
	printf("t:%s\n", t);

	char result = findTheDifference(s, t);
	printf("result = %c\n", result);

	return 0;
}

/*
Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
*/