#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

void printArray(int *Array, int size)
{
	printf("Array of size %d is:\n", size);
	for (int i=0;i<size;i++)
		printf("%d ", Array[i]);
	printf("\n");
}

int maxProfit(int* prices, int pricesSize) {
	int i, buy_day = 0, sell_day = 0;
	int max_profit = 0, temp_profit= 0;

	for (i=0;i<pricesSize;i++) {
#ifdef DEBUG
		printf("prices[%d]:%d\n", i, prices[i]);
#endif

		if (prices[i] < prices[sell_day]) {
#ifdef DEBUG
			printf("max_profit:%d temp_profit:%d\n", max_profit, temp_profit);
#endif
			buy_day = sell_day =i;
			max_profit += temp_profit;
			temp_profit = 0;
			continue;
		}

		if (prices[i] > prices[sell_day]) {
			sell_day = i;
			temp_profit = prices[sell_day] - prices[buy_day];
		}
#ifdef DEBUG
		printf("buy_day:%d sell_day:%d temp_profit:%d\n", buy_day, sell_day, temp_profit);
#endif
		
	}

	if (temp_profit != 0 && buy_day != sell_day)
		max_profit += temp_profit;

	return max_profit;
}

int main(void)
{
	int Input[] = {7,1,5,3,6,4};
	//int Input[] = {1,7,1};
	int Input_size = sizeof(Input)/sizeof(int);

	printf("The input is:\n");
	printArray(Input, Input_size);

	int max_profit = maxProfit(Input, Input_size);
	printf("The max profit is:%d\n", max_profit);
	
	return 0;
}

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
