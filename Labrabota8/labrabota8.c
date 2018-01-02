/*
����� ��� ����� ��������� �� �������� ��������� �������� �������� (��. ����. 1).
��� �����:
1.	�������� �����:
- ��������� ������� ��������  ������� ��  ��������� [X_min, X_max]
� ����� h ;
- ���������� ���������� �������, �� ������ �������  ������� ������ ����;
2.	�� ������ ������� �������� ������ � ���������  eps = 0.001.
����� ��������� ��� ������� ������� ������� �������������� ���
�������, ���  ��� ������ ��������. ��� ������� ������ ������� �����
��������.

X_min	X_max  step
-0,5	1,5	   0,05

x^4-3*sin(3.6*x)=0
*/
#pragma once
#pragma hdrstop
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define X_min  -0.5
#define X_max  1.5
#define step  0.05
#define eps  0.001

double equation(double x) {
	return (pow(x, 4) - (3 * sin(3.6*x)));
}
double secant(double a, double b)//����� ����
{
	int iterator = 0;
	while (fabs(b - a) > eps)
	{
		a = b - (b - a) * equation(b) / (equation(b) - equation(a));
		b = a - (a - b) * equation(a) / (equation(a) - equation(b));
		iterator++;
	}
	printf("iterations - %d ", iterator);
	return b;
}
double dichotomy(double a, double b)//����� ����������� �������
{
	double x;
	int iterator = 0;
	while (b - a > eps) {
		x = (a + b) / 2;
		iterator++;
		if (equation(b) * equation(x) < 0)
			a = x;
		else
			b = x;
	}
	printf("iterations - %d ", iterator);
	return (a + b) / 2;
}
int main()
{
	int iter1 = 0;
	double arr[41][2];//������ �������� ������� 
	for (double i = X_min; i <= X_max + 0.001; i += step) {

		arr[iter1][0] = i;//������ ������� - �������� �������
		arr[iter1][1] = equation(i);//������ - �������� ������� ��� ������ ���������
		printf("x=%.2f\tf(x)=%f\n", i, arr[iter1][1]);
		iter1++;

	}
	int iter2 = 0;
	double arr_func_change_sign[2][2];//������ �������� �������� ����� �������
	for (int i = 0; i < 40; i++) {
		if ((arr[i][1] > 0 && arr[i + 1][1] < 0) || (arr[i][1] < 0 && arr[i + 1][1] > 0)) {
			arr_func_change_sign[iter2][0] = arr[i][0];//�������� ���������� ����� ������ ����� �������� �������
			arr_func_change_sign[iter2][1] = arr[i + 1][0];//�������� �������� ������� �����
			printf("----------------------------\na=%.3f \t b=%.3f\n", arr_func_change_sign[iter2][0], arr_func_change_sign[iter2][1]);
			iter2++;
		}
	}
	//����� ����

	printf("Koren' (metod hord) =%f\n", secant(arr_func_change_sign[1][0], arr_func_change_sign[1][1]));

	//����� ����������� �������
	printf("Koren' (metod polov.del) =%f\n", dichotomy(arr_func_change_sign[1][0], arr_func_change_sign[1][1]));
	return 0;
}