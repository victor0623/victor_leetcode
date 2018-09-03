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

	int m=2, n=4;
	struct ListNode * result = reverseBetween(head, m, n);
	printf("The output with m=%d n=%d is:\n", m, n);
	printList(result);

	return 0;
}

/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/