#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
 	int val;
 	struct ListNode *next;
 };

void travel_nodes(struct ListNode *head)
{
	struct ListNode *n = head;
	while (n != NULL) {
		printf("%d\n", n->val);
		n = n->next;
	}
}

void insert_node_end(struct ListNode *head, int item)
{
	struct ListNode *n = head;
	struct ListNode *inserted_node = malloc(sizeof(struct ListNode));
	
	//find the end node
	while (n->next != NULL) {
		n = n->next;
	}
	
	n->next = inserted_node;
	inserted_node->val = item;
	inserted_node->next = NULL;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int local_sum = 0, bonus = 0, isFirstDigit = 1;
	int l1_val, l2_val;

	struct ListNode *result = malloc(sizeof(struct ListNode));
	if (result != NULL) {
		while (1) {
			if (l1 == NULL && l2 == NULL)
				break;

			if (l1 == NULL)
				l1_val = 0;
			else
				l1_val = l1->val;

			if (l2 == NULL)
				l2_val = 0;
			else
				l2_val = l2->val;

			local_sum = l1_val + l2_val + bonus;
			bonus = local_sum / 10;
			local_sum = local_sum % 10;

			if (isFirstDigit == 1) {
				result->val = local_sum;
				result->next = NULL;
				isFirstDigit = 0;
			}
			else {
				insert_node_end(result, local_sum);
			}

			if (l1 != NULL)
				l1 = l1->next;
			if (l2 != NULL)
				l2 = l2->next;
		}
	}

	if (bonus > 0) {
		insert_node_end(result, bonus);
	}

    return result;
}

int main(void)
{
	struct ListNode *l1 = malloc(sizeof(struct ListNode));
	struct ListNode *l2 = malloc(sizeof(struct ListNode));

	/*
	l1->val = 2;
	l1->next = NULL;
	insert_node_end(l1, 4);
	insert_node_end(l1, 3);

	l2->val = 5;
	l2->next = NULL;
	insert_node_end(l2,6);
	insert_node_end(l2,4);
	*/
	l1->val = 9;
	l1->next = NULL;
	insert_node_end(l1, 9);
	insert_node_end(l1, 9);

	l2->val = 9;
	l2->next = NULL;
	insert_node_end(l2,9);
	insert_node_end(l2,9);

	printf("number1:\n");
	travel_nodes(l1);
	printf("number2:\n");
	travel_nodes(l2);

	struct ListNode *result = addTwoNumbers(l1, l2);
	printf("The result is:\n");
	travel_nodes(result);

	return 0;
}

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/