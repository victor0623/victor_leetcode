#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
	int i, pre1_sum, pre2_sum, sum=0;
	for (i=1;i<=n;i++) {
		if (i == 1)
			sum = pre2_sum = 1;
		else if (i == 2)
			sum = pre1_sum = 2;
		else {
			//printf("i=%d\n", i);
			sum = pre1_sum + pre2_sum;
			//printf("pre1_sum:%d pre2_sum:%d sum:%d\n", pre1_sum, pre2_sum, sum);
			pre2_sum = pre1_sum;
			pre1_sum = sum;
		}
	}
	
	return sum;
}

int main(void)
{
	int n = 6;
	printf("n=%d\n", n);

	int result = climbStairs(n);
	printf("The result is :%d\n", result);
	
	return 0;
}

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/
