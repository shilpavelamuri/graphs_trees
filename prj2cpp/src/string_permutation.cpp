// find all permutations of string t


#include <string>
#include <set>
#include <stdio.h>

using namespace std;

set<string> permute(string& inp)
{
	char buf;
	string anchor;
	anchor = inp[0];
    set<string> sRet;

    // exit condition
	if (inp.size() == 2)
	{
		printf("\ninp of size 2: %s", inp.c_str());

		// add original inp to set
		sRet.insert(inp);

		// swap letter positions
		buf = inp[0];
		inp[0] = inp[1];
		inp[1] = buf;

		printf("\ninp of size 2, after swap: %s", inp.c_str());

		// add to set
		sRet.insert(inp);

		return sRet;
	}

	printf("\ninp: %s", inp.c_str());

	// copy input string as a combination to return
	sRet.insert(inp);

	// copy string suffix combinations to anchor
    // anchor being the starting letter
	string newInp = inp.substr(1,inp.length()-1);

	printf("\nnewInp(to permute): %s", newInp.data());

	set<string> sSub = permute(newInp);

    for (set<string>::iterator it = sSub.begin(); it != sSub.end(); it++)
    {
    	string stmp = *it;
    	printf("\nsSub:%s", stmp.data());
    	sRet.insert(anchor + *it);
		printf("\nsRet after appending anchor[%s]: %s", anchor.c_str(), (anchor+stmp).c_str());
    }

    // now move the anchor through the various non-anchor positions
    // for each sub-combination and append to return set
    // copy the return set to work with so as to not run algorithm on
    // already processed non-anchor strings
    set<string> sOrig = sRet;
    for (set<string>::iterator it = sOrig.begin(); it != sOrig.end(); it++)
	{
    	string sOrig = *it;
    	int len = sOrig.length();
    	string currAnchor (1, sOrig[0]);
    	printf("\nsOrig:%s", sOrig.c_str());
    	for (int i=1; i<len; i++)
    	{
    		string sBuf = sOrig.substr(1, i)+currAnchor+sOrig.substr(i+1, len-i-1);
			printf("\nsBuf:%s", sBuf.c_str());
			sRet.insert(sOrig.substr(1, i)+currAnchor+sOrig.substr(i+1, len-i-1));
    	}
	}

    return sRet;
}

int main()
{
    string sInp = "This";

    set<string> sOut = permute(sInp);

    for (set<string>::iterator it = sOut.begin(); it != sOut.end(); it++)
    {
    	string s = *it;
    	printf("\n%s", s.c_str());
    }
}
