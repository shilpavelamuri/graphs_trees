/*
 * dbl_array.c
 *
 *  Created on: Feb 12, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>

void printValues(int M, int N, int arr[][N])
{
	for (int i=0; i<M; i++)
		for (int j=0; j<N; j++)
			printf("%d ", arr[i][j]);
}

int main()
{
	int arr[3][2] = {{1,2}, {2,3}, {4,5}};

	printValues(3, 2, arr);
}
