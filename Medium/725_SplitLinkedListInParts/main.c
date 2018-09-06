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
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize) {
	*returnSize = k;
	struct ListNode *n = root;
	int len = 0;
	while (n != NULL) {
		len++;
		n = n->next;
	}

	int num_per_group = len / k;
	int num_bonus = len % k;
	int total_num;

	n = root;

	int i, j;
	struct ListNode ** result = (struct ListNode **) malloc(sizeof(struct ListNode *) * k);
	if (result != NULL) {
		for (i=0;i<k;i++) {
			result[i] = (struct ListNode *) malloc(sizeof(struct ListNode));
			result[i] = NULL;

			if (i < num_bonus)
				total_num = num_per_group + 1;
			else
				total_num = num_per_group;
            
            		struct ListNode * c;
			for (j=0;j<total_num;j++) {
				struct ListNode *new_node = malloc(sizeof(struct ListNode));
				new_node->val = n->val;
				new_node->next =NULL;
				if (result[i] == NULL) {
                    			result[i] = new_node;
                    			c = result[i];
                		}
				else {
					c->next = new_node;
					c = c->next;
				}

				n = n->next;
			}
		}
	}

	return result;
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
	node3->val = 3;
	node3->next = NULL;
	/*
	node4->val = 1;
	node4->next = NULL;
	*/

	printf("The input is:\n");
	printList(head);

	int k = 5;
	int returnSize;
	struct ListNode ** result = splitListToParts(head, k, &returnSize);
	printf("The result with k=%d is:\n", k);
	for (int i=0;i<returnSize;i++) {
		printf("List %d:\n", i+1);
		printList(result[i]);
	}

	return 0;
}

/*
Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input: 
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
Example 2:
Input: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
*/