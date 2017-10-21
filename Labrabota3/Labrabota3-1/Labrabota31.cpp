//Program finds max length of a repeated numbers sequences (elements of array input manually) 
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop
int main()
{
	int counter = 1, max = 0;
	const int A = 10;
	int array[A] = {};
	scanf("%u", &array[0]);
	for (int i = 1; i <= A; i++) {
		scanf("%u", &array[i]);
		if (array[i - 1] == array[i]) {
			counter++;
			if (counter >= max) { max = counter; }
			else { counter = 1; }
		}

	}
	printf("Answer is %i\n", max);
	system("PAUSE");
	return 0;
}
