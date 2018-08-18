#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode {
	int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int height(struct TreeNode* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
        printf("lheight:%d\trheight:%d\n", lheight, rheight);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
	struct TreeNode * result = t1;

	//printf("The height of T1 is:%d\n", height(t1));
	//printf("THe height of T2 is:%d\n", height(t2));

	if (t1 == NULL)
		t1->val = t1->val + t2->val;

	if (t1 == NULL)
		return mergeTrees(t1->left, t2->left);
	return result;
}

struct TreeNode * newNode(int data)
{
	struct TreeNode * node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
	node->val = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void printPostorder(struct TreeNode * node)
{
	if (node == NULL)
		return;
	
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d\n", node->val);
}

void printPreorder(struct TreeNode * node)
{
	if (node == NULL)
		return;

	printf("%d\n", node->val);
	printPreorder(node->left);
	printPreorder(node->right);
}

void printInorder(struct TreeNode * node)
{
	if (node == NULL)
		return;

	printInorder(node->left);
	printf("%d\n", node->val);
	printInorder(node->right);
}

int main(void)
{
	/*
	struct TreeNode * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);

	printf("Inorder Traversal:\n");
	printInorder(root);

	printf("Preorder Traversal:\n");
	printPreorder(root);

	printf("Postorder Traversal:\n");
	printPostorder(root);
	*/

	struct TreeNode * Tree1 = newNode(1);
	Tree1->left = newNode(3);
	Tree1->right = newNode(2);
	Tree1->left->left = newNode(5);

	struct TreeNode * Tree2 = newNode(2);
	Tree2->left = newNode(1);
	Tree2->right = newNode(3);
	Tree2->left->right = newNode(4);
	Tree2->right->right = newNode(7);

	printf("Inorder Traversal of Tree1:\n");
	printInorder(Tree1);

	printf("Inorder Traversal of Tree2:\n");
	printInorder(Tree2);

	struct TreeNode * mergedTree = mergeTrees(Tree1, Tree2);
	printf("Inorder Traversal of mergeing T1 and T2:\n");
	printInorder(mergedTree);

	return 0;
}