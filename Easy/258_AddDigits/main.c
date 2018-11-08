#include <stdio.h>
#include <stdlib.h>

int addDigits(int num) {
	int pop, local_sum;

	while (1) {
		local_sum = 0;
		while (num > 0) {
			pop = num % 10;
			local_sum += pop;
			num /= 10;
		}
		
		if (local_sum >= 10)
			num = local_sum;
		else
			break;
	}

	return local_sum;
}

int main(void)
{
	int Input = 38;
	printf("Input:%d\n", Input);

	int result = addDigits(Input);
	printf("Result=%d\n", result);
	
	return 0;
}

/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

Example:

Input: 38
Output: 2 
Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
             Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/
