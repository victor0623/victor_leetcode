#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
 };

struct TreeNode * new_node(int data)
{
	struct TreeNode * Node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
	if (Node != NULL) {
		Node->val = data;
		Node->left = NULL;
		Node->right = NULL;
	}

	return Node;
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct TreeNode* node)
{
     if (node == NULL)
          return;
 
     /* first recur on left child */
     printInorder(node->left);
 
     /* then print the data of node */
     printf("%d ", node->val);  
 
     /* now recur on right child */
     printInorder(node->right);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;

	if (p != NULL && q != NULL) {
		if (p->val != q->val)
			return false;
	}
	else
		return false;

	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(void)
{
	struct TreeNode * p = NULL;
	struct TreeNode * q = new_node(0);
	/*
	struct TreeNode * p = new_node(1);
	p->left = new_node(2);
	p->right = new_node(3);

	struct TreeNode * q = new_node(1);
	q->left = new_node(2);
	q->right = new_node(3);
	*/

	printf("Inorder of p:\n");
	printInorder(p);
	printf("\n");

	printf("Inorder of q:\n");
	printInorder(q);
	printf("\n");

	bool result = isSameTree(p, q);
	if (result)
		printf("p and q are the same tree!\n");
	else
		printf("p and q are the different tree!\n");

	return 0;
}

/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/
