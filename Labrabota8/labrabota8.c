/*
Найти все корни уравнения на заданном интервале согласно варианта (см. табл. 1).
Для этого:
1.	Отделить корни:
- вычислить таблицу значений  функции на  интервале [X_min, X_max]
с шагом h ;
- программно определить отрезки, на концах которых  функция меняет знак;
2.	На каждом отрезке уточнить корень с точностью  eps = 0.001.
Метод уточнения для каждого отрезка выбрать самостоятельно при
условии, что  все методы различны. Для каждого метода вывести число
итераций.

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
void chord(double a, double b);
void dichotomy(double a, double b);

double equation(double x) {
	return ( pow(x, 4) - ( 3 * sin(3.6*x) ) );
}

int main()
{
	int iter1 = 0;
	double arr[41][2];//массив значений функций 
	for (double i = X_min; i <= X_max + 0.001; i += step) {

		arr[iter1][0] = i;//первый столбец - аргумент функции
		arr[iter1][1] = equation(i);//второй - значение функции при данном аргументе
		printf("x=%.2f\tf(x)=%f\n", i, arr[iter1][1]);
		iter1++;

	}
	int iter2 = 0;
	double arr_func_change_sign[2][2];//массив значений перемены знака функции
	for (int i = 0; i < 40; i++) {
		if ( (arr[i][1] > 0 && arr[i + 1][1] < 0) || (arr[i][1] < 0 && arr[i + 1][1] > 0) ) {
			arr_func_change_sign[iter2][0] = arr[i][0];//аргумент последнего перед сменой знака значения функции
			arr_func_change_sign[iter2][1] = arr[i + 1][0];//аргумент другого знака
			printf("----------------------------\na=%.3f \t b=%.3f\n", arr_func_change_sign[iter2][0], arr_func_change_sign[iter2][1]);
			iter2++;
		}
	}
	
	//метод хорд
	printf("----------------------------\n");
	printf("Metod hord :\t");
	chord(arr_func_change_sign[1][0], arr_func_change_sign[1][1]);

	//метод половинного деления
	printf("----------------------------\n");
	printf("Metod polov.del :\t"); 
	dichotomy(arr_func_change_sign[1][0], arr_func_change_sign[1][1]);
	
	return 0;
}

void chord(double a, double b)
{
	double x_a = a;
	double x_b = b;

	double f_a = equation(x_a);
	double f_b = equation(x_b);
	double x;
	int iter = 0;
	do {
		x = (x_a*f_b - x_b * f_a) / (f_b - f_a);

		if (f_a*equation(x) < 0) {
			x_b = x;
		}
		else {
			x_a = x;
		}
		iter++;
	} while (fabs(equation(x)) >= eps);
	printf("Root is %f\t", x);
	printf("Solved for %d iter.\n", iter);
	return;
}
void dichotomy(double a, double b)//метод половинного деления
{
	double x_a = a;
	double x_b = b;
	double f_a = equation(x_a);
	double f_b = equation(x_b);
	double x_mid, f_mid;
	int iter = 0;
	do {
		x_mid = (x_a + x_b) / 2;
		f_mid = equation(x_mid);
		
		if ((f_a*f_mid) < 0) {
			x_b = x_mid;
		}
		else {
			x_a = x_mid;
		}
		iter++;
	} while ( fabs ( equation(x_mid) ) > eps );
	
	printf("Root is %f\t", x_mid);
	printf("Solved for %d iter.\n", iter);
	return ;
}
