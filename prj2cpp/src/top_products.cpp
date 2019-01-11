/*
 * top_products.cpp
 *
 *  Created on: Jan 10, 2019
 *      Author: shilpakalla
 */

#include <map>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    std::multimap<string, int> inpMap;
    std::multimap<int, string> sortedMap;

    inpMap.insert(std::pair<string, int>("Aa", 15));
    inpMap.insert(std::pair<string, int>("Bb", 78));
    inpMap.insert(std::pair<string, int>("Cc", 37));
    inpMap.insert(std::pair<string, int>("Dd", 61));
    inpMap.insert(std::pair<string, int>("Ee", 45));
    inpMap.insert(std::pair<string, int>("Ff", 25));
    inpMap.insert(std::pair<string, int>("Gg", 51));
    inpMap.insert(std::pair<string, int>("Hh", 50));
    inpMap.insert(std::pair<string, int>("Ii", 85));
    inpMap.insert(std::pair<string, int>("Jj", 15));
    inpMap.insert(std::pair<string, int>("Kk", 5));
    inpMap.insert(std::pair<string, int>("Ll", 95));
    inpMap.insert(std::pair<string, int>("Mm", 85));

    // now iterate through to find the top 10
    for (std::multimap<string, int>::iterator it = inpMap.begin(); it != inpMap.end(); it++)
    {
        sortedMap.insert(std::pair<int, string>(it->second, it->first));
    }

    int i=0;
    for (std::multimap<int, string>::reverse_iterator rit = sortedMap.rbegin(); i<10 && rit!=sortedMap.rend(); i++, rit++)
    {
    	printf("%s ", rit->second.c_str());
    }
}
