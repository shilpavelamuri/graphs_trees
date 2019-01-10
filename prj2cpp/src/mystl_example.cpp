/*
 * mystl_example.cpp
 *
 *  Created on: Jan 8, 2019
 *      Author: shilpakalla
 */

#include "mystl_example.h"
#include <stdio.h>

void MyStlExample::updateSet(std::set<int>& inp)
{
    score = inp;
}

void MyStlExample::updateSet(int inp)
{
	score.insert(inp);
}

int MyStlExample::getSetSize()
{
	return score.size();
}

std::set<int>& MyStlExample::getSet()
{
    return score;
}

int main()
{
	MyStlExample myStlObj;

	std::set<int> inpSet;
	for (int i=0; i<5; i++)
	{
		inpSet.insert(i*6);
	}

	myStlObj.updateSet(inpSet);
	myStlObj.updateSet(10);

	// print set sizes
    printf("\ninpSet size: %lu\n", inpSet.size());
    printf("\nStlObj set size: %d\n", myStlObj.getSetSize());

    // print class set contents
    std::set<int>::iterator s_it = myStlObj.getSet().begin();
    for (; s_it != myStlObj.getSet().end(); s_it++)
    {
    	printf("%d ", *s_it);
    }
}
