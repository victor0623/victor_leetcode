#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SUCCESS 1
#define ERROR -1
//#define DEBUG

enum {
	SMALL_BRACKET = 0,
	MEDIUM_BRACKET = 1,
	BIG_BRACKET = 2,
	DEFAULT_VALUE = -1
};

int isFull(int *top, int max_stack_size)
{
	if (*top == max_stack_size -1)
		return 1;
	else
		return 0;
}

int isEmpty(int *top)
{
	if (*top == -1)
		return 1;
	else
		return 0;
}

int push(int data, int *stack, int *top, int max_stack_size)
{
	if (isFull(top, max_stack_size) != 1) {
		(*top)++;
		stack[*top] = data;
		return SUCCESS;
	}
	else {
		printf("The stack is full!\n");
		return ERROR;
	}
}

int pop(int *stack, int *top, int type)
{
	int ret = ERROR;

	if (isEmpty(top) != 1) {
		if (stack[*top] == type) {
			stack[*top] = DEFAULT_VALUE;
			(*top)--;
			ret = SUCCESS;
		}
	}

	return ret;
}

void print_stack(int *stack, int max_stack_size)
{
	int i;
	for (i=0;i<max_stack_size;i++)
		printf("stack[%d]: %d\n", i, stack[i]);
}

void init_stack(int *stack, int max_stack_size)
{
	int i;
	for (i=0;i<max_stack_size;i++)
		stack[i] = DEFAULT_VALUE;
}

bool isValid(char* s) {
	int input_string_len = (int) strlen(s);
	int *stack = (int *) malloc(sizeof(int) * input_string_len);
	if (stack != NULL)
		init_stack(stack, input_string_len);

#ifdef DEBUG
	print_stack(stack, input_string_len);
#endif
	int top = -1;

#ifdef DEBUG
	printf("The input is:\n%s strlen:%d\n", s, input_string_len);
#endif
	if (*s == '\0')
		return true;

	if (input_string_len %2 == 1)
		return false;

	int ret;
	while (*s != '\0') {
#ifdef DEBUG
		printf("%c\n", *s);
#endif
		switch (*s) {
			case '(':
				ret = push(SMALL_BRACKET, stack, &top, input_string_len);
				break;
			case ')':
				ret = pop(stack, &top, SMALL_BRACKET);
				break;
			case '[':
				ret = push(MEDIUM_BRACKET, stack, &top, input_string_len);
				break;
			case ']':
				ret = pop(stack, &top, MEDIUM_BRACKET);
				break;
			case '{':
				ret = push(BIG_BRACKET, stack, &top, input_string_len);
				break;
			case '}':
				ret = pop(stack, &top, BIG_BRACKET);
				break;
			default:
				ret = ERROR;
				break;
		}
		if (ret == ERROR)
			return false;

		s++;
	}

#ifdef DEBUG
	printf("top=%d\n", top);
	print_stack(stack, input_string_len);
#endif

	if (isEmpty(&top))
		return true;
	else
		return false;
}

int main(void)
{
	char Input[] = "{[]}";
	//char Input[] = "";
	bool result = isValid(Input);

	printf("Input is:\n%s\n", Input);

	if (result)
		printf("Valid!\n");
	else
		printf("Invalid!\n");

	return 0;
}

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/