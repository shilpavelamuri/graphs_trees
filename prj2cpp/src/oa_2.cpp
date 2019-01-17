/*
 * oa_2.cpp
 *
 *  Created on: Jan 16, 2019
 *      Author: shilpakalla
 */


#include <stdio.h>

#if 0
int main()
{
    int inpArr[15] = {12, 12, 14, 24, 45, 65, 32, 24, 87, 23, 65, 55, 7, 78, 11};

    int i=0, j=14;

    for (; i<15; i++,j--)
    {
    	if (inpArr[j] > inpArr[i])
    		break;
    }

    printf("\nResult: %d, %d", j, i);
}
#endif
