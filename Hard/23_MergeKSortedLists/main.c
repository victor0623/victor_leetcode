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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	if (lists == NULL || listsSize <= 0)
		return NULL;
	
	struct ListNode* head = NULL;
	struct ListNode* current = NULL;
	int i, count, min, min_index;

	while (1) {
		struct ListNode* node = NULL;
		count = 0;
		min_index = -1;
		for (i=0;i<listsSize;i++) {
			if (lists[i] != NULL) {
				count++;

				if (count == 1) {
					min = lists[i]->val;
					min_index = i;
				}
				else if (count > 1) {
					if (lists[i]->val < lists[min_index]->val) {
						min = lists[i]->val;
						min_index = i;
					}
				}
			}
		}

		//printf("count=%d\n", count);

		if (count == 0)
			break;

		if (count > 0) {
			node = lists[min_index];
			if (count > 1) {
				lists[min_index] = lists[min_index]->next;
				node->next = NULL;
			}

			if (head == NULL) {
				head = node;
				current = node;
			}
			else {
				current->next = node;
				current = current->next;
			}
		}

		if (count == 1)
			break;
	}
	
	return head;
}

int main(void)
{
	int listsSize = 3;
	struct ListNode ** Input = (struct ListNode **) malloc(sizeof(struct ListNode *) * listsSize);
	for (int i=0;i<listsSize;i++) {
		*(Input+i) = (struct ListNode *) malloc(sizeof(struct ListNode));
	}

	struct ListNode * l1_node2 = malloc(sizeof(struct ListNode));
	struct ListNode * l1_node3 = malloc(sizeof(struct ListNode));
	struct ListNode * l2_node2 = malloc(sizeof(struct ListNode));
	struct ListNode * l2_node3 = malloc(sizeof(struct ListNode));
	struct ListNode * l3_node2 = malloc(sizeof(struct ListNode));

	Input[0]->val = 1;
	Input[0]->next = l2_node2;
	l2_node2->val = 3;
	l2_node2->next = l2_node3;
	l2_node3->val = 4;
	l2_node3->next = NULL;

	Input[1]->val = 1;
	Input[1]->next = l1_node2;
	l1_node2->val = 4;
	l1_node2->next = l1_node3;
	l1_node3->val = 5;
	l1_node3->next = NULL;

	Input[2]->val = 2;
	Input[2]->next = l3_node2;
	l3_node2->val = 6;
	l3_node2->next = NULL;

	for (int i=0;i<listsSize;i++) {
		printf("List %d:\n", i+1);
		printList(Input[i]);
	}

	struct ListNode * result = mergeKLists(Input, listsSize);
	printf("The result is:\n");
	printList(result);

	return 0;
}

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
