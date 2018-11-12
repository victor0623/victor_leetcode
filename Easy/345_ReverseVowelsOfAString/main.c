#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG

int isVowel(char c) {
	switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return 1;
		default:
			return 0;
	}
}

char* reverseVowels(char* s) {
	int str_len = (int) strlen(s);
	if (str_len <= 1)
		return s;
	
	char temp;
	char * result = malloc(str_len+1);
	if (result) {
		//memcpy(result, (void *) s, str_len+1);
		strcpy(result, s);
	}
	
	int h, r;
	h = 0;
	r = str_len-1;
	int isTerminal = 0;

	while (1) {
		if ((h >= r) || (h >= str_len-1))
			break;

		if (isVowel(result[h]) == 1) {
#ifdef DEBUG
			printf("I am head--> h=%d result[%d]:%c\n", h, r, result[h]);
#endif

			while (1) {
				if (h >= r || r <= 0) {
					isTerminal = 1;
					break;
				}

				if (isVowel(result[r]) == 1) {
#ifdef DEBUG
					printf("I am rear-->Found! h=%d result[%d]:%c\n", h, r, result[r]);
#endif
					temp = result[h];
					result[h] = result[r];
					result[r] = temp;
					
					r--;
					break;
				}
				else {
					r--;
				}
			}
		}

		if (isTerminal)
			break;
		
		h++;
	}
	
	return result;
}

int main(void)
{
	char Input[] = "hello";
	printf("Input is:%s\n", Input);

	char *Output = reverseVowels(Input);
	printf("Output is:%s\n", Output);
	
	return 0;
}

/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"
Note:
The vowels does not include the letter "y".
*/
