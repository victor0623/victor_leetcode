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

struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode * partition_head = head;
	struct ListNode *n = partition_head;
	struct ListNode *previous = NULL;
	struct ListNode *select = NULL;

	while (n != NULL) {
		struct ListNode *temp = n->next;
		if (n->val < x) {
			if (select == NULL) {
				if (previous == NULL) {
					previous = n;
				}
				else {
					previous->next = n->next;
					n->next = partition_head;
					partition_head = n;
				}
			}
			else {
				if (previous->val < x) {
					previous = n;
				}
				else {
					previous->next = n->next;
					n->next = select->next;
					select->next = n;
				}
			}

			select = n;
		}
		else {
			previous = n;
		}
		n = temp;
	}

    return partition_head;
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
	node2->val = 4;
	node2->next = node3;
	node3->val = 3;
	node3->next = node4;
	node4->val = 2;
	node4->next = node5;
	node5->val = 5;
	node5->next = node6;
	node6->val = 2;
	node6->next = NULL;

	printf("The input list is:\n");
	printList(head);

	int x = 3;
	struct ListNode * result = partition(head, x);
	printf("The output with x=%d is:\n", x);
	printList(result);

	return 0;
}

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/