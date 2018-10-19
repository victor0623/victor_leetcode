#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int trailingZeroes(int n) {
	int base = 5;
	int sum = 0, count;

	while (1) {
		count = n/base;
		if (count == 0)
			break;
		
		sum += count;
		if (base > INT_MAX/5)
			break;
		else
			base *= 5;
	}

	return sum;
}

int main(void)
{
	int n = 100;
	printf("n=%d\n", n);

	int result = trailingZeroes(n);
	printf("result=%d\n", result);
	
	return 0;
}

/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.
*/