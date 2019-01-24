/*
 * longest_palin.cpp
 *
 *  Created on: Jan 24, 2019
 *      Author: shilpakalla
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* inp = "This issi noonnoon jdgjfhfj";
	int len = strlen(inp);
	char *out = (char*) calloc(len+1, sizeof(char));
	char *maxOut = (char*) calloc(len+1, sizeof(char));
    int j = 0, k = 0, p = 0;

    printf("\ninp length: %d\n", len);
	for (int i=0; i<len; i++)
	{
		j = len - 1;
        memset(out, 0, len);
        k = 0;
        p = i;

        printf("\nj: %d", j);

		while(j > p)
		{
			printf("\ninp[%d]:%c, inp[%d]:%c, k:%d", p, inp[p], j, inp[j], k);


			if (inp[p] == inp[j])
			{
				out[k] = inp[p];
				out[k+j-p] = inp[j];
				k++;
				p++;
				printf("\nso far match:%s", out);
			}
			else
			{
				// check if there was a partial match
				// that needs to be erased
				if (strlen(out) > 0)
				{
					printf("\nerasing partial match");
					memset(out, 0, len);
					p = i;
			        k = 0;
				}
			}

			j--;

		}//while

		// check if palindrome
		if (strlen(out) > 0)
		{
			printf("\nFound a match:%s", out);
			if (strlen(out) > strlen(maxOut))
			{
				strncpy(maxOut, out, strlen(out));
				printf("\nCopied match to max:%s", maxOut);
			}
		}
	}

	if (strlen(maxOut) > 0)
	{
		printf("\nLongest palindrome: %s\n", maxOut);
	}
	else
	{
		printf("\nString does not contain palindrome\n");
	}
}
