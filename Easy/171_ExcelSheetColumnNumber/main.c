#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int titleToNumber(char* s) {
	int str_len = (int) strlen(s);
	int base, i, c, sum = 0;

	for (i=0;i<str_len;i++) {
		base = (int) pow(26, (str_len-i-1));
		c = s[i]-64;
		sum = sum + base*c;
	}

	return sum;
}

int main(void)
{
	char Input[] = "ZY";
	printf("Input is :%s\n", Input);

	int result = titleToNumber(Input);
	printf("The result is %d\n", result);
	
	return 0;
}

/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
*/
