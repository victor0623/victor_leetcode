#include <stdio.h>
#include <math.h>

//#define DEBUG

int findComplement(int num) {
	int sum, count, temp;

	temp = num;
	sum = count = 0;
	while (temp != 0) {
		int pop_value = temp % 2;
#ifdef DEBUG
		printf("pop_value=%d\n", pop_value);
#endif

		int mul_temp;
		if (!pop_value) {
			mul_temp = (int) pow(2,count);
#ifdef DEBUG
			printf("mul_temp=%d\n", mul_temp);
#endif
			sum += mul_temp;
#ifdef DEBUG
			printf("sum=%d\n", sum);
#endif
		}

		count++;
		temp /= 2;
	}

    return sum;
}

int main(void)
{
	int num = 5;
	int result = findComplement(num);
	printf("The input is:%d\n", num);
	printf("The output is:%d\n", result);
	return 0;
}

/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/