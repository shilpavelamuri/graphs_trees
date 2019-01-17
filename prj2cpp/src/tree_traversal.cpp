/*
 * tree_traversal.cpp
 *
 *  Created on: Jan 16, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PKG_NAME_SIZE    10

struct Node {
	char data[PKG_NAME_SIZE];
	struct Node *next;
};

struct List {
	struct Node* list;// head of list
};

struct Graph {
	int numDepLists;
	struct List* arrayPkgs;
};

void traverse_subtree(struct Node* node)
{
	if (node == NULL)
		return;

	traverse_subtree(node->next);

	printf(" %s ", node->data);
}

void post_order_traversal(struct Graph* g)
{
	for (int i=g->numDepLists-1; i>0; i--)
	{
		traverse_subtree(g->arrayPkgs[i].list);
    }

	// root node
	printf(" %s ", g->arrayPkgs[0].list->data);
}

#if 0
int main()
{
	// fill the graph first
	struct Graph g;
	g.numDepLists = 3;
	g.arrayPkgs = (struct List*) calloc(g.numDepLists, sizeof(struct List));

    // populate one list
	g.arrayPkgs[0].list = (struct Node*) calloc(1, sizeof(struct Node));
	memcpy(g.arrayPkgs[0].list->data, "pkg1", PKG_NAME_SIZE);

	g.arrayPkgs[0].list->next = (struct Node*) calloc(1, sizeof(struct Node));
	memcpy(g.arrayPkgs[0].list->next->data, "pkg3", PKG_NAME_SIZE);

	g.arrayPkgs[0].list->next->next = (struct Node*) calloc(1, sizeof(struct Node));
	memcpy(g.arrayPkgs[0].list->next->next->data, "pkg5", PKG_NAME_SIZE);
	g.arrayPkgs[0].list->next->next->next = NULL;

	// populate 2nd list
	g.arrayPkgs[1].list = (struct Node*) calloc(1, sizeof(struct Node));
    memcpy(g.arrayPkgs[1].list->data, "pkg3", PKG_NAME_SIZE);

	g.arrayPkgs[1].list->next = (struct Node*) calloc(1, sizeof(struct Node));
	memcpy(g.arrayPkgs[1].list->next->data, "pkg4", PKG_NAME_SIZE);
	g.arrayPkgs[1].list->next->next = NULL;

	// populate 3rd list
	g.arrayPkgs[2].list = (struct Node*) calloc(1, sizeof(struct Node));
	memcpy(g.arrayPkgs[2].list->data, "pkg5", PKG_NAME_SIZE);

	g.arrayPkgs[2].list->next = (struct Node*) calloc(1, sizeof(struct Node));
	memcpy(g.arrayPkgs[2].list->next->data, "pkg2", PKG_NAME_SIZE);

	g.arrayPkgs[2].list->next->next = (struct Node*) calloc(1, sizeof(struct Node));
	memcpy(g.arrayPkgs[2].list->next->next->data, "pkg7", PKG_NAME_SIZE);

	g.arrayPkgs[2].list->next->next->next = NULL;

	printf("\n Populated input \n");

	// post-order traversal
    post_order_traversal(&g);
}

#endif
