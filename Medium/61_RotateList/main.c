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
struct ListNode* rotateRight(struct ListNode* head, int k) {
	struct ListNode * rotated_head = head;
	struct ListNode *n;
	struct ListNode *previous;

	if (rotated_head == NULL)
		return NULL;

	int count = 0;
	n = head;
	while (n != NULL) {
		count++;
		n = n->next;
	}

	k = k % count;

	while (k > 0) {
		n = rotated_head;
		previous = NULL;
		while (1) {
			if (n->next == NULL) {
				previous->next = NULL;
				n->next = rotated_head;
				break;
			}

			previous = n;
			n = n->next;
		}

		rotated_head = n;
		k--;
	}

    return rotated_head;
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

	struct ListNode * result = rotateRight(head, k);
	printf("The output with k %d is:\n", k);
	printList(result);

	return 0;
}

/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/