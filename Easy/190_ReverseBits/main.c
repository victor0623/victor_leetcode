#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t reverseBits(uint32_t n) {
	uint32_t sum = 0;
	uint32_t pop, base, y = 31;
	while (n > 0) {
		pop = n % 2;
		base = (uint32_t) pow(2, y);
		sum = sum + (pop * base);
		y--;
		n /= 2;
	}

	return sum;
}

int main(void)
{
	uint32_t n = 43261596;
	printf("n=%d\n", n);

	uint32_t result = reverseBits(n);
	printf("result=%u\n", result);
	
	return 0;
}

/*
Reverse bits of a given 32 bits unsigned integer.

Example:

Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
             return 964176192 represented in binary as 00111001011110000010100101000000.
Follow up:
If this function is called many times, how would you optimize it?
*/
