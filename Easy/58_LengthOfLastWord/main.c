#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

int lengthOfLastWord(char* s) {
	int last_len = 0;
	while (*s != '\0') {
#ifdef DEBUG
		printf("%c\n", *s);
#endif
		if (*s == ' ') {
			if (*(s+1) == '\0')
				break;
			else {
				if (*(s+1) != ' ')
					last_len = 0;
			}
		}
		else
			last_len++;

		s++;
	}

    return last_len;
}

int main(void)
{
	char Input[] = "Hello World";
	printf("Input:%s\n", Input);
	int result = lengthOfLastWord(Input);

	printf("result is:%d\n", result);
}

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/