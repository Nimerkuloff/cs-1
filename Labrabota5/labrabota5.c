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
#include<limits>
using namespace std;
void func(int rows, int cols, int n1, int n2, int val) {
	int **ary;
	const unsigned int DIM1 = rows;	//строки
	const unsigned int DIM2 = cols;	//столбцы
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
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << ary[i][j] << " ";
		}
		cout << endl;
	}

	// прибавление строк
	for (int i = 0; i < DIM2; i++) {
		ary[n2][i] += ary[n1][i] * val;
	}
	printf("After\n");//вывод матрицы после преобразований 
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			cout << ary[i][j] << " ";
		}
		cout << endl;
	}
	return;
}
int main()
{
	int m, n, n1, n2, val;
	printf("How many rows?\n");
	while (!(cin >> m)) {
		// Reset the input:
		cin.clear();
		// Get rid of the bad input before return was pressed:
		while (cin.get() != '\n') {
			continue;
		}
		// Ask user to try again:
		cout << "Please enter a number:  ";
	}

	printf("How many columns?\n");
	while (!(cin >> n)) {
		// Reset the input:
		cin.clear();
		// Get rid of the bad input before return was pressed:
		while (cin.get() != '\n') {
			continue;
		}
		// Ask user to try again:
		cout << "Please enter a number:  ";
	}

	printf("First row: ");
	cin >> n1;
	if ((n1 < 0) || (n1 >= m)) {
		printf("Bad number!\n");
		do {
			printf("Try again\n");
			cin >> n1;
		} while (((n1 < 0) || (n1 >= m)) == 1);
	}

	printf("Second row: ");
	cin >> n2;
	if ((n2 < 0) || (n2 >= m)) {
		printf("Bad number!\n");
		do {
			printf("Try again\n");
			cin >> n2;
		} while (((n2 < 0) || (n2 >= m)) == 1);
	}

	printf("Value:");
	cin >> val;

	func(m, n, n1, n2, val);
	return 0;
}