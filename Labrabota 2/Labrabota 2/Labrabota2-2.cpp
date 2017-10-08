#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include <math.h>
int main(void)
{
	int number, sum = 0;
	scanf("Input number \n%i", &number)

		while (number != 0) {
			sum += number % 10;
			number /= 10;
		}

	if ((pow(number, 2) == (sum))) {
		printf("Are equivalent");
	}
	return 0;
}
