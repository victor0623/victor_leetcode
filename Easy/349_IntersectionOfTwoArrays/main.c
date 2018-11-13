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
		//printf("val:%d addr:%x ", n->val, (int) n);
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");
}

void addToList(struct ListNode *head, int value) {
	struct ListNode *n = head;
	struct ListNode *temp = malloc(sizeof(struct ListNode));

	if (temp != NULL) {
		temp->val = value;
		temp->next = NULL;
	}

	while (n->next != NULL)
		n = n->next;

	n->next = temp;
}

int isExistList(struct ListNode *head, int value) {
	struct ListNode *n = head;
	while (n != NULL) {
		if (n->val == value) {
			return 1;
		}
		n = n->next;
	}

	return 0;
}

void printArray(int *Array, int size)
{
	printf("Array of size %d is:\n", size);
	for (int i=0;i<size;i++)
		printf("%d ", Array[i]);
	printf("\n");
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	if (nums1Size == 0 || nums2Size == 0) {
		*returnSize = 0;
		return NULL;
	}

	int count = 0;
	int nums_size, marked_array_size, *marked_array, *nums_tobe_compared;
	int i, j;
	struct ListNode *i_list = NULL;

	if (nums1Size >= nums2Size) {
		marked_array_size = nums2Size;
		marked_array = nums2;
		nums_tobe_compared = nums1;
		nums_size = nums1Size;
	}
	else {
		marked_array_size = nums1Size;
		marked_array = nums1;
		nums_tobe_compared = nums2;
		nums_size = nums2Size;
	}

	for (i=0;i<marked_array_size;i++) {
#ifdef DEBUG
		printf("marked_array[%d]:%d\n", i, marked_array[i]);
#endif
		for (j=0;j<nums_size;j++) {
			if (marked_array[i] == nums_tobe_compared[j]) {
				if (isExistList(i_list, nums_tobe_compared[j]) == 1) {
					break;
				}
				else {
					if (i_list == NULL) {
						i_list = malloc(sizeof(struct ListNode));
						if (i_list != NULL) {
							i_list->val = marked_array[i];
							i_list->next = NULL;
						}
					}
					else {
						addToList(i_list, marked_array[i]);
					}

					count++;
					break;
				}
			}
		}
	}

#ifdef DEBUG
	printf("The list of count %d is:\n", count);
	printList(i_list);
#endif

	int *result = malloc(sizeof(int) * count);
	if (result != NULL) {
		struct ListNode *n = i_list;
		i = 0;
		while (n != NULL) {
			result[i] = n->val;
			i++;
			n = n->next;
		}
	}

	*returnSize = count;

	if (i_list != NULL)
		free(i_list);
	
	return result;
}

int main(void)
{
	int nums1[] = {4,7,9,7,6,7};
	int nums1_size = sizeof(nums1)/sizeof(int);

	int nums2[] = {5,0,0,6,1,6,2,2,4};
	int nums2_size = sizeof(nums2)/sizeof(int);

	printf("Input nums1:\n");
	printArray(nums1, nums1_size);

	printf("Input nums2:\n");
	printArray(nums2, nums2_size);

	int returnSize = 0;
	int *result = intersection(nums1, nums1_size, nums2, nums2_size, &returnSize);
	printf("The result is:\n");
	printArray(result, returnSize);

	return 0;
}

/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.
*/