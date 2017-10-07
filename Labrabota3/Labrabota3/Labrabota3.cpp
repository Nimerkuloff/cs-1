// Labrabota3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	const int A = 10;
	int array[A] = {}, box, counter = 0, counterMax = 0, counterMaxMeta = 0, j = 0;
	//Input
	for (int i = 0; i < A; i++) {
		scanf("%i", &array[i]);
	}
	//2
	for (j = 0; j < A;j++) {
	box = array[j];
	if (counterMax > counterMaxMeta) {
		counterMaxMeta = counterMax;
	}
	for (int i = 0; i < A; i++) {
			if (array[i] == box) {
				counter++;
			}
			else if (counter > counterMax) {
				counterMax = counter;
				counter = 1;
			}
		}
	}
	//2
    return 0;
}


