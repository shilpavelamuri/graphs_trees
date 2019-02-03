/*
 * num_strings_1s.cpp
 *
 *  Created on: Feb 2, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

int num_strings(string& str)
{
	int count = 0;
	int inp = 0;
	int right_index = 0, left_index = 0;
    int str_len = str.size();
    int spaces_jumped = 0;

	// validate input
	if (0 == str_len) return 0;

	inp = strtol(str.data(), NULL, 2);

	printf("\ninput number:%d", inp);

	while (inp != 0)
	{
		// reset trackers
		right_index = -1;
		left_index = -1;

		// iterate through string bit by bit
		for (int i=0; i<(str_len - spaces_jumped); i++)
		{
			// found 1
			if (inp & (1<<i))
			{
				if (-1 == right_index)
				{
					right_index = i;
				}
				else if (-1 == left_index)
				{
					left_index = i;
					count++;
				}
				else
				{
					count++;
				}
			}
		}


		printf("\ninput before shift:%d", inp);

		spaces_jumped = (right_index+1);
		// shift input to the right to drop the right index
		inp >>= (right_index+1);


		printf("\ninput %d after right shift by:%d", inp, right_index+1);
	}

	return count;
}

int main()
{
	string str = "0010110010";

	int result = num_strings(str);

	printf("\nNumber of strings found: %d", result);
}
