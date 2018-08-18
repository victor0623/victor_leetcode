#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};

void travel_nodes(struct ListNode *head)
{
	struct ListNode *n = head;
	while (n != NULL) {
		printf("%d\n", n->val);
		n = n->next;
	}
}

int get_node_num(struct ListNode *head)
{
	struct ListNode *n = head;
	int node_num = 0;
	while (n != NULL) {
		node_num++;
		n = n->next;
	}
	return node_num;
}

struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode * current = head;
	int node_num, index_middleNode, i;

	node_num = get_node_num(head);
	printf("the number of nodes is: %d\n", node_num);

	index_middleNode = node_num/2 + 1;
	printf("the index of middle node is: %d\n", index_middleNode);

	for (i=0;i<index_middleNode-1;i++) {
		current = current->next;
	}

    return current;
}


int main(void)
{
	struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode *node1 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode *node2 = (struct ListNode *) malloc(sizeof(struct ListNode));
	struct ListNode *node3 = (struct ListNode *) malloc(sizeof(struct ListNode));

	head->val = 1;
	head->next = node1;

	node1->val = 2;
	node1->next = node2;

	node2->val = 3;
	node2->next = node3;

	node3->val = 4;
	node3->next = NULL;

	travel_nodes(head);

	struct ListNode *middle_node = middleNode(head);
	printf("The value of middle node is: %d\n", middle_node->val);

	return 0;
}