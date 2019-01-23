/*
 * factorial.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: shilpakalla
 */

#include <stdio.h>

int factorial(int n)
{
	// exit condition
	if (1 == n) return n;

	return (n * factorial(n-1));
}

int main()
{
	printf("\nfactorial(3): %d\n", factorial(3));
}
