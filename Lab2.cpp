#include  <stdio.h>
#
static int factorial(int k)
{
	return (k < 2) ? 1 : k * factorial(k - 1);
}

int main(void)
{
	double x1, x2, y1 = 0, y2 = 0, sum1=0, sum2=1;
	const M = 10, N = 15;
	
	//Blet isprav output na input
	//dobavit' output dlya y1 y2 delta
	scanf("����� �������� ��������� ������� ���������\n %le",&x1);
	scanf("����� �������� ��������� ������� ���������\n %le",&x2);

	if (x1<M_PI/6){
		y1 = pow(x1, 2);
	}
	else if (x1 >= M_PI / 3){
		y1 = pow(6, x1);
	}
	else {
		y1 = 1 / (1 + pow(sin(x), 2));
	}

	for (int k = 1, k < M, i++) {
		sum1 += pow(x2, 2 * k) / factorial(k + 1);
		sum2 *= cos(x2) / (pow(M_PI, k);
	}
	y2 = sum1*sum2;
	
	double delta = ((y2 - y1) * 100) / y1;







		return 0;
}