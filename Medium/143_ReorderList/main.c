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

void reorderList(struct ListNode* head) {
	struct ListNode *n = head;
	int len = 0;
	while (n != NULL) {
		len++;
		n = n->next;
	}

	if (len != 0) {
		int count = 0, i, index;
		struct ListNode  ** temp_nodes = (struct ListNode  **) malloc(sizeof(struct ListNode *) * len );
		if (temp_nodes != NULL) {
			for (i=0;i<len;i++) {
				temp_nodes[i] = (struct ListNode  *) malloc(sizeof(struct ListNode));
			}

			n = head;
			int half;
			if (len % 2 == 1)
				half = len / 2 + 1;
			else
				half = len / 2;

			while (n != NULL) {
				if (count < half) {
					index = count*2;
					temp_nodes[index] = n;
				}
				else {
					index = (len - count - 1) * 2 + 1;
					temp_nodes[index] = n;
				}
				
				count++;
				n = n->next;
			}
		}

		n = head;
		for (i=1;i<len;i++) {
			n->next = temp_nodes[i];
			n = n->next;
		}

		n->next = NULL;
	}
	
}

int main(void)
{
	struct ListNode * head = malloc(sizeof(struct ListNode));
	struct ListNode * node2 = malloc(sizeof(struct ListNode));
	struct ListNode * node3 = malloc(sizeof(struct ListNode));
	struct ListNode * node4 = malloc(sizeof(struct ListNode));
	struct ListNode * node5 = malloc(sizeof(struct ListNode));
	struct ListNode * node6 = malloc(sizeof(struct ListNode));

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
	/*
	node6->val = 2;
	node6->next = NULL;
	*/

	printf("The input list is:\n");
	printList(head);

	reorderList(head);
	printf("The re-order result is:\n");
	printList(head);

	return 0;
}

/*
Given a singly linked list L: L0¡÷L1¡÷¡K¡÷Ln-1¡÷Ln,
reorder it to: L0¡÷Ln¡÷L1¡÷Ln-1¡÷L2¡÷Ln-2¡÷¡K

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/