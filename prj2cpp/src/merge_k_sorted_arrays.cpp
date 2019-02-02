/*
 * merge_k_sorted_arrays.cpp
 *
 *  Created on: Jan 31, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <vector>

using namespace std;


bool getMin(vector<int>& idx, vector<int> *arrList, int* min, int* min_it_index, int* num)
{

	*num = 0;

    bool min_set = false;


	for (int i=0; i<idx.size(); i++)
	{
		// check if current index for the particular array is within range
		// if not in range, continue to next array
		if (idx[i] == arrList[i].size())
		{
			(*num)++;
			printf("\nindex %d out of range : num: %d", i, *num);
			continue;
		}

		if (!min_set)
		{
			printf("\nsetting min with index %d", i);
			// use first array as baseline
			*min = arrList[i][idx[i]];
			// track the min index within the vector of tracking indices
			*min_it_index = i;
			min_set = true;
			continue;
		}

		printf("\nComparing min:%d with idx[%d]:%d ", *min, i, arrList[i][idx[i]]);

		if (arrList[i][idx[i]] < *min)
		{
			// update new min
			*min = arrList[i][idx[i]];
			*min_it_index = i;
		}
		else if (arrList[i][idx[i]] == *min)
		{
			printf("\nFound duplicate occurrence. Before incrementing:idx[%d]:%d\n", i, idx[i]);

			// advance index over the occurrence
			// in another array
			idx[i]++;

			printf("\nFound duplicate occurrence. After:idx[%d]:%d\n", i, idx[i]);
		}
	}


	printf("\nresult min:%d", *min);

	return min_set;
}

vector<int>* merge(int k, vector<int> *arrList)
{
    vector<int> *out = new vector<int>();

    vector<int> curr_index;

    int min = 0;
    int min_index = 0;
    int num_traversed = 0;

    // setup start index to all the arrays
    for (int i=0; i<k; i++)
    {
    	curr_index.push_back(0);
    }

    printf("\nall iterators set\n");

    // compare until iterators are present
    while (num_traversed < k)
    {
    	if (getMin(curr_index, arrList, &min, &min_index, &num_traversed))
    	    out->push_back(min);

    	// advance the iterator on the minimum element array
    	curr_index[min_index]++;
    }

    return out;
}

int main()
{
	vector<int> arrList[5];

	for (int i=1; i<=10; i++)
	    arrList[0].push_back(2*i);
	for (int i=1; i<=11; i++)
		arrList[1].push_back(3*i);
	for (int i=1; i<=9; i++)
		arrList[2].push_back(4*i);
	for (int i=1; i<=2; i++)
		arrList[3].push_back(5*i);
	for (int i=1; i<=20; i++)
		arrList[4].push_back(6*i);

	printf("\nReady to merge\n");


	vector<int> *outArr = merge(5, arrList);

	vector<int>::iterator it = outArr->begin();
	printf("\nMerged result:");
	for (; it != outArr->end(); it++)
		printf(" %d ", *it);
}
