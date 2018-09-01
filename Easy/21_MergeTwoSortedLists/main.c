#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

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

void insert_node_end(struct ListNode *head, int item)
{
	struct ListNode *n = head;
	struct ListNode *inserted_node = malloc(sizeof(struct ListNode));
	
	//find the end node
	while (n->next != NULL) {
		n = n->next;
	}
	
	n->next = inserted_node;
	inserted_node->val = item;
	inserted_node->next = NULL;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	int isFirstNode = 1;
	int l1_val, l2_val, is_l1_null, is_l2_null;
	struct ListNode *result = malloc(sizeof(struct ListNode));
	int count = 0;

	if (l1 == NULL && l2 == NULL)
		return NULL;

	if (result != NULL) {
		while (1) {
			if (l1 == NULL && l2 == NULL) 
				break;

#ifdef DEBUG
			printf("count:%d\n", count);
#endif

			if (l1 != NULL) {
				l1_val = l1->val;
				is_l1_null = 0;
			}
			else
				is_l1_null = 1;

			if (l2 != NULL) {
				l2_val = l2->val;
				is_l2_null = 0;
			}
			else
				is_l2_null = 1;

			if (isFirstNode == 1) {
				if (is_l1_null == 0 && is_l2_null == 0) {
					if (l1_val <= l2_val) {
						result->val = l1_val;
						result->next = NULL;
						l1 = l1->next;
					}
					else {
						result->val = l2_val;
						result->next = NULL;
						l2 = l2->next;
					}
				}
				else if (is_l1_null == 0 && is_l2_null == 1) {
					result->val = l1_val;
					result->next = NULL;
					l1 = l1->next;
				}
				else if (is_l1_null == 1 && is_l2_null == 0) {
					result->val = l2_val;
					result->next = NULL;
					l2 = l2->next;
				}

				isFirstNode = 0;
			}
			else {
				if (is_l1_null == 0 && is_l2_null == 0) {
					if (l1_val <= l2_val) {
						insert_node_end(result, l1_val);
						l1 = l1->next;
					}
					else {
						insert_node_end(result, l2_val);
						l2 = l2->next;
					}
				}
				else if (is_l1_null == 0 && is_l2_null == 1) {
					insert_node_end(result, l1_val);
					l1 = l1->next;
				}
				else if (is_l1_null == 1 && is_l2_null == 0) {
					insert_node_end(result, l2_val);
					l2 = l2->next;
				}
			}
			count++;
		}
	}
	
	return result;
}

struct ListNode* mergeTwoLists2(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL && l2 == NULL)
		return NULL;

	struct ListNode *node = malloc(sizeof(struct ListNode));

	if (l1 != NULL && l2 != NULL) {
		if (l1->val <= l2->val) {
			node->val = l1->val;
			l1 = l1->next;
		}
		else {
			node->val = l2->val;
			l2 = l2->next;
		}
	}
	else if (l1 != NULL && l2 == NULL) {
		node->val = l1->val;
		l1 = l1->next;
	}
	else if (l1 == NULL && l2 != NULL) {
		node->val = l2->val;
		l2 = l2->next;
	}

	node->next = NULL;
	struct ListNode *temp = node;

	while (l1 != NULL || l2 != NULL) {
		struct ListNode *inserted_node = malloc(sizeof(struct ListNode));
		if (l1 != NULL && l2 != NULL) {
			if (l1->val <= l2->val) {
				inserted_node->val = l1->val;
				l1 = l1->next;
			}
			else {
				inserted_node->val = l2->val;
				l2 = l2->next;
			}
		} else if (l1 != NULL && l2 == NULL) {
			inserted_node->val = l1->val;
			l1 = l1->next;
		} else if (l1 == NULL && l2 != NULL) {
			inserted_node->val = l2->val;
			l2 = l2->next;
		}

		printf("inserted_node->val:%d\n", inserted_node->val);
		inserted_node->next = NULL;
		node->next = inserted_node;
		printf("node->val:%d\n", node->val);
		node = node->next;
	}

	return temp;
}

int main(void)
{
	struct ListNode *l1 = malloc(sizeof(struct ListNode));
	struct ListNode *l2 = malloc(sizeof(struct ListNode));

	l1->val = 1;
	l1->next = NULL;
	insert_node_end(l1, 2);
	insert_node_end(l1, 4);

	l2->val = 1;
	l2->next = NULL;
	insert_node_end(l2,3);
	insert_node_end(l2,4);

	printf("List1:\n");
	travel_nodes(l1);
	printf("List2:\n");
	travel_nodes(l2);

	struct ListNode *result = mergeTwoLists2(l1, l2);
	printf("Merged list:\n");
	travel_nodes(result);
	
	return 0;
}

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
