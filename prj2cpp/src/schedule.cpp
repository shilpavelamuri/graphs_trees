/*
 * states.cpp
 *
 *  Created on: Jan 16, 2019
 *      Author: shilpakalla
 */

#include <set>
#include <stdio.h>

using namespace std;


#if 0
int main()
{
	int n = 10;
	int t[10] = {5, 10, 2, 15, 4, 20, 8, 12, 10, 11};

	int m = 0, sum = 0;


	std::multiset<int> t_sorted(t, t+10);
	std::multiset<int>::iterator it = t_sorted.begin();

	// find difference between highest and least times
    int time_diff = *(t_sorted.rbegin()) - *(t_sorted.begin());

    printf("\ntime diff:%d", time_diff);

    int max_time = *(t_sorted.rbegin());

    printf("\nmax time:%d", max_time);

	// OPT:than 20 (arbitrary difference), then

    // sum up the job times until they are the same value
    // as the max time
    // as we group them, each iter will be an increment of m
    // in the end, we add one more to m to account for the max
    // time task
    for(int i=0; i<n; i++,it++)
    {
    	// add job times to the sum
        sum += *it;

        // if sum exceeds max time of a single job
        // stop adding times and move on to the next job
        if (sum > max_time)
        {
        	printf("\nSum: %d", sum);
            m++;
            sum = 0;
        }
    }

    // one more for the longest timed job
    m++;
    printf("\nm:%d", m);
}
#endif
