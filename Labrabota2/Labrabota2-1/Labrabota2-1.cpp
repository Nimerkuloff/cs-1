#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define  _USE_MATH_DEFINES
#define M 10
#define N 15
#include <math.h>
#pragma hdrstop
static int factorial(int k)
{
	return (k < 2) ? 1 : k * factorial(k - 1);
}

int main(void)
{
	double x1, x2, y1 = 0, y2 = 0, sum1 = 0, sum2 = 1, delta=0;
	printf("x1 is ");
	scanf("%le", &x1);
	printf("x2 is ");
	scanf("%le", &x2);

	if (x1<M_PI / 6) {
		y1 = pow(x1, 2);
	}
	else if (x1 >= M_PI / 3) {
		y1 = pow(6, x1);
	}
	else {
		y1 = 1 / (1 + pow(sin(x1), 2));
	}

	for (int k = 1; k < M; k++) {
		sum1 += pow(x2, 2 * k) / factorial(k + 1);
	}
	for (int k = 1; k < N; k++) {
		sum2 *= cos(x2) / (pow(M_PI, k));
	}
	y2 = sum1*sum2;

	delta = ((y2 - y1) * 100) / y1;
	printf("y1 is %le", y1);
	printf("\ny2 is %le", y2);
	printf("\ndelta is %le\n", delta);
	//system("PAUSE");
	return 0;
}