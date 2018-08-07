#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

//#define DEBUG

struct node {
	int data;
	struct node *next;
};

int compose_sum(struct node *head, int count)
{
	int sum = 0;
	struct node *n = head;
	for (int i=count;i>0;i--) {
		int mul_temp = (int) pow(10, i-1);

		//handle with the overflow case
		if ((n->data) > (INT_MAX/mul_temp)) {
#ifdef DEBUG
			printf("The multiplication result will be overflow! return 0\n");
#endif
			return 0;			
		}

		if (sum > INT_MAX - (mul_temp * (n->data))) {
#ifdef DEBUG
			printf("The sum will be overflow! return 0\n");
#endif
			return 0;
		}

		sum += mul_temp * (n->data);
#ifdef DEBUG
		printf("current sum:%d\n", sum);
#endif
		n = n->next;
	}

	return sum;
}

void travel_nodes(struct node *head)
{
	struct node *n = head;
	while (n != NULL) {
		printf("%d\n", n->data);
		n = n->next;
	}
}

void reserve_linked_list(struct node **head)
{
	struct node *current = *head;
	struct node *previous = NULL;
	struct node *temp = NULL;

	while (current->next != NULL) {
		//printf("current:%d\n", current->data);
		temp = current->next;
		current->next = previous;
		previous = current;
		current = temp;
	}

	current->next = previous;
	*head = current;
}

void insert_node_end(struct node *head, int item)
{
	struct node *n = head;
	struct node *inserted_node = malloc(sizeof(struct node));
	
	//find the end node
	while (n->next != NULL) {
		n = n->next;
	}
	
	n->next = inserted_node;
	inserted_node->data = item;
	inserted_node->next = NULL;
}

bool isPalindrome(int x) {
	printf("The input is:%d\n", x);
 
	if (x < 0)
		return false;

	//for single digit case
	if ((x / 10) == 0)
		return true;

	int result, temp, isSigned = 0;

	temp = abs(x);

	int count = 0;
	struct node *head = malloc(sizeof(struct node));
	while (temp != 0) {
		int mod_temp = temp % 10;
#ifdef DEBUG
		printf("mod_temp=%d\n", mod_temp);
#endif

		if (count == 0) {
			head->data = mod_temp;
			head->next = NULL;
		}
		else {
			insert_node_end(head, mod_temp);
		}

		count++;
		temp = temp / 10;
	}

#ifdef DEBUG
	travel_nodes(head);
#endif

	int sum = compose_sum(head, count);
#ifdef DEBUG
	printf("final sum is:%d\n", sum);
#endif

	free(head);

	if (sum == x)
		return true;
	else
		return false;
}

int main(void)
{
	int input = 121;
	bool result = isPalindrome(input);
	if (result)
		printf("True\n");
	else
		printf("False\n");
	return 0;
}

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/