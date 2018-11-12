#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfThree(int n) {
	if (n == 1)
		return true;
	else if (n <= 0)
		return false;

	bool result = true;
	int pop, count = 0;
	while (n > 1) {
		pop = n % 3;
		//printf("pop=%d\n", pop);
		if (pop != 0) {
			result = false;
			break;
		}

		n /= 3;
	}

    	return result;
}

int main(void)
{
	int n = 3;
	printf("n = %d\n", n);

	bool result = isPowerOfThree(n);
	if (result)
		printf("Yes!\n");
	else
		printf("No!\n");

	return 0;
}

/*
Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
Follow up:
Could you do it without using any loop / recursion?
*/
