/*
 * trie.h
 *
 *  Created on: Jan 29, 2019
 *      Author: shilpakalla
 */

#ifndef TRIE_H_
#define TRIE_H_

#include <stdlib.h>
#include <string>

using namespace std;

#define    MAX_NUM_ALPHABETS    26

class Trie {

    public:
	    // variables
	    Trie* child[MAX_NUM_ALPHABETS];
	    bool isEndOfWord;

	    // Ctor
	    Trie ()
	    {
	    	for (int k=0; k<MAX_NUM_ALPHABETS; k++)
	    	{
	    		child[k] = NULL;
	    	}

	    	isEndOfWord = false;
	    }

	    ~Trie ()
	    {
	    	// delete all child nodes
	    	for (int i=0; i<MAX_NUM_ALPHABETS; i++)
	    		delete child[i];
	    }

	    // Functions
	    void insertTrie(Trie&);
	    void deleteTrie(Trie*&);
	    bool searchTrie(string&);
};



#endif /* TRIE_H_ */
