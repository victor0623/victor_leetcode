#include <stdio.h>
#include <stdlib.h>
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


int reverse(int x) {
	//for single digit case
	if ((x / 10) == 0) {
		return x;
	}

	int result, temp, isSigned = 0;

	if (x < 0)
		isSigned = 1;
		
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

	if (isSigned == 1)
		result = sum * (-1);
	else
		result = sum;

	free(head);
    return result;
}

int main(void)
{
	int input_value = 123;
	int y = reverse(input_value);

	printf("The input value is:%d\n", input_value);
	printf("returned value is:%d\n", y);

	return 0;
}

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/