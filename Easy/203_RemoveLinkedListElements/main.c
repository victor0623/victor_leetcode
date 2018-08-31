#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
 	int val;
 	struct ListNode *next;
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL)
		return NULL;

	struct ListNode *n = head;
	struct ListNode *previous = NULL;
	while (n != NULL) {
		if (n->val == val) {
			if (previous == NULL) {
				struct ListNode *temp = head;
				head = head->next;
				n = n->next;
				free(temp);
			}
			else {
				previous->next = n->next;
				struct ListNode *temp = n;
				n = n->next;
				free(temp);
			}
		}
		else {
			previous = n;
			n = n->next;
		}
	}

	return head;
}

int main(void)
{
	struct ListNode * head = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node2 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node3 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node4 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node5 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node6 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node7 = (struct ListNode *) malloc(sizeof(struct ListNode));
	
	head->val = 1;
	head->next = node2;
	node2->val = 2;
	node2->next = node3;
	node3->val = 6;
	node3->next = node4;
	node4->val = 3;
	node4->next = node5;
	node5->val = 4;
	node5->next = node6;
	node6->val = 5;
	node6->next = node7;
	node7->val = 6;
	node7->next = NULL;

	int val = 6;

	struct ListNode *n = head;
	printf("The input is:\n");
	while (n != NULL) {
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");

	struct ListNode* result = removeElements(head, val);
	printf("The result with removing %d is:\n", val);
	while (result != 0) {
		printf("%d ", result->val);
		result = result->next;
	}
	printf("\n");

	return 0;
}

/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/