#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE_MAX 250

//#define DEBUG

struct node {
	char words[ARRAY_SIZE_MAX];
	struct node *next;
};

int travel_nodes(struct node *head)
{
	int node_num = 0;
	struct node *n = head;
	
	while (n != NULL) {
		if (n->words[0] == '\0')
			break;
#ifdef DEBUG
		printf("words:%s\n", n->words);
#endif
		n = n->next;
		node_num++;
	}

	free(n);

	return node_num;
}

void insert_node_end(struct node *head, char * item)
{
	struct node *n = head;
	struct node *inserted_node = malloc(sizeof(struct node));
	if (inserted_node == NULL)
		return;
	
	//find the end node
	while (n->next != NULL) {
		n = n->next;
	}
	
	n->next = inserted_node;
	strcpy(inserted_node->words, item);
	inserted_node->next = NULL;
}

void parseString(char *S, struct node **head)
{
	char *ptr_s = S;
	char temp_s[ARRAY_SIZE_MAX] = "";
	int i = 0;
	int isEmpty = 1;
	while (1) {
		//printf("c:%c\n", *ptr_s);
		if (*ptr_s == ' ' || *ptr_s == '\0') {
#ifdef DEBUG
			printf("temp_s:%s strlen:%d\n", temp_s, (int) strlen(temp_s));
#endif

			if (isEmpty) {
				(*head)->words[0] = '\0';
				temp_s[i+1] = '\0';
				strcpy((*head)->words, temp_s);
				(*head)->next = NULL;
				isEmpty = 0;
			}
			else {
				temp_s[i+1] = '\0';
				insert_node_end(*head, temp_s);
			}

			memset(temp_s, '\0', sizeof(temp_s));
			i = 0;
		}
		else {
			temp_s[i] = *ptr_s;
			i++;
		}

		if (*ptr_s == '\0')
			break;

		ptr_s++;
	} 

	return;
}

int word_found_count(struct node *head, char * word)
{
	int found_count = 0;

	struct node *n = head;
	while (n != NULL) {
		if (!strcmp(n->words, word))
			found_count++;

		n = n->next;
	}

	return found_count;
}

void findUniqueWords(struct node *head_A, struct node *head_B, struct node **head_match)
{
	char temp_s[ARRAY_SIZE_MAX] = "";
	int found_countA = 0, found_countB = 0;
	int isEmpty = 1;

	(*head_match)->words[0] = '\0';

	struct node *n_A = head_A;
	while (n_A != NULL) {
		strcpy(temp_s, n_A->words);
		found_countA = word_found_count(head_A, temp_s);
		found_countB = word_found_count(head_B, temp_s);
		if ((found_countA+found_countB) == 1) {
#ifdef DEBUG
			printf("found word:%s\n",temp_s );
#endif
			if (isEmpty == 1) {
				strcpy((*head_match)->words, temp_s);
				(*head_match)->next = NULL;
				isEmpty = 0;
			}
			else {
				insert_node_end(*head_match, temp_s);
			}	
		}

		memset(temp_s, '\0', sizeof(temp_s));
		n_A = n_A->next;
	}

	struct node *n_B = head_B;
	while (n_B != NULL) {
		strcpy(temp_s, n_B->words);
		found_countA = word_found_count(head_A, temp_s);
		found_countB = word_found_count(head_B, temp_s);
		if ((found_countA+found_countB) == 1) {
#ifdef DEBUG
			printf("found word:%s\n",temp_s );
#endif
			if (isEmpty == 1) {
				strcpy((*head_match)->words, temp_s);
				(*head_match)->next = NULL;
				isEmpty = 0;
			}
			else {
				insert_node_end(*head_match, temp_s);
			}	
		}

		memset(temp_s, '\0', sizeof(temp_s));
		n_B = n_B->next;
	}

	free(n_B);
	
	return;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** uncommonFromSentences(char* A, char* B, int* returnSize) {
	struct node *head_A = (struct node *) malloc(sizeof(struct node));
	if (head_A == NULL)
		return NULL;

	struct node *head_B = (struct node *) malloc(sizeof(struct node));
	if (head_B == NULL)
		return NULL;

	parseString(A, &head_A);
#ifdef DEBUG
	int count_A = travel_nodes(head_A);
	printf("count_A=%d\n", count_A);
#endif

	parseString(B, &head_B);
#ifdef DEBUG
	int count_B = travel_nodes(head_B);
	printf("count_B=%d\n", count_B);
#endif

	struct node *head_matched = (struct node *) malloc(sizeof(struct node));
	if (head_matched == NULL)
		return NULL;
	
	findUniqueWords(head_A, head_B, &head_matched);
	int count_matched = travel_nodes(head_matched);
#ifdef DEBUG
	printf("count_matched=%d\n", count_matched);
#endif

	free(head_A);
	free(head_B);

	*returnSize = count_matched;

	if (count_matched == 0)
		return NULL;

	char **result = (char **) malloc(sizeof(char *) * count_matched);
	int i;
	for (i=0;i<count_matched;i++) {
		*(result+i) = (char *) malloc(sizeof(char) * ARRAY_SIZE_MAX);
		strcpy(*(result+i), head_matched->words);
		head_matched = head_matched->next;
	}

	*returnSize = count_matched;

	free(head_matched);
	
    	return result;
}

int main(void)
{
	char A[ARRAY_SIZE_MAX] = "this apple is sweet";
	char B[ARRAY_SIZE_MAX] = "this apple is sour";
	//char A[ARRAY_SIZE_MAX] = "apple apple";
	//char B[ARRAY_SIZE_MAX] = "banana";	
	//char A[ARRAY_SIZE_MAX] = "fd kss fd";
	//char B[ARRAY_SIZE_MAX] = "fd fd kss";

	printf("A:%s\n", A);
	printf("B:%s\n", B);

	char *p_A = A;
	char *p_B = B;
	int returnSize;

	char **result = uncommonFromSentences(p_A, p_B, &returnSize);
	printf("Number of uncommon words:%d\n", returnSize);
	int i;
	for (i=0;i<returnSize;i++)
		printf("%s\n", *(result+i));

	return 0;
}

/*
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Return a list of all uncommon words. 

You may return the list in any order.

 

Example 1:

Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]
Example 2:

Input: A = "apple apple", B = "banana"
Output: ["banana"]
 

Note:

0 <= A.length <= 200
0 <= B.length <= 200
A and B both contain only spaces and lowercase letters.
*/