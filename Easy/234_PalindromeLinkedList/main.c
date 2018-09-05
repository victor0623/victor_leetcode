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

bool isPalindrome(struct ListNode* head) {
	bool is_Palindrome = true;
	struct ListNode * reversed_head = reverseList(head);

	printf("head:\n");
	printList(head);
	printf("reversed_head\n");
	printList(reversed_head);
	
	while (head != NULL) {
		printf("head->val:%d reversed_head:%d\n", head->val, reversed_head->val);
		if (head->val != reversed_head->val) {
			is_Palindrome = false;
			break;
		}
		head = head->next;
		reversed_head = reversed_head->next;
	}
	
	return is_Palindrome;
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
	node3->val = 2;
	node3->next = node4;
	node4->val = 1;
	node4->next = NULL;
	/*
	node5->val = 5;
	node5->next = node6;
	node6->val = 2;
	node6->next = NULL;
	*/

	printf("The input list is:\n");
	printList(head);

	bool result = isPalindrome(head);
	if (result)
		printf("It's palindrome!\n");
	else
		printf("It's not palindrome!\n");

	return 0;
}

/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/