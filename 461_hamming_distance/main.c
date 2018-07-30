#include <stdio.h>

int hammingDistance(int x, int y) {
	int h_dist = 0;
	int temp = x^y;

	while (temp != 0) {
		h_dist += (temp % 2);
		temp /= 2;
	}

    return h_dist;
}

int main(void)
{
	int a = 1;
	int b = 4;

	printf("the hammingDistance between %d and %d is: %d\n", a, b, hammingDistance(a, b));

	return 0;
}