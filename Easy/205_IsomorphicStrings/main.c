#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//#define DEBUG

struct item {
	char c;
	int pos;
};

int isFound(char c, int pos, int p_index, struct item * pattern)
{
	int i, found_pos_in_pattern = -1;
	for (i=0;i<=p_index;i++) {
		if (pattern[i].c == c) {
			found_pos_in_pattern = i;
			pattern[i].pos = pos;
			break;
		}
	}

	return found_pos_in_pattern;
}

void addPattern(char c, int pos, int p_index, struct item * pattern)
{
	pattern[p_index].c = c;
	pattern[p_index].pos = pos;
}

bool isIsomorphic(char* s, char* t) {
	bool is_Isomorphic = true;
	int str_len = strlen(s);
	int i, p_index = -1;

	struct item * s_pattern = malloc(sizeof(struct item) * str_len);
	struct item * t_pattern = malloc(sizeof(struct item) * str_len);

	if (s_pattern != NULL && t_pattern != NULL) {
		for (i=0;i<str_len;i++) {
			s_pattern[i].c = '\0';
			t_pattern[i].c = '\0';

			s_pattern[i].pos = -1;
			t_pattern[i].pos = -1;
		}
	}

	for (i=0;i<str_len;i++) {
		int s_found_index = isFound(s[i], i, p_index, s_pattern);
		int t_found_index = isFound(t[i], i, p_index, t_pattern);

		if (s_found_index != t_found_index) {
			is_Isomorphic = false;
			break;
		}
		
		if (s_found_index == -1) {
			p_index++;
			addPattern(s[i], i, p_index, s_pattern);
			addPattern(t[i], i, p_index, t_pattern);
		}		
	}

#ifdef DEBUG
	for (i=0;i<=p_index;i++) {
		printf("s-> c:%c pos:%d\n", s_pattern[i].c, s_pattern[i].pos);
		printf("t-> c:%c pos:%d\n", t_pattern[i].c, t_pattern[i].pos);
	}
#endif

	if (s_pattern != NULL && t_pattern != NULL) {
		free(s_pattern);
		free(t_pattern);
	}
	
	return is_Isomorphic;
}

int main(void)
{
	char s[] = "paper";
	char t[] = "title";

	printf("s=%s\n", s);
	printf("t=%s\n", t);

	bool result = isIsomorphic(s, t);
	if (result)
		printf("Yes!\n");
	else
		printf("No!\n");
	
	return 0;
}

/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
*/
