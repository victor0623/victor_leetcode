#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define DEBUG

bool hasAlternatingBits(int n) {
	int temp = n;
	int pop;

	if (temp/2 == 0)
		return true;

	int previous, init = 1;
	while (temp != 0) {
		pop = temp % 2;
		if (init == 1) {
			init = 0;
		}
		else {
#ifdef DEBUG
			printf("pop:%d previous:%d\n", pop, previous);
#endif
			if ((pop ^ previous) == 0)
				return false;

		}

		previous = pop;
		temp /= 2;
	}

    return true;
}

int main(void)
{
	int Input = 5;
	printf("Input is:%d\n", Input);
	bool result = hasAlternatingBits(Input);

	if (result)
		printf("It is true!\n");
	else
		printf("It is false!\n");

	return 0;
}

/*
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: 5
Output: True
Explanation:
The binary representation of 5 is: 101
Example 2:
Input: 7
Output: False
Explanation:
The binary representation of 7 is: 111.
Example 3:
Input: 11
Output: False
Explanation:
The binary representation of 11 is: 1011.
Example 4:
Input: 10
Output: True
Explanation:
The binary representation of 10 is: 1010.
*/