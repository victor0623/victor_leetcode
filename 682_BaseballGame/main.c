#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPS_LENGTH 10
#define MAX_STACK_SIZE 1000
#define STACK_DEFAULT_VALUE -100000000

//#define DEBUG

typedef struct stack {
	int top;
	int data[MAX_STACK_SIZE];
} STACK;

int isFull(STACK *s)
{
	if (s->top == MAX_STACK_SIZE - 1)
		return 1;
	else
		return 0;
}

int isEmpty(STACK *s)
{
	if (s->top == - 1)
		return 1;
	else
		return 0;
}

void push_stack(STACK *s, int data_item)
{
	if (isFull(s) != 1) {
		s->top = s->top + 1;
		s->data[s->top] = data_item;
	}
	else {
		printf("The stack is full!\n");
	}
}

int pop_stack(STACK *s)
{
	int ret = -1;
	if (isEmpty(s) != 1) {
		ret = s->data[s->top];
		s->top = s->top - 1;
	}
	else {
		printf("The stack is empty!\n");
	}

	return ret;
}

void init_stack(STACK *s)
{
	int i;
	s->top = -1;
	for (i=0;i<MAX_STACK_SIZE;i++) 
		s->data[i] = STACK_DEFAULT_VALUE;
}

void print_stack(STACK *s)
{
	int i;
	for (i=0;i<=s->top;i++) {
		if (s->data[i] == STACK_DEFAULT_VALUE)
			break;
		printf("s[%d]: %d\n", i, s->data[i]);
	}
}

int calPoints(char** ops, int opsSize) {
	int i;
	int score_sum = 0;
	char op, *pEnd;;
	int parsed_num, last_valid_score, curr_obtained_score;

	STACK *valid_op_stack = malloc(sizeof(STACK) * MAX_STACK_SIZE);
	init_stack(valid_op_stack);
	
	for (i=0;i<opsSize;i++) {
		char temp_ops[OPS_LENGTH];
		strcpy(temp_ops, *(ops+i));
		int len = (int) strlen(temp_ops);

#ifdef DEBUG
		printf("ops[%d]:%s strlen:%d\n", i, temp_ops, len);
#endif
		op = temp_ops[0];
		//if (!strcpy(temp_ops, "C")) {
		if (op == 'C') {
#ifdef DEBUG
			printf("detect C\n");
#endif
			
			int pop_item = pop_stack(valid_op_stack);
#ifdef DEBUG
			printf("pop_item:%d\n", pop_item);
#endif
			score_sum -= pop_item;
		} else if (op == 'D') {
#ifdef DEBUG
			printf("detect D\n");
#endif
			last_valid_score = valid_op_stack->data[valid_op_stack->top];
#ifdef DEBUG
			printf("last_valid_score:%d\n", last_valid_score);
#endif
			curr_obtained_score = last_valid_score*2;
			score_sum += curr_obtained_score;
			push_stack(valid_op_stack, curr_obtained_score);
		} else if (op == '+') {
#ifdef DEBUG
			printf("detect +\n");
#endif
			if (valid_op_stack->top >= 1) {
				curr_obtained_score = valid_op_stack->data[valid_op_stack->top] + valid_op_stack->data[valid_op_stack->top-1];
				score_sum += curr_obtained_score;
				push_stack(valid_op_stack, curr_obtained_score);
			}
		} else {
			parsed_num = (int) strtol(temp_ops,&pEnd,10);
#ifdef DEBUG
			printf("detect number %d\n", parsed_num);
#endif

			push_stack(valid_op_stack, parsed_num);
			score_sum += parsed_num;
		}
#ifdef DEBUG
		printf("round%d: score:%d\n", i, score_sum);
		printf("stack:\n");
		print_stack(valid_op_stack);
#endif
	}

	return score_sum;
}

int main(void)
{
	//char *Input[] = {"5","2","C","D","+"};
	char *Input[] = {"5","-2","4","C","D","9","+","+"};
	int opsSize = 8;

	for (int i=0;i<opsSize;i++)
		printf("Input[%d]: %s\n", i, *(Input+i));
	
	int score = calPoints(Input, opsSize);
	printf("The final score is:%d\n", score);
	return 0;
}

/*
You're now a baseball game point recorder.

Given a list of strings, each string can be one of the 4 following types:

Integer (one round's score): Directly represents the number of points you get in this round.
"+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
"D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
"C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
Each round's operation is permanent and could have an impact on the round before and the round after.

You need to return the sum of the points you could get in all the rounds.

Example 1:
Input: ["5","2","C","D","+"]
Output: 30
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get 2 points. The sum is: 7.
Operation 1: The round 2's data was invalid. The sum is: 5.  
Round 3: You could get 10 points (the round 2's data has been removed). The sum is: 15.
Round 4: You could get 5 + 10 = 15 points. The sum is: 30.
Example 2:
Input: ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation: 
Round 1: You could get 5 points. The sum is: 5.
Round 2: You could get -2 points. The sum is: 3.
Round 3: You could get 4 points. The sum is: 7.
Operation 1: The round 3's data is invalid. The sum is: 3.  
Round 4: You could get -4 points (the round 3's data has been removed). The sum is: -1.
Round 5: You could get 9 points. The sum is: 8.
Round 6: You could get -4 + 9 = 5 points. The sum is 13.
Round 7: You could get 9 + 5 = 14 points. The sum is 27.
Note:
The size of the input list will be between 1 and 1000.
Every integer represented in the list will be between -30000 and 30000.
*/
