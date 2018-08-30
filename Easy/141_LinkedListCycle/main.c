#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
	    return false;

	bool isCycle = false;
	struct ListNode * node_1 = head;
	struct ListNode * node_2 = head->next;
	if (node_2->next != NULL)
		node_2 = node_2->next;
	else
		return false;

	while (1) {
		if (node_1 == node_2) {
			isCycle = true;
			break;
		}
		
		if (node_1->next != NULL)
			node_1 = node_1->next;
		else 
			break;

		if (node_2->next != NULL) {
			node_2 = node_2->next;
			if (node_2->next != NULL) {
				node_2 = node_2->next;
			}
			else
				break;		
		}
		else
			break;
	}

	return isCycle;
}

int main(void)
{
	struct ListNode * node1 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node2 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node3 = (struct ListNode *) malloc(sizeof(struct ListNode));
	/*
	struct ListNode * node4 = (struct ListNode *) malloc(sizeof(struct ListNode));
	*/

	node1->val = 1;
	node1->next = node2;
	printf("addr of node1:0x%8x\n", (unsigned int) node1);

	node2->val = 2;
	node2->next = node3;
	printf("addr of node2:0x%8x\n", (unsigned int) node2);

	node3->val = 3;
	node3->next = NULL;
	printf("addr of node3:0x%8x\n", (unsigned int) node3);

	/*
	node4->val = 4;
	node4->next = NULL;
	printf("addr of node4:0x%8x\n", node4);
	*/

	bool result =  hasCycle(node1);
	if (result)
		printf("It's a cycle!\n");
	else
		printf("It's not a cycle!\n");

	return 0;
}

/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/
