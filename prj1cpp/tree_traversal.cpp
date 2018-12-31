/*
 * tree_traversal.cpp
 *
 *  Created on: Dec 28, 2018
 *      Author: shilpakalla
 */

#include <stdio.h>


int main()
{
	Node *root, *node;
	Node *l, *r;

	// fill in the tree
    root = new Node(50);
    if (root == NULL) return -1;
    root->left[0] = new Node(45);
    if (root->left[0] == NULL) return -1;
    root->right[0] = new Node(60);
    if (root->right[0] == NULL) return -1;

    l = root->left[0];
    r = root->right[0];

    // go down left child
    l->left[0] = new Node(40);
    if (l->left[0] == NULL) return -1;
    l->right[0] = new Node(49);
    if (l->right[0] == NULL) return -1;

    // go down first right child
    r->left[0] = new Node(55);
    if (r->left[0] == NULL) return -1;
    r->right[0] = new Node(80);
    if (r->right[0] == NULL) return -1;


	// in-order traversal
    // left->root->right
    node = root;

}

