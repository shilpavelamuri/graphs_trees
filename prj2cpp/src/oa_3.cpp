/*
 * oa_3.cpp
 *
 *  Created on: Jan 16, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char inpArr[] = "you got beautiful eyes";
    int arrLength = strlen(inpArr);
    int asciiSet[256] = {0};
    int ctr = 0;


    for (int i=0; i<arrLength && inpArr[i]!='\0'; i++)
    {
    	int value = inpArr[i];
    	asciiSet[value]++;


    	if (0 == (asciiSet[value]%2))//even occurrence
        {
    		ctr++; // keep track of number of duplicates deleted

            if ((i+1) < arrLength)
    		{
        		strncpy(&inpArr[i], &inpArr[i+1], arrLength-i-1);// remove in place
        	    inpArr[arrLength-ctr] = '\0';//reset remainder of the array
        	    i--;// offset for loop iteration
    		}
    		else
    		{
    			inpArr[i] = '\0';// reset in place
    			break;
    		}
        }
    }


    printf("\nResult:%s", inpArr);
}
