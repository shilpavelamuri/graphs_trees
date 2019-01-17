/*
 * sorting.cpp
 *
 *  Created on: Jan 14, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <list>
#include <vector>

using namespace std;

void quickSort(std::vector<char>& inpVec, int lo, int hi)
{
	char pivot = inpVec[hi+1];
	    char buf;
	    int i = lo, j = hi;

    printf("\nPivot:%c, lo:%d, hi:%d", pivot, lo, hi);

    while (i < j)
    {
    	if (inpVec[i] > pivot)
    	{
    		if (inpVec[j] < pivot)
    		{
    			buf = inpVec[j];
    		    inpVec[j] = inpVec[i];
    		    inpVec[i] = buf;
    		    i++;
    		    j--;
    		}
    		else
    		{
    			// keep j in its place since it is higher than pivot
    			// go to next lower index
    			j--;
    		}
    	}
    	else
    	{
    	    i++;
    	}
    }

    while (i <= (hi+1))
    {
		if (inpVec[i] > pivot)
		{
			buf = inpVec[hi+1];
			inpVec[hi+1] = inpVec[i];
			inpVec[i] = buf;
			break;
		}
		else
			i++;
    }

    if (i == inpVec.size()) return;// reached the last element

    printf("\nPivot iteration complete: i:%d\n", i);
    for (std::vector<char>::iterator it = inpVec.begin(); it != inpVec.end(); it++)
    {
    	printf(" %c ", *it);
    }

    // recurse
    int lo_p1 = lo;
    int hi_p1 = i-1-1;
    int lo_p2 = i+1;
    int hi_p2 = inpVec.size()-1-1;

	//char* inpVecData = inpVec.data();
    /*std::vector<char> p1(&inpVecData[1], &inpVecData[1]+2);
    for (std::vector<char>::iterator it = p1.begin(); it != p1.end(); it++)
    {
    	printf(" %c ", *it);
    }*/
	if (lo_p1 <= hi_p1)
	{
		// 1st partition
		printf("\nlo_p1:%d, hi_p1:%d", lo_p1, hi_p1);
		//std::vector<char> p1(&inpVecData[lo_p1], &inpVecData[lo_p1]+(hi_p1 - lo_p1 + 1 + 1));
		//quickSort(p1, 0, p1.size()-1-1);
		quickSort(inpVec, lo_p1, hi_p1);
	}

	if (lo_p2 <= hi_p2)
	{
		// 2nd partition
		printf("\nlo_p2:%d, hi_p2:%d", lo_p2, hi_p2);
		//std::vector<char> p2(&inpVecData[lo_p2], &inpVecData[lo_p2]+(hi_p2 - lo_p2 + 1 + 1));// extra 1 to make sure the pivot is copied over
		//printf("\nhi for p2:%d", p2.size()-1-1);
		/*for (std::vector<char>::iterator it = p2.begin(); it != p2.end(); it++)
			{
				printf(" %c ", *it);
			}*/
		//quickSort(p2, 0, p2.size()-1-1);
		quickSort(inpVec, lo_p2, hi_p2);
	}
}

void quicksort(std::list<char>& list)
{
	std::vector<char> inpVec;

	// copy list items to array
	std::list<char>::iterator it = list.begin();
    for (; it != list.end(); it++)
    {
    	inpVec.push_back(*it);
    }

    // now apply quick sort algo
    quickSort(inpVec, 0, inpVec.size()-1-1);
}

#if 0
int main()
{
	char array[6] = {'z', 'y', 'x', 'c', 'a', 'b'};

	std::list<char> inpList(array, array + sizeof(array)/sizeof(char));

    quicksort(inpList);
}
#endif
