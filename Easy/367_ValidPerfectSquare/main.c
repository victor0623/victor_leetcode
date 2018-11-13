#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPerfectSquare(int num) {
	if (num == 1)
		return true;
	else if (num <= 0)
		return false;

	int x, square_num;
	x = 2;
	while (1) {
		//printf("x=%d\n", x);
		if (x > (INT_MAX/x)) {
			return false;
		}
		else {
			square_num = x * x;
			if (square_num > num) {
				return false;
			}
			else if (square_num == num)
				return true;
		}

		x++;
	}
}

int main(void)
{
	int n = 16;
	printf("n = %d\n", n);

	bool result = isPerfectSquare(n);
	if (result)
		printf("Yes!\n");
	else
		printf("No!\n");

	return 0;
}

/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/