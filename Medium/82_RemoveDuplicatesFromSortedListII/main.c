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

struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	
	struct ListNode * new_head = head;
	struct ListNode * current = new_head;
	struct ListNode *n = head;
	struct ListNode *cur_previous = NULL;
	int isDupFound = 0;

	n = n->next;

	while (n != NULL) {
		if (current->val == n->val) {
			if (isDupFound == 0) {
				current->next = n;
				current = current->next;
				isDupFound = 1;
			}
		}
		else {
			if (isDupFound == 1) {
				if (cur_previous == NULL) {
					new_head = n;
					current = new_head;
				}
				else {
					cur_previous->next = n;
					current = n;	
				}
				isDupFound = 0;
			}
			else {
				cur_previous = current;
				current->next = n;
				current = current->next;
			}
		}

		n = n->next;
	}

	if (isDupFound == 1) {
		if (cur_previous == NULL) {
			new_head = NULL;
		}
		else {
			current = cur_previous;
			current->next = NULL;
		}
	}
	
	return new_head;
}

int main(void)
{
	struct ListNode * head = malloc(sizeof(struct ListNode));
	struct ListNode * node2 = malloc(sizeof(struct ListNode));
	struct ListNode * node3 = malloc(sizeof(struct ListNode));
	struct ListNode * node4 = malloc(sizeof(struct ListNode));
	struct ListNode * node5 = malloc(sizeof(struct ListNode));
	struct ListNode * node6 = malloc(sizeof(struct ListNode));
	struct ListNode * node7 = malloc(sizeof(struct ListNode));

	head->val = 1;
	head->next = node2;
	node2->val = 1;
	node2->next = NULL;
	/*
	node3->val = 1;
	node3->next = node4;
	node4->val = 2;
	node4->next = node5;
	node5->val = 3;
	node5->next = node6;
	node6->val = 3;
	node6->next = NULL;
	//node7->val = 5;
	//node7->next = NULL;
	*/

	printf("The input list is:\n");
	printList(head);

	struct ListNode * result = deleteDuplicates(head);
	printList(result);

	return 0;
}

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/
