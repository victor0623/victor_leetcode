#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct {
	struct ListNode *head;
	struct ListNode *tail;
	int length;
} MyLinkedList;

void printList(MyLinkedList* obj) {
	struct ListNode *node = obj->head;
	printf("The list with length %d is: ", obj->length);
	while (node != NULL) {
		printf("%d ", node->val);
		node = node->next;
	}
	printf("\n");
}

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
	MyLinkedList * obj = malloc(sizeof(MyLinkedList));
	obj->length = 0;
	obj->head = NULL;
	obj->tail = NULL;

	return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
#ifdef DEBUG
	printf("index:%d obj->length:%d\n", index, obj->length);
#endif
	if (index >= obj->length)
		return -1;

	int count = 0, value = -1;
	struct ListNode * node = obj->head;
	while (node != NULL) {
		if (count == index) {
			value = node->val;
			break;
		}
		count++;
		node = node->next;
	}

	return value;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	struct ListNode * new_node = malloc(sizeof(struct ListNode));
	if (new_node != NULL) {
		new_node->val = val;
		new_node->next = obj->head;
		if (obj->head == NULL)
			obj->tail = new_node;
		obj->head = new_node;
		
		obj->length = obj->length + 1;
	}
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	struct ListNode * new_node = malloc(sizeof(struct ListNode));
	if (new_node != NULL) {
		new_node->val = val;
		new_node->next = NULL;

		if (obj->tail == NULL) {
			obj->head = new_node;
		}
		else {
			obj->tail->next = new_node;
		}
		obj->tail = new_node;
		obj->length = obj->length + 1;
	}
}

void insertNodeAtMiddle(MyLinkedList* obj, int index, int val) {
	int count = 0;
	struct ListNode * node = obj->head;
	struct ListNode * previous = NULL;
	struct ListNode * new_node = malloc(sizeof(struct ListNode));
	if (new_node != NULL) {
		new_node->val = val;
		while (node != NULL) {
			if (count == index) {
				new_node->next = node;
				previous->next = new_node;
				obj->length = obj->length + 1;
				break;
			}
			previous = node;
			node = node->next;
			count++;
		}
	}
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
#ifdef DEBUG
	printf("length of list is:%d\n", obj->length);
#endif
	
	if (index <= obj->length) {
		if (index == obj->length) {
			myLinkedListAddAtTail(obj, val);
		}
		else if (index == 0){
			myLinkedListAddAtHead(obj, val);
		}
		else {
			insertNodeAtMiddle(obj, index, val);
		}
	}
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	if (index >= obj->length)
		return;

	int count = 0;
	struct ListNode * node = obj->head;
	struct ListNode * previous = NULL;

	while (node != NULL) {
		if (count == index) {
			struct ListNode * temp = node;
			if (count == 0) {
				obj->head = node->next;
			}
			else if (count == obj->length-1) {
				previous->next = node->next;
				obj->tail = previous;
			}
			else {
				previous->next = node->next;
			}

			free(temp);
			obj->length = obj->length - 1;
			break;
		}

		count++;
		previous = node;
		node = node->next;
	}
}

void myLinkedListFree(MyLinkedList* obj) {
	if (obj != NULL) {
		struct ListNode * node = obj->head;
		struct ListNode * temp;

		while (node != NULL) {
			temp = node;
			node = node->next;
			free(temp);
		}

		free(obj);
	}
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

int main(void)
{
	int ret;
	MyLinkedList *obj= myLinkedListCreate();
	myLinkedListAddAtHead(obj, 8);
	printList(obj);
	ret = myLinkedListGet(obj, 1);
	printf("ret = %d\n", ret);
	myLinkedListAddAtTail(obj, 81);
	printList(obj);
	myLinkedListDeleteAtIndex(obj, 2);
	printList(obj);
	myLinkedListAddAtHead(obj, 26);
	printList(obj);
	myLinkedListDeleteAtIndex(obj, 2);
	printList(obj);
	ret = myLinkedListGet(obj, 1);
	printf("ret = %d\n", ret);
	myLinkedListAddAtTail(obj, 24);
	printList(obj);
	myLinkedListAddAtHead(obj, 15);
	printList(obj);
	myLinkedListAddAtTail(obj, 0);
	printList(obj);
	myLinkedListAddAtTail(obj, 13);
	printList(obj);
	myLinkedListAddAtTail(obj, 1);
	printList(obj);
	myLinkedListAddAtIndex(obj, 6, 33);
	printList(obj);
	ret = myLinkedListGet(obj, 6);
	printf("ret = %d\n", ret);


	/*
	myLinkedListAddAtHead(obj, 1);
	printList(obj);
	myLinkedListAddAtTail(obj, 3);
	printList(obj);
	myLinkedListAddAtIndex(obj, 1, 2);
	printList(obj);

	ret = myLinkedListGet(obj, 1);
	printf("ret = %d\n", ret);

	myLinkedListDeleteAtIndex(obj, 1);
	printList(obj);

	ret = myLinkedListGet(obj, 1);
	printf("ret = %d\n", ret);

	myLinkedListFree(obj);
	*/

	/*
	myLinkedListAddAtIndex(obj, 0, 1010);
	printList(obj);
	myLinkedListAddAtIndex(obj, 1, 55);
	printList(obj);

	int ret = myLinkedListGet(obj, 0);
	printf("ret = %d\n", ret);

	myLinkedListDeleteAtIndex(obj, 0);
	printList(obj);
	*/

	return 0;
}


/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

/*
Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
addAtTail(val) : Append a node of value val to the last element of the linked list.
addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
Example:

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
Note:

All values will be in the range of [1, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in LinkedList library.
*/
