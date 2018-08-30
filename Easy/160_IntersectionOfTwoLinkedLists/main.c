#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void printMemory(struct ListNode *node)
{
	struct ListNode * n = node;
	while (n != NULL) {
		printf("0x%8x\n", n);
		n = n->next;
	}
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *n_A = headA;
	struct ListNode *n_B = headB;
	
	while (n_A != n_B) {
		if (n_A != NULL)
			n_A = n_A->next;
		else
			n_A = headB;

		if (n_B != NULL)
			n_B = n_B->next;
		else
			n_B = headA;
	}

	return n_A;
}

int main(void)
{
	struct ListNode * node1 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node2 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node3 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode * node4 = (struct ListNode *) malloc(sizeof(struct ListNode));

	node1->val = 1;
	node1->next = node2;
	printf("addr of node1:0x%8x\n", node1);

	node2->val = 2;
	node2->next = node3;
	printf("addr of node2:0x%8x\n", node2);

	node3->val = 3;
	node3->next = node4;
	printf("addr of node3:0x%8x\n", node3);

	node4->val = 4;
	node4->next = NULL;
	printf("addr of node4:0x%8x\n", node4);

	if (node1 < node2)
		printf("a\n");
	else
		printf("b\n");

	printMemory(node1);

	return 0;
}

/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
*/