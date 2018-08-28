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
		if (prices[i] < prices[buy_day]) {
			buy_day = sell_day =i;
			if (temp_profit >= max_profit)
				max_profit = temp_profit;
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

	if (temp_profit >= max_profit)
		max_profit = temp_profit;

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

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/