/*
 * median.cpp
 *
 *  Created on: Jan 24, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define      BUF_MAX    256

void insertIntoBuf(int* buf, int count, int val)
{
	int tmpBuf[BUF_MAX] = {0};

	for (int i=0; i < count; i++)
	{
		// insert in ascending sorted order
		if (val > buf[i])
		{
            // copy over the remaining buf to a temporary backup
			memcpy(tmpBuf, &buf[i], BUF_MAX - i);

			// insert val
			buf[i] = val;

			// copy back the tmp buffer to buf starting at the next position
			memcpy(&buf[i+1], tmpBuf, BUF_MAX - (i + 1));

			// done with insertion, return
			break;
		}
	}
}

int main()
{
	int buf[BUF_MAX] = {0};
	char inpBuf[5];
	int val = 0, count = 0, median = 0;

	FILE *f = fopen("/home/shilpakalla/Downloads/workspace/prj2cpp/src/numbers.txt", "r");

	if (NULL == f)
	{
		printf("\nFailed to open file for read");

		return -1;
	}

	printf("\nSuccessfully opened file for read");


	while (NULL != fgets(inpBuf, sizeof(int), f))
	{
		//printf("\ninpBuf : %s", inpBuf);
		sscanf(inpBuf, "%d", &val);
		//printf("\nval : %d", val);

		count++;
        insertIntoBuf(buf, count, val);
	}

	fclose(f);

	printf("\nClosed file");

	// calculate median
	if (count % 2)
	{
		median = buf[count/2];
	}
	else
	{
		median = (buf[(count/2) - 1] + buf[count/2])/2;
	}

	printf("\nBuf contents:");
	for (int i=0; i<count; i++)
		printf("%d", buf[i]);

	printf("\nCount: %d", count);
	printf("\nMedian: %d", median);
}

