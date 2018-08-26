#include <stdlib.h>
#include <stdio.h>

#define DEBUG

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
struct ListNode* deleteDuplicates(struct ListNode* head) {
	struct ListNode *n = head;

	if (n == NULL)
		return NULL;

	int isFirstNode = 1, previous_val;
	struct ListNode *result = malloc(sizeof(struct ListNode));
	if (result != NULL) {
		while (n != NULL) {
			if (isFirstNode == 1) {
				result->val = n->val;
				result->next = NULL;
				isFirstNode = 0;
			}
			else {
				if (n->val != previous_val)
					insert_node_end(result, n->val);
			}

			previous_val = n->val;
			n = n->next;
		}
	}

    return result;
}

int main(void)
{
	struct ListNode *head = malloc(sizeof(struct ListNode));

	head->val = 1;
	head->next = NULL;

	printf("The input list:\n");
	insert_node_end(head, 1);
	insert_node_end(head, 2);
	insert_node_end(head, 3);
	insert_node_end(head, 3);

	travel_nodes(head);

	struct ListNode *result = deleteDuplicates(head);
	printf("Result is:\n");
	travel_nodes(result);

	return 0;
}

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/