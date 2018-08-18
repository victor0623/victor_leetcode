#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

char* reverseString(char* s) {
	int len = 0;
	char *ptr_s = s;
	if (ptr_s == NULL)
		return NULL;

	while (*ptr_s != '\0') {
		len++;
		ptr_s++;
	}

#ifdef DEBUG
	printf("string len=%d\n", len);
#endif
	char *r = malloc(sizeof(char) * (len+1));
	if (r == NULL)
		return NULL;

	int i;
	for (i=0;i<len;i++) {
		*(r+i) = *(s+len-i-1);
#ifdef DEBUG
		printf("%c\n", *(r+i));
#endif
	}

	*(r+i) = '\0';

    return r;
}

int main(void)
{
	//char Input[] = "hello";
	char Input[] = "A man, a plan, a canal: Panama";
	char *Output = reverseString(Input);

	printf("Input=%s\n", Input);
	printf("Output=%s\n", Output);
	return 0;
}


/*
Write a function that takes a string as input and returns the string reversed.

Example 1:

Input: "hello"
Output: "olleh"
Example 2:

Input: "A man, a plan, a canal: Panama"
Output: "amanaP :lanac a ,nalp a ,nam A"
*/