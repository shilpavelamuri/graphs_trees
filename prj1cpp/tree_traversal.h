/*
 * tree_traversal.h
 *
 *  Created on: Dec 28, 2018
 *      Author: shilpakalla
 */

#ifndef TREE_TRAVERSAL_H_
#define TREE_TRAVERSAL_H_


class Node {
public:
	int val;
	Node left[], right[];

	void Node(int num)
    {
	    val = num;
    }

	void ~Node()
	{
		// remove all child nodes
	}

};


#endif /* TREE_TRAVERSAL_H_ */
