#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

struct ListNode {
	int val;
	struct ListNode *next;
};

void printList(struct ListNode * head)
{
	struct ListNode *n = head;
	while (n != NULL) {
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode * reversed_head = head;
	struct ListNode *n = reversed_head;
	struct ListNode *previous = NULL;

	while (n != NULL) {
		struct ListNode *temp = n->next;
		n->next = previous;
		previous = n;
		n = temp;
	}

	reversed_head = previous;

    return reversed_head;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
	struct ListNode * reversed_head = head;
	struct ListNode *node = reversed_head;
	struct ListNode *previous = NULL;
	struct ListNode *start, *start_pre, *end;
	int count = 1;

	while (node != NULL) {
		if (count >= m && count <= n) {
			struct ListNode *temp = node->next;

			if (count == m) {
				start = node;
				start_pre = previous;
			}
			
			node->next = previous;
			previous = node;
			
			if (count == n) {
				start->next = temp;
				if (m == 1)
					reversed_head = node;
				else
					start_pre->next = node;
			}

			node = temp;

			if (count == n)
				break;
		}
		else {
			previous = node;
			node = node->next;
		}

		count++;	
	}

	return reversed_head;    
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
	if (head == NULL)
		return NULL;

	if (k == 1)
		return head;
	
	struct ListNode * reversed_head = head;
	struct ListNode *node = reversed_head;
	struct ListNode *previous = NULL;
	struct ListNode *start, *start_pre = NULL;
	int count = 1;
	int group_index = 0;

	struct ListNode * n = head;
	int len = 0;
	while (n != NULL) {
		len++;
		n = n->next;
	}

	int max_group = len / k + 1;

	while (node != NULL) {
		struct ListNode *temp = node->next;
		group_index = (count-1) / k + 1;
		if (group_index < max_group) {
			if (count % k == 1)
				start = node;

			if (count > 1 && count % k != 1)
				node->next = previous;
			previous = node;

			if (count % k == 0) {
				start->next = temp;
				if (group_index == 1)
					reversed_head = node;
				else
					start_pre->next = node;
				
				start_pre = start;
			}
		
		}
		
		node = temp;
		count ++;	
	}
	
	return reversed_head;
}

int main(void)
{
	struct ListNode * head = malloc(sizeof(struct ListNode));
	struct ListNode * node2 = malloc(sizeof(struct ListNode));
	struct ListNode * node3 = malloc(sizeof(struct ListNode));
	struct ListNode * node4 = malloc(sizeof(struct ListNode));
	struct ListNode * node5 = malloc(sizeof(struct ListNode));

	head->val = 1;
	head->next = node2;
	node2->val = 2;
	node2->next = node3;
	node3->val = 3;
	node3->next = node4;
	node4->val = 4;
	node4->next = node5;
	node5->val = 5;
	node5->next = NULL;

	printf("The input list is:\n");
	printList(head);

	int k = 2;
	struct ListNode * result = reverseKGroup(head, k);
	printf("The output with k=%d\n", k);
	printList(result);

	return 0;
}

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/