/*
 * oa_5.cpp

 *
 *  Created on: Jan 18, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *right, *left;
};

bool isBalanced(struct Node* node)
{
	if (node == NULL) return -1;

	bool bResult = false;
	static int prev_ht = 0;
	static int ht = 0;

    if (node->left)
    {
    	ht++;

        bResult = isBalanced(node->left);
        if (!bResult)
        {
       	    return bResult;
        }
    }

    if (node->right)
    {
    	ht++;

        bResult = isBalanced(node->right);
        if (!bResult)
        {
    	    return bResult;
        }
    }

    if (node->left == NULL && node->right == NULL)
    {
    	if (0 == prev_ht)
    	{
    		prev_ht = ht;
    	    printf("\nsaving prev_ht for the first leaf node found: %d", prev_ht);
    	}
    	else
    	{
//    		printf("\ncurrent height computed for non-first leaf node: %d", ht);

    		// compare current height to previous height for leaf node
    		if (abs(prev_ht - ht) > 1)
    		{
//                printf("\n height is : %d", abs(prev_ht - ht));
    			return false;
    		}
    		else
    		{
    			printf("\n saving ht as prev_ht for future leaf node reference");
    			prev_ht = (prev_ht > ht)?prev_ht:ht;
    		}
    	}
    }

    ht--;
	return true;
}

struct Node* createNode(int data)
{
    struct Node* n = (struct Node*) calloc(1, sizeof(struct Node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

int main()
{
	struct Node* root = createNode(90);

	root->left = createNode(80);
	root->right = createNode(100);

	root->left->left = createNode(70);
	root->left->right = createNode(85);
	root->left->left->left = createNode(60);
	root->left->left->left->left = createNode(50);

	root->right->left = createNode(95);
	root->right->right = createNode(105);

	printf("\nResult: isBalanced?: %d", isBalanced(root));
}
