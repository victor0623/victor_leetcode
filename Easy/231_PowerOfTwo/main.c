#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
	if (n == 1)
		return true;
	else if (n <= 0)
		return false;
	else if (n % 2 == 1)
		return false;

	bool result = true;
	int pop, count = 0;
	while (n > 0) {
		pop = n % 2;
		//printf("pop=%d\n", pop);

		count += pop;
		if (count > 1) {
			result = false;
			break;
		}

		n /= 2;
	}

    return result;
}

int main(void)
{
	int n = 8;
	printf("n = %d\n", n);

	bool result = isPowerOfTwo(n);
	if (result)
		printf("Yes!\n");
	else
		printf("No!\n");

	return 0;
}

/*
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false
*/
