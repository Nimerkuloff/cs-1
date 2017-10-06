
#include <stdio.h>
#include <stdlib.h>
#define  _USE_MATH_DEFINES
#define M 10
#define N 15
#include <math.h>
static int factorial(int k)
{
	return (k < 2) ? 1 : k * factorial(k - 1);
}
 
int main(void)
{
	double x1, x2, y1 = 0, y2 = 0, sum1=0, sum2=1;
 
	scanf("Input x1\n %le",&x1);
	scanf("Input x2\n %le",&x2);
 
	if (x1<M_PI/6){
		y1 = pow(x1, 2);
	}
	else if (x1 >= M_PI / 3){
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
 
	double delta = ((y2 - y1) * 100) / y1;
	printf("y1 is \n %le", &y1);
	printf("y2 is \n %le", &y2);
	printf("delta is \n %le", &delta);
	return 0;
}