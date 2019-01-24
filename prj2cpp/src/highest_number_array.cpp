/*
 * highest_number_array.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    int arr[4] = {9, 93, 24, 6};
    int buf = 0;

    int arrLen = sizeof(arr)/sizeof(int);

    char* str1 = (char*) calloc(arrLen+1, sizeof(char));
    char* str2 = (char*) calloc(arrLen+1, sizeof(char));

    // do a string concatenation and then comparison, for sorting
    for (int j=0; j<arrLen; j++)
		for (int i=0; i<arrLen-1; i++)
		{
			sprintf(str1, "%d", arr[i]);
			sprintf(str2, "%d", arr[i+1]);

			strncat(str1, str2, strlen(str1));
			strncat(str2, str1, strlen(str2));

			printf("\nstr1:%s, str2:%s\n", str1, str2);

			// is str1 < str2
			if (strncmp(str1, str2, strlen(str2)) < 0)
			{
				buf = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = buf;
			}
		}

	printf("\nMax number: ");
    for (int i=0; i<arrLen; i++)
    	printf("%d", arr[i]);
}
