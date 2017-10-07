// Labrabota3.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop
int main()
{
	const int A = 10;
	//int array[A] = {1,0,1,1,1,0,1,1,1,-9}, box, counter = 0, counterMax = 1, counterMaxMeta = 0, j = 0;
  int array[A] = {}, box, counter = 1, counterMax = 0, counterMaxMeta = 0, j = 0;
	
for (int i = 0; i < A; i++) {
	scanf("%i", &array[i]);
}
	box = array[0] + 1;
	for (j = 0; j < A;j++) {
		if (array[j] != box) {
			box = array[j];
			counter = 0;
			if (counterMax >= counterMaxMeta) {
				counterMaxMeta = counterMax;
				counterMax = 0;
			}
			for (int i = 0; i < A; i++) {
				if (array[i] == box) {
					counter++;
				}
				else if (counter >= counterMax) {
					counterMax = counter;
					counter = 0;
				}
			}
		}
	}

	printf("Answer is %i\n",counterMaxMeta);
	system("PAUSE");
    return 0;
}


