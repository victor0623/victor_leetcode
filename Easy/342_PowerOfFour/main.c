#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfFour(int n) {
	if (n == 1)
		return true;
	else if (n <= 0)
		return false;
	else if (n % 2 != 0)
		return false;

	bool result = true;
	int pop, count = 0;
	while (n > 1) {
		pop = n % 4;
		//printf("pop=%d\n", pop);
		if (pop != 0) {
			result = false;
			break;
		}

		n /= 4;
	}

    	return result;
}

int main(void)
{
	int n = 16;
	printf("n = %d\n", n);

	bool result = isPowerOfFour(n);
	if (result)
		printf("Yes!\n");
	else
		printf("No!\n");

	return 0;
}

/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
*/
