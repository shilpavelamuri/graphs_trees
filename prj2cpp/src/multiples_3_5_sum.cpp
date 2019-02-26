/*
 * multiples_3_5_sum.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>

#if 0
int main()
{
	int i = 1, m3 = 1, m5 = 1, sum = 0;

	while (true)
	{
		// compute multiples of 3 first
		// so we can break loop when exceeds 1000
		// multiples of 3 will exceed 1000 later
		// than multiples of 5
		m3 = 3 * i;

		if (m3 < 1000)
		{
			sum += m3;

			// skip multiples common to 3 and 5
			// coz 3*i already accounts for them
			m5 = 5 * i;

			if (i % 3 && m5 < 1000)
			{
				sum += m5;
			}
		}
		else
		{
			// multiples of 3 will be
			// lower than 1000 later than
			// multiples of 5. So, when
			// multiples of 3 exceed 1000,
			// multiples of 5 would have
			// already exceeded 1000 for the
			// same 'i' and
			// hence safe to break
			break;
		}

		i++;
	}

	printf("\nResult: %d\n", sum);
}

#endif
