#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef struct {
	int top;
	int min_top;
	int size;
	int *entries;
	int *min_entries;
	
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
	MinStack *stack = (MinStack *) malloc(sizeof(MinStack));
	stack->top = -1;
	stack->size = maxSize;
	stack->entries = (int *) malloc(sizeof(int) * maxSize);
	stack->min_top = -1;
	stack->min_entries = (int *) malloc(sizeof(int) * maxSize);

	return stack;
}

void minStackPush(MinStack* obj, int x) {
	if (obj->top == MAX_STACK_SIZE-1) {
		printf("Stack overflow!\n");
	}

	obj->top = obj->top + 1;
	obj->entries[obj->top] = x;

	if (obj->min_top == -1) {
		obj->min_top = obj->min_top + 1;
		obj->min_entries[obj->min_top] = x;
	} 
	else {
		if (x <= obj->min_entries[obj->min_top]) {
			obj->min_top = obj->min_top + 1;
			obj->min_entries[obj->min_top] = x;
		}
	}
}

void minStackPop(MinStack* obj) {
	if (obj->top == -1) {
		printf("Stack underflow!\n");
		return;
	}

	if (obj->entries[obj->top] == obj->min_entries[obj->min_top])
		obj->min_top = obj->min_top - 1;

	obj->top = obj->top - 1;
}

int minStackTop(MinStack* obj) {
	if (obj->top == -1) {
		printf("Stack underflow!\n");
		return 0;
	}
	
	return obj->entries[obj->top];
}

int minStackGetMin(MinStack* obj) {
	return obj->min_entries[obj->min_top];
}

void minStackFree(MinStack* obj) {
	if (obj->entries != NULL)
		free(obj->entries);

	if (obj->min_entries != NULL)
		free(obj->min_entries);

	if (obj != NULL)
		free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */

int main(void)
{
	MinStack *s = minStackCreate(MAX_STACK_SIZE);
	printf("s->top:%d\n", s->top);
	minStackPush(s, -2);
	printf("s->top:%d\n", s->top);
	minStackPush(s, 0);
	printf("s->top:%d\n", s->top);
	minStackPush(s, -3);
	printf("Get min:%d\n", minStackGetMin(s));
	printf("s->top:%d\n", s->top);
	printf("Get top:%d\n", minStackTop(s));
	minStackPop(s);
	printf("s->top:%d\n", s->top);
	printf("Get top:%d\n", minStackTop(s));
	printf("Get min:%d\n", minStackGetMin(s));
	return 0;
}

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
