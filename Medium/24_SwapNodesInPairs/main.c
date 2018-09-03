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

struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode * swapped_head = head;
	struct ListNode *n = swapped_head;
	struct ListNode *previous = NULL;
	struct ListNode *odd_pre = NULL;

	int count = 1;

	while (n != NULL) {
		struct ListNode *temp = n->next;

		if (count % 2 == 0) {
			if (count == 2) {
				swapped_head->next = n->next;
				swapped_head = n;
				swapped_head->next = previous;
			}
			else {
				previous->next = n->next;
				n->next = previous;
				odd_pre->next = n;
			}
		}
		else {
			odd_pre = previous;
			previous = n;
		}
		
		n = temp;
		count++;
	}
	
	return swapped_head;
}

int main(void)
{
	struct ListNode * head = malloc(sizeof(struct ListNode));
	struct ListNode * node2 = malloc(sizeof(struct ListNode));
	struct ListNode * node3 = malloc(sizeof(struct ListNode));
	struct ListNode * node4 = malloc(sizeof(struct ListNode));
	//struct ListNode * node5 = malloc(sizeof(struct ListNode));

	head->val = 1;
	head->next = node2;
	node2->val = 2;
	node2->next = node3;
	
	node3->val = 3;
	node3->next = node4;
	node4->val = 4;
	node4->next = NULL;
	/*
	node5->val = 5;
	node5->next = NULL;
	*/

	printf("The input list is:\n");
	printList(head);

	struct ListNode * result = swapPairs(head);
	printf("The output is:\n");
	printList(result);

	return 0;
}

/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
*/