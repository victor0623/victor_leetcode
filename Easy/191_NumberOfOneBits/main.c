#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
	int h_weight = 0;

	while (n != 0) {
		h_weight += (n % 2);
		n /= 2;
	}

       return h_weight;
}

int main(void)
{
	uint32_t n = 128;
	printf("n=%d\n", n);

	int result = hammingWeight(n);
	printf("result=%d\n", result);
	
	return 0;
}

/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: 11
Output: 3
Explanation: Integer 11 has binary representation 00000000000000000000000000001011 
Example 2:

Input: 128
Output: 1
Explanation: Integer 128 has binary representation 00000000000000000000000010000000
*/

