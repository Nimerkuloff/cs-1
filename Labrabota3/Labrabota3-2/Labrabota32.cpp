
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop
int main()
{
	int counter = 1, max = 0;
	const int A = 10;
	int array[A] = {};
	for (int i = 0; i < A; i++) {
		scanf("%u", &array[i]);
		if(i != 0) {
			while (array[i] == array[i - 1]) {
				counter++;
				i++;
			}
			if (counter >= max) {
				max = counter;
				counter = 1;
			}
		}
	}
	printf("Answer is %i\n", max);
	system("PAUSE");
	return 0;
}
