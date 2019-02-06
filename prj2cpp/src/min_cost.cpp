/*
 * min_cost.cpp
 *
 *  Created on: Feb 5, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <set>

using namespace std;

int min_cost(int* arr, int N)
{
	// validate input
	if (arr == NULL || N == 0) return 0;

	// store array contents in multiset for ease of insert, erase
	multiset<int> mInp (arr, arr+N);

	int sum = 0, cost = 0;
	int min1 = 0, min2 = 0;

	while (!mInp.empty())
	{
		// take the top 2 weights (min weights)
		min1 = *(mInp.begin());
		mInp.erase(mInp.begin());
		min2 = *(mInp.begin());
		mInp.erase(mInp.begin());

		// add the min weights
		sum = min1 + min2;

		// update overall cost
		cost += sum;

        // insert summed weight, if not the last weights
		if (!mInp.empty())
			mInp.insert(sum);
	}

	return cost;
}

int main()
{
	int inp[5] = {4,3,2,6,1};

	printf("\nmin_cost:%d", min_cost(inp, 5));
}
