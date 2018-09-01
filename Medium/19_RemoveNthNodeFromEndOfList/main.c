#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void reserve_linked_list(struct ListNode **head)
{
	struct ListNode *current = *head;
	struct ListNode *previous = NULL;
	struct ListNode *temp = NULL;

	if (*head == NULL)
		return;

	while (current->next != NULL) {
		temp = current->next;
		current->next = previous;
		previous = current;
		current = temp;
	}

	current->next = previous;
	*head = current;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *current = head;
	reserve_linked_list(&current);

	struct ListNode *temp = current;
	struct ListNode *previous = NULL;
	int count = 1;
	while (temp != NULL) {
		printf("val:%d\n", temp->val);
		if (count == n) {
			if (previous == NULL) {
				struct ListNode * deletedNode = current;
				if (current->next == NULL)
					current = NULL;
				else
					current = current->next;

				free(deletedNode);
			}
			else {
				previous->next = temp->next;
				struct ListNode * deletedNode = temp;
				free(deletedNode);
			}
			break;
		}
		count++;
		previous = temp;
		temp = temp->next;
	}

	reserve_linked_list(&current);

    return current;
}

int main(void)
{
	struct ListNode * head = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node2 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node3 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node4 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node5 = (struct ListNode *) malloc(sizeof(struct ListNode));

	
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

	struct ListNode *n = head;
	printf("The input is:\n");
	while (n != NULL) {
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");

	int N = 1;

	struct ListNode *result = removeNthFromEnd(head, N);

	printf("The result is:\n");
	while (result != NULL) {
		printf("%d ", result->val);
		result = result->next;
	}
	printf("\n");

	return 0;
}

/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/