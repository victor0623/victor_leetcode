#include <stdio.h>
#include <stdlib.h>

#define PRIME_NUM 11
//#define DEBUG

int prime_num[PRIME_NUM] = {2,3,5,7,11,13,17,19,23,29,31};

int is_prime_num(int N)
{
	int isPrimeNum = 0;
	for (int i=0;i<PRIME_NUM;i++) {
		if (N == prime_num[i]) {
			isPrimeNum = 1;
			break;
		}
	}

	return isPrimeNum;
}

int calculate_set_bit(int N)
{
	int pop, num_set_bit = 0;
	while (N != 0) {
		pop = N % 2;
		if (pop == 1)
			num_set_bit++;
		N /= 2;
	}

	return num_set_bit;
}

int countPrimeSetBits(int L, int R) {
	int i, j, num_set_bit, total_prime_num = 0;

	for (i=L;i<=R;i++) {
		num_set_bit = calculate_set_bit(i);
#ifdef DEBUG
		printf("num_set_bit = %d\n", num_set_bit);
#endif
		total_prime_num = total_prime_num + is_prime_num(num_set_bit);
	}

    return total_prime_num;
}

int main(void)
{
	int L = 10;
	int R = 15;

	printf("L=%d R=%d\n", L, R);

	int result = countPrimeSetBits(L, R);
	printf("The result is:%d\n", result);

	return 0;
}

/*
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
Example 2:

Input: L = 10, R = 15
Output: 5
Explanation:
10 -> 1010 (2 set bits, 2 is prime)
11 -> 1011 (3 set bits, 3 is prime)
12 -> 1100 (2 set bits, 2 is prime)
13 -> 1101 (3 set bits, 3 is prime)
14 -> 1110 (3 set bits, 3 is prime)
15 -> 1111 (4 set bits, 4 is not prime)
Note:

L, R will be integers L <= R in the range [1, 10^6].
R - L will be at most 10000.
*/