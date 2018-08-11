#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

char* reverseWords(char* s) {
	char *result = malloc(strlen(s)+1);
	char *p_s = s;
	if (p_s == NULL) {
		free(result);
		return NULL;
	}

	int offset = 0, token_len = 0, i;
	while (*p_s != '\0') {
		

		if(*p_s == ' ') {
#ifdef DEBUG
			printf("offset=%d token_len=%d\n", offset, token_len);
#endif

			for (i=0;i<token_len;i++)
				*(result+offset+i) = *(s+offset+token_len-i-1);
			*(result+offset+i) = ' ';
//Line 25: store to address 0x0000011912a8 with insufficient space for an object of type 'char'

			offset += token_len+1;
			token_len = 0;
		}
		else {
			token_len++;
		}
		p_s++;
	}
#ifdef DEBUG
	printf("offset=%d token_len=%d\n", offset, token_len);
#endif
	for (i=0;i<token_len;i++)
		*(result+offset+i) = *(s+offset+token_len-i-1);
	*(result+offset+i) = '\0';

    return result;
}

int main(void)
{
	char Input[] = "Let's take LeetCode contest";
	char *Output = reverseWords(Input);
	printf("Input=%s\n", Input);
	printf("Output=%s\n", Output);
	return 0;
}

/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/