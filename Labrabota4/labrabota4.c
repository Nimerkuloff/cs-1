/*
Лабораторная №4
Вводят 2 строки с строчными символами.
Функция переводит символы, общие для обоих строк в верхний регистр.
*/
#pragma warning(suppress : 4996)
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string.h>
using namespace std;
//Преребираю символы из строк. Если они одинаковые, то перевожу их в верхний регистр
void function(char *str1, char *str2) {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (str1[i] == str2[j]) {
				str1[i] -= 32;
				str2[j] -= 32;
			}
		}
	}
	return;
}


int main()
{

	char *p1, *p2;
	//Выделил место под две "строки" по десять символов 
	p1 = (char*)malloc(sizeof(char) * 10);
	p2 = (char*)malloc(sizeof(char) * 10);

	//Немного прибрался
	free(p1);
	free(p2);

	//Ввожу первую строку
	for (int i = 0; i < 10; i++) {
		printf("Please, add a symbol to first string\n");
		cin >> p1[i];
	}
	printf("--------------------\nFirst string is complete!\n--------------------\n");
	//Ввожу вторую десятку
	for (int i = 0; i < 10; i++) {
		printf("Please, add a symbol to second string\n");
		cin >> p2[i];
	}
	printf("--------------------\nSecond string is complete!\n--------------------");
	function(p1, p2);

	//Output
	printf("--------------------\nHere are the results\n--------------------\n ");
	for (int i = 0; i < 10; i++) {
		cout << p1[i];
	}
	printf("   ");
	for (int i = 0; i < 10; i++) {
		cout << p2[i];
	}
	printf("\n");
	return 0;
}
