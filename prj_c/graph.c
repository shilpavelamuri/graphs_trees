/*
 * graph.c
 *
 *  Created on: Jan 4, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node* next;
};

struct adj_list {
	struct node* nodes;
};

struct graph {
	int num_nodes;
	struct adj_list* array_of_vertices;
};

void addToGraph(struct adj_list* list, int src, int num_dest, int* dest)
{
	struct node *node = NULL, *prev_node = NULL;


	// populate head of list with 'root' node
	list->nodes = (struct node*) calloc(1, sizeof(struct node));
	list->nodes->val = src;
    prev_node = list->nodes;

    printf("\n for root: %d, num of dest items:%d", src, num_dest);
	for (int i=0; i<num_dest; i++)
	{
	    // adjacent node
		node = (struct node*) calloc(1, sizeof(struct node));
		node->val = dest[i];
	    node->next = NULL;
	    // link the adjacent node to the prev node
	    prev_node->next = node;

	    // update the prev_node tracker
	    prev_node = node;
	}
}

void print_graph(struct graph* g)
{
	struct node* node = NULL;

    for (int i=0; i<g->num_nodes; i++)
    {
    	printf("\n");
    	node = g->array_of_vertices[i].nodes;
    	while (node)
    	{
    		printf("%d ", node->val);

    		node = node->next;
    	}
    }
}

int main()
{
	struct graph g;
	int dest[4] = {0};

    // initialize graph
	g.num_nodes = 5;
	g.array_of_vertices = (struct adj_list*) calloc(5, sizeof(struct adj_list));

	// populate graph
    dest[0] = 8;
    addToGraph(&g.array_of_vertices[0], 5, 1, dest);

    dest[0] = 5;
    dest[1] = 10;
    dest[2] = 12;
	addToGraph(&g.array_of_vertices[1], 8, 3, dest);

	dest[0] = 5;
	dest[1] = 8;
	dest[2] = 20;
	addToGraph(&g.array_of_vertices[2], 12, 3, dest);

	dest[0] = 8;
	addToGraph(&g.array_of_vertices[3], 10, 1, dest);

	dest[0] = 12;
	addToGraph(&g.array_of_vertices[4], 20, 1, dest);

    // print graph
	print_graph(&g);
}
