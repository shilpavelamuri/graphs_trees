/*
 * mystl_example.h
 *
 *  Created on: Jan 8, 2019
 *      Author: shilpakalla
 */

#ifndef MYSTL_EXAMPLE_H_
#define MYSTL_EXAMPLE_H_


#include <set>

using namespace std;

class MyStlExample {

public:
	// Var
	std::set<int> score;

	// Ctor, Dtor Fn
    MyStlExample() {};
    ~MyStlExample() {};

    void updateSet(std::set<int>&);
    void updateSet(int);
    int  getSetSize();
    std::set<int>& getSet();
};

#endif /* MYSTL_EXAMPLE_H_ */
