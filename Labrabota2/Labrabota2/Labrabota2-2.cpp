#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include <math.h>
#pragma hdrstop
int main2(void)
{
	int number, sum = 0;
	scanf("Input number \n%3i", &number);

		while (number != 0) {
			sum += number % 10;
			number /= 10;
		}

	if ((pow(number, 2) == (sum))) {
		printf("Are equivalent");
	}
		//system("PAUSE");
	return 0;
}
