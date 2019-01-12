/*
 * linked_list_letters_organizing.cpp
 *
 *  Created on: Jan 11, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <set>

using namespace std;

int main()
{
	std::multiset<char> outSet;

	// fill it into a set
    outSet.insert('a');
    outSet.insert('x');
    outSet.insert('b');
    outSet.insert('c');
    outSet.insert('y');
    outSet.insert('z');

    for (std::multiset<char>::iterator it = outSet.begin(); it != outSet.end(); it++)
    {
    	printf("%c ", *it);
    }
}
