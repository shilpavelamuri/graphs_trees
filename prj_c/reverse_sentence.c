/*
 * reverse_sentence.c
 *
 *  Created on: Jan 11, 2019
 *      Author: shilpakalla
 */
#include <stdio.h>
#include <string.h>

int main()
{
	const char* inpStr = "I work at XYZ.";
	int inpStrLen = strlen(inpStr);

	printf("\ninpStrLen : %d\n", inpStrLen);

	char outStr[inpStrLen];

    memset(outStr, '\0', inpStrLen);

    int ctr=0, i=0;

    for (i=inpStrLen-1; i>=0; i--)
	{
    	// space is delimiter
    	// until space accumulate the word
		if (inpStr[i] != ' ')
		{
			// increment a counter to know
			// how many letters form a word
			// to be copied over
			ctr++;
		}
		else // detected space
		{
            // copy over the word from the inpStr
			// from one position to the right of
			// this space i+1 and ctr characters
			strncat(outStr, &inpStr[i+1], ctr);

			// copy over the space
			strncat(outStr, &inpStr[i], 1);

			// reset counters for next word
            ctr = 0;
		}
	}

    // copy over the last word, since there is no delimiter
    // before the starting word
    // it will not go thru' the above else logic
    if (ctr)
    {
    	strncat(outStr, inpStr, ctr);
    }

	printf("\nInput Str: %s\nOutput Str: %s\n", inpStr, outStr);
}

