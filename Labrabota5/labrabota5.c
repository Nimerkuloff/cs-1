/*
‘ункци€ прибавлени€ одной строки, умноженной на число, к другой строке.
ћатрица целых чисел.( ƒинамический массив многомерных данных)
ѕрототип функции: int** func(int ** matrix, int m, int n, int n1, int n2, int val);
*/
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string.h>
using namespace std;
void func(int m, int n, int n1, int n2, int val) {
	int **ary;
	const unsigned int DIM1 = m;
	const unsigned int DIM2 = n;
	// создание
	ary = new int *[DIM1];    // массив указателей 
	for (int i = 0; i < DIM1; i++) {
		ary[i] = new int[DIM2];     // инициализаци€ указателей
	}
	// работа с массивом
	for (int i = 0; i < DIM1; i++) {
		for (int j = 0; j < DIM2; j++) {
			printf("arr[%d][%d]=", i, j);
			cin >> ary[i][j];
		}
	}
	printf("Before\n");//вывод матрицы до преобразований 
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ary[i][j] << " ";
		cout << endl;
	}
	// прибавление строк
	for (int i = 0; i < DIM2; i++) {
		ary[n2][i] = ary[n1][i] * val;
	}
	printf("After\n");//вывод матрицы после преобразований 
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ary[i][j] << " ";
		cout << endl;
	}
	return;
}
int main()
{
	int m, n, n1, n2, val;
	printf("How many rows?\n");
	do
	{
		printf("(integers only)");
		cin >> m;
	} while (isdigit(m) == 0);

	printf("How many columns?\n");
	do
	{
		printf("(integers only)");
		cin >> n;
	} while (isdigit(n) == 0);


	printf("First row: ");
	cin >> n1;
	if ((n1 < 0) || (n1 > m)) {
		printf("Bad number!\n");
		do {
			printf("Try again\n");
			cin >> n1;
		} while (((n1 < 0) || (n1 > m)) == 1);
	}
	printf("Second row: ");
	cin >> n2;
	if ((n2 < 0) || (n2 > m)) {
		printf("Bad number!\n");
		do {
			printf("Try again\n");
			cin >> n2;
		} while (((n2 < 0) || (n2 > m)) == 1);
	}
	printf("Value:");
	cin >> val;

	func(m, n, n1, n2, val);
	return 0;
}