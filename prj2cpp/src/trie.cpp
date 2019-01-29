/*
 * trie.cpp
 *
 *  Created on: Jan 29, 2019
 *      Author: shilpakalla
 */

#include "trie.h"
#include <stdio.h>

bool Trie::searchTrie(string& srchStr)
{
	Trie* curr = this;
	int index = 0;

	for (int i = 0; i<srchStr.length(); i++)
	{
		index = srchStr[i] - 'a';

		printf("\n\nLooking for:%c", srchStr[i]);
		printf("\ncurr->child[%d]:%ul", index, curr->child[index]);

		// if end of branch reached, return false
		if (NULL == curr->child[index])
			return false;

		// update current search node
        curr = curr->child[index];
	}

	// if end of word reached, return true
	if (curr->isEndOfWord == true)
		return true;

	return false;
}

int main()
{
	bool bFound = false;

	string srch = "helix";

	Trie *root = new Trie();
	Trie *head = root;

	// 'he'
	root->child['h'-'a'] = new Trie();
	root = root->child['h'-'a'];

	root->child['e'-'a'] = new Trie();
	root = root->child['e'-'a'];
	root->isEndOfWord = true;// he is a possible word

	// 'helium'
	root->child['l'-'a'] = new Trie();
	root = root->child['l'-'a'];
	root->child['i'-'a'] = new Trie();
	root = root->child['i'-'a'];
	root->child['u'-'a'] = new Trie();
	root = root->child['u'-'a'];
	root->child['m'-'a'] = new Trie();
	root = root->child['m'-'a'];
	root->isEndOfWord = true;


	// search for word Helium
	bFound = head->searchTrie(srch);

	printf("\nFound: %d", bFound);
}

