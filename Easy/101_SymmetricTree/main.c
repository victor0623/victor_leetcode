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

bool isSym(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return true;

	if (p != NULL && q != NULL) {
		if (p->val != q->val)
			return false;
	}
	else
		return false;

	return isSym(p->left, q->right) && isSym(p->right, q->left);
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSymmetric(struct TreeNode* root) {
	return isSym(root, root);
}

int main(void)
{
	struct TreeNode * root = new_node(1);
	root->left = new_node(2);
	root->right = new_node(2);
	root->left->left = new_node(3);
	root->left->right = new_node(4);
	root->right->left = new_node(4);
	root->right->right = new_node(3);

	printf("Inorder:\n");
	printInorder(root);
	printf("\n");

	bool result = isSymmetric(root);
	if (result)
		printf("The tree is symmetric!\n");
	else
		printf("The tree is not symmetric\n");

	return 0;
}


/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/
