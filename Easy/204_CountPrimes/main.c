#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int is_prime(int x){
	if(x <= 1) return 0;
	for(int i = 2; i * i <= x; i++)
	    if(x % i == 0)
           	return 0;
	return 1;
}

int countPrimes(int n) {
	int sum = 0;
	int i;
	for (i=0;i<n;i++)
		sum = sum + is_prime(i);
	
	return sum;
}

int countPrimes_SieveOfEratosthenes(int n) {
	if (n <= 2)
		return 0;

	int i, j, p, sum = 0;
	bool *list = malloc(sizeof(bool) * n);

	//initialization
	for (i=2;i<n;i++) {
		list[i] = true;
	}

	for (i=2;i<n;i++) {
		if (list[i] == true) {
			
			p = i;
			for (j=p; j<=n;j+=p) {
				list[j] = false;
			}

			sum++;
		}	
	}

	if (list)
		free(list);

	return sum;
}

int main(void)
{
	int n = 10000;
	printf("n = %d\n", n);

	int result = countPrimes_SieveOfEratosthenes(n);
	printf("result = %d\n", result);
	
	return 0;
}

/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
