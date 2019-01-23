/*
 * making_number.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>
#include <math.h>

int makeNumber(int* arr, int numArr, int start)
{
	int ret = 0;
    int place = numArr - 1;

	for (int i=start; i<numArr; i++)
	{
		ret += arr[i] * pow(10, place--);
		printf("\n intermed num: %d \n", ret);
	}

	for (int j=0; j < start; j++)
	{
		ret += arr[j] * pow(10, place--);
	}

	return ret;
}

int main()
{
	int arr[3] = {1,2,3};

	printf("\n %d \n", makeNumber(arr, 3, 1));
}
