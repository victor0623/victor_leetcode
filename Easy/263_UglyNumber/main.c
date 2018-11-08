#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isUgly(int num) {
	if (num == 1)
		return true;
	if (num <= 0)
		return false;

	bool result = true;

	while (num > 0) {
		if (num % 2 == 0)
			num /= 2;
		else if (num % 3 == 0)
			num /= 3;
		else if (num % 5 == 0)
			num /= 5;
		else {
			result = false;
			break;
		}

		//printf("num=%d\n", num);
			
		if (num == 1)
			break;
	}

	return result;
}

int main(void)
{
	int Input = 6;
	printf("Input:%d\n", Input);

	bool result = isUgly(Input);
	if (result)
		printf("Yes!\n");
	else
		printf("No!\n");
	
	return 0;
}

/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Example 1:

Input: 6
Output: true
Explanation: 6 = 2 กั 3
Example 2:

Input: 8
Output: true
Explanation: 8 = 2 กั 2 กั 2
Example 3:

Input: 14
Output: false 
Explanation: 14 is not ugly since it includes another prime factor 7.
Note:

1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range: [?231,  231 ? 1].
*/
