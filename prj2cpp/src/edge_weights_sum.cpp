/*
 * edge_weights_sum.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <vector>

using namespace std;


void addEdge(vector<int> *aL, int dest, int wt)
{
    aL->push_back(wt);
}

void printGraph(vector<int> *aL)
{
    for (int i=0; i<10; i++)
    {
    	printf("\nNew List:aL[%d]: ", i);

    	for (int j=0; j<aL[i].size(); j++)
    	{
    		printf(" aL[%d][%d]: %d", i, j, aL[i][j]);
    	}
    }
}

void max_sum_path(vector<int> *aL, int index, vector<int> &max_path)
{
	static int sum = 0;
	static int max_sum = 0;
	static vector<int> path;


    // exit if leaf node
	if (aL[index].size() == 0)
	{
		printf("\nleaf node at index:%d", index);

	    // save the path if sum is the highest
		// current sum was not the max,
		// pop out the 'j' vector element
		if (sum > max_sum)
		{
			max_sum = sum;
	        path.push_back(index);

			printf("\npushing back index: %d", index);

	        max_path = path;

			printf("\nmax_sum set: %d", max_sum);

			printf("\nPopped out : %d", path.back());

			path.pop_back();
		}
		else
		{
			printf("\nsum %d not max_sum %d", sum, max_sum);
		}

		// clear out running variables
		sum = 0;

		return;
	}

	// add index to path
	path.push_back(index);
	printf("\npushing back index: %d", index);


	for (int j=index+1; j<10; j++)
	{
		printf("\nIn edge: %d -> %d", index, j);

		// if there is an edge, go down the
		// neighbors to the adjacent node
		if (aL[index][j] > 0)
		{
			sum += aL[index][j];

			max_sum_path(aL, j, max_path);// recurse to adjacent's neighbor
		}
	}


	printf("\nPopped out : %d", path.back());
	path.pop_back(); // done processing index
}

int main()
{
	// out
	vector<int> max_path;

    // populate graph
	vector<int> adjList[10];

	// add edge from node1 to node2
	addEdge(&adjList[0], 0, 0);
	addEdge(&adjList[0], 1, 10);
	addEdge(&adjList[0], 2, 0);
	addEdge(&adjList[0], 3, 30);
	addEdge(&adjList[0], 4, 40);

	addEdge(&adjList[1], 0, 0);
	addEdge(&adjList[1], 1, 0);
	addEdge(&adjList[1], 2, 10);
	addEdge(&adjList[1], 3, 0);
	addEdge(&adjList[1], 4, 0);
	addEdge(&adjList[1], 5, 10);

	addEdge(&adjList[2], 0, 0);
	addEdge(&adjList[2], 1, 0);
	addEdge(&adjList[2], 2, 0);
	addEdge(&adjList[2], 3, 0);
	addEdge(&adjList[2], 4, 0);
	addEdge(&adjList[2], 5, 0);
	addEdge(&adjList[2], 6, 0);
	addEdge(&adjList[2], 7, 0);
	addEdge(&adjList[2], 8, 80);

	addEdge(&adjList[4], 0, 0);
	addEdge(&adjList[4], 1, 0);
	addEdge(&adjList[4], 2, 0);
	addEdge(&adjList[4], 3, 0);
	addEdge(&adjList[4], 4, 0);
	addEdge(&adjList[4], 5, 0);
	addEdge(&adjList[4], 6, 0);
	addEdge(&adjList[4], 7, 0);
	addEdge(&adjList[4], 8, 0);
	addEdge(&adjList[4], 9, 90);

	addEdge(&adjList[5], 0, 0);
	addEdge(&adjList[5], 1, 0);
	addEdge(&adjList[5], 2, 0);
	addEdge(&adjList[5], 3, 0);
	addEdge(&adjList[5], 4, 0);
	addEdge(&adjList[5], 5, 0);
	addEdge(&adjList[5], 6, 0);
	addEdge(&adjList[5], 7, 70);

	printGraph(adjList);

	max_sum_path(adjList, 0, max_path);

	// printing max path
	printf("\nprinting max path: ");
	for (int k=0; k<max_path.size(); k++)
	{
		printf(" %d ", max_path[k]);
	}
}
