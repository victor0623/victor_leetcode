#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//#define DEBUG

struct ListNode {
	int val;
	struct ListNode *next;
};

void printList(struct ListNode * head)
{
	struct ListNode *n = head;
	while (n != NULL) {
		//printf("val:%d addr:%x ", n->val, (int) n);
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
struct ListNode* reverseList2(struct ListNode* head) {
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

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode * reversed_head = head;
	struct ListNode *n = reversed_head;
	struct ListNode *previous = NULL;
	struct ListNode *previous_new = NULL;

	struct ListNode * new_node;
	while (n != NULL) {
		struct ListNode *temp = n->next;
		new_node = malloc(sizeof(struct ListNode));
		new_node->val = n->val;
		if (previous_new == NULL)
			new_node->next = NULL;
		else 
			new_node->next = previous_new;

		previous_new = new_node;

		n = n->next;
	}

	return new_node;
}

struct ListNode* oddEvenList(struct ListNode* head) {
	struct ListNode *odd_head = NULL;
	struct ListNode *odd_c = odd_head;
	struct ListNode *even_head = NULL;
	struct ListNode *even_c = even_head;
	struct ListNode *n = head;

	int count = 1;
	while (n != NULL) {
		printf("n->val:%d\n", n->val);
		struct ListNode *temp = n->next;
		if (count % 2 == 1) {
			if (odd_head == NULL) {
				odd_head = n;
				odd_c = odd_head;
			}
			else {
				odd_c->next = n;
				odd_c = odd_c->next;
			}
		}
		else {
			if (even_head == NULL) {
				even_head = n;
				even_c = even_head;
			}
			else {
				even_c->next = n;
				even_c = even_c->next;
			}
		}

		n = n->next;
		count++;
	}

	if (even_head != NULL)
		even_c->next = NULL;

	if (odd_c != NULL) {
		odd_c->next = even_head;
	}
	else {
		odd_head = even_head;
	}

    return odd_head;
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

	head->val = 2;
	head->next = node2;
	node2->val = 1;
	node2->next = node3;
	node3->val = 3;
	node3->next = node4;
	node4->val = 5;
	node4->next = node5;
	node5->val = 6;
	node5->next = node6;
	node6->val = 4;
	node6->next = node7;
	node7->val = 7;
	node7->next = NULL;

	printf("The input list is:\n");
	printList(head);

	printf("The result is:\n");
	struct ListNode * result = oddEvenList(head);
	printList(result);

	return 0;
}

/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
*/