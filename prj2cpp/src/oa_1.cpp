/*
 * oa_1.cpp
 *
 *  Created on: Jan 16, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <stdlib.h>

// struct serves as tree node and
// linked list struct
struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* Node(int data)
{
	struct Node* n = (struct Node*) calloc(1, sizeof(struct Node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void traverse_tree(struct Node* n, struct Node** listNode, struct Node** prevNode)
{
	if (n->left == NULL && n->right == NULL)
	{
		printf("\n Found leaf node:%d", n->data);

		// populate the linked list
		if (*listNode == NULL)
		{
			printf("\nCreating head");
			*listNode = Node(n->data);
			*prevNode = *listNode;
		}
		else
		{
			printf("\nAdding to list");
			(*prevNode)->right = Node(n->data);
			(*prevNode)->right->left = *prevNode;
			*prevNode = (*prevNode)->right;
		}

		return;
	}

	traverse_tree(n->left, listNode, prevNode);

	traverse_tree(n->right, listNode, prevNode);
}

struct Node* save_all_leaf_nodes_as_dbll(struct Node* root)
{
	// create head of Dbly Linked list
    struct Node *head = NULL, *prev = NULL;

    // traverse left sub-tree
    traverse_tree(root->left, &head, &prev);

    // traverse right sub-tree
    traverse_tree(root->right, &head, &prev);

    return head;
}

#if 0
// driver function
int main()
{
	// populate binary tree
    struct Node* root = Node(20);

    root->left = Node(9);
    root->right = Node(30);

    root->left->left = Node(8); // leaf node
    root->left->right = Node(11); // leaf node

    root->right->left = Node(25); // leaf node
    root->right->right = Node(31); // leaf node


    // save all leaf nodes as Dbly-Linked-List
    struct Node* head = save_all_leaf_nodes_as_dbll(root);

    // print out dbl linked list
    struct Node* ll = head;
    printf("\nList Output:\n");
    while(ll != NULL)
    {
        printf(" %d ", ll->data);
        ll = ll->right;
    }
}
#endif
