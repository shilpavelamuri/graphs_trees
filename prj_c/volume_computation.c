/*
 * volume_computation.c
 *
 *  Created on: Jan 2, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("\nComputing volume\n");

	// input
	int arr[15] = {1, 3, 2, 4, 1, 3, 1, 4, 5, 2, 2, 1, 4, 2, 2};
    int left_wall[15] = {0};
    int right_wall[15] = {0};
    int vol = 0;
    int last_left_wall = 0;
    int last_right_wall = 0;
    int num_arr_items = sizeof(arr)/sizeof(int);

    // i is fwd index, j is reverse index
    for (int i=0,j=num_arr_items-i; i<num_arr_items; i++, j--)
    {
        // update left wall for each node
    	// keep track of last tallest as left wall
    	if (0 == last_left_wall)
    	{
    		left_wall[i] = 0;
    		last_left_wall = arr[i];
    	}
    	else if (last_left_wall < arr[i])
    	{
    		last_left_wall = arr[i];
    	}
    	else if (last_left_wall > arr[i])
    	{
    		left_wall[i] = last_left_wall;
    	}
    	else
    	{
    		left_wall[i] = left_wall[i-1];
    	}

    	// update right wall for each node
    	// keep track of last tallest as right wall
    	if (0 == last_right_wall)
    	{
    	    right_wall[j] = 0;
    	    last_right_wall = arr[j];
    	}
    	else if (last_right_wall < arr[j])
    	{
    		last_right_wall = arr[j];
    	}
    	else if (last_right_wall > arr[j])
    	{
    		right_wall[j] = last_right_wall;
    	}
    	else
    	{
    		right_wall[j] = right_wall[j+1];
    	}
    }

    // compute volumes now that the boundaries
    // have been determined for each node
    for (int i=0; i<num_arr_items; i++)
    {
    	if ((0 == left_wall[i]) || (0 == right_wall[i]))
    		continue;

    	if (left_wall[i] < right_wall[i])
    	{
    		vol += (left_wall[i] - arr[i]);
    	}
    	else
    	{
    		vol += (right_wall[i] - arr[i]);
    	}

        printf("\ni:%d, left wall:%d, right_wall: %d, floor:%d, vol: %d\n",
        		i, left_wall[i], right_wall[i], arr[i], vol);
    }


    printf("\nTot Vol: %d\n", vol);
}
