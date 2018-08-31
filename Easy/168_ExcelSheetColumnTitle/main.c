#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

char* convertToTitle(int n) {
	int nums_char = 0;
	int temp = n, pop;

	while (temp != 0) {
		nums_char++;
		pop = temp % 26;
#ifdef DEBUG
		printf("temp=%d\n", temp);
#endif
		temp /= 26;
		if (pop == 0)
			temp--;
	}

#ifdef DEBUG
	printf("nums_char=%d\n", nums_char);
#endif

	char *result = (char *) malloc(sizeof(char) * (nums_char+1));
	int i = 0;
	if (result != NULL) {
		temp = n;
		while (temp != 0) {
			pop = temp % 26;
			if (pop != 0)
				*(result+nums_char-i-1) = (char) (pop+65-1);
			else
				*(result+nums_char-i-1) = 'Z';

#ifdef DEBUG
			printf("pop:%d result:%c\n", pop, *(result+nums_char-i-1));
#endif
			temp /= 26;
			if (pop == 0)
				temp--;
			i++;
		}
	}

	*(result+nums_char) = '\0';

    return result;
}

int main(void)
{
	int n = 701;
	printf("n=%d\n", n);

	char *result = convertToTitle(n);
	printf("result:%s\n", result);

	return 0;
}

/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
*/