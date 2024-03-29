﻿/*
ЗАДАНИЕ  НА РАБОТУ

- разработать шаблон структуры хранения информации;
- выбрать размер статического массива структур;
TODO- организовать ввод данных в массив структур и вывод результата обработки;
TODO- составить алгоритмы и написать функции выполнения заданных действий.

ВАРИАНТЫ  ЗАДАНИЙ
В справочной аэропорта хранится расписание вылета самолетов на следующие сутки. 
Для каждого рейса указаны: номер рейса, тип самолета, пункт назначения, время вылета.
Вывести все номера рейсов, типы самолетов и время вылета в заданный пункт назначения 
в порядке возрастания времени вылета.
*/
#pragma hdrstop
#include "stdafx.h"
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	int check;
	char buffer[20] = {};
	struct flight
	{
		char flight_number[20];
		char plane[20];
		char destination[20];
		struct {
			int h;
			int min;
		} departure;
	};

	int n = 0;
	cout << "Chislo zapisei - ";
	cin >> n;

	flight *ptrFlights = new flight[n];

	//ввод записей
	for (int i = 0; i < n; i++) {

		printf("Enter [%d] flight number\n", i);
		scanf("%s", buffer);
		strcpy(ptrFlights[i].flight_number, buffer);

		printf("Enter [%d] flight plane\n", i);
		scanf("%s", buffer);
		strcpy(ptrFlights[i].plane, buffer);

		printf("Enter [%d] flight destination\n", i);
		scanf("%s", buffer);
		strcpy(ptrFlights[i].destination, buffer);

		printf("Enter [%d] flight departure", i);
		printf(" hour - \n");
		do {
			printf("Integers from 0 to 23 (including 0,23) only!\n");
			scanf("%d", &ptrFlights[i].departure.h);
		} while (ptrFlights[i].departure.h < 0 || ptrFlights[i].departure.h > 23);

		printf("Minutes - ");
		do {
			printf("Integers from 1 to 59 (including 1,59) only!\n");
			check = scanf("%d", &ptrFlights[i].departure.min);
		} while (ptrFlights[i].departure.min < 1 || ptrFlights[i].departure.min > 59);
	}
	//сортировка записей
	int tmp = 0;
	char tmp_str[20] = {};
	for (int i = n - 1; i >= 0; i--) {

		for (int j = 0; j < i; j++) {
			if ((ptrFlights[j].departure.h + ptrFlights[j].departure.min) >(ptrFlights[j + 1].departure.h + ptrFlights[j + 1].departure.min)) {

				tmp = ptrFlights[j].departure.h;
				ptrFlights[j].departure.h = ptrFlights[j + 1].departure.h;
				ptrFlights[j + 1].departure.h = tmp;

				tmp = ptrFlights[j].departure.min;
				ptrFlights[j].departure.min = ptrFlights[j + 1].departure.min;
				ptrFlights[j + 1].departure.min = tmp;


				strcpy(tmp_str, ptrFlights[j].destination);
				strcpy(ptrFlights[j].destination, ptrFlights[j + 1].destination);
				strcpy(ptrFlights[j + 1].destination, tmp_str);


				strcpy(tmp_str, ptrFlights[j].plane);
				strcpy(ptrFlights[j].plane, ptrFlights[j + 1].plane);
				strcpy(ptrFlights[j + 1].plane, tmp_str);

				strcpy(tmp_str, ptrFlights[j].flight_number);
				strcpy(ptrFlights[j].flight_number, ptrFlights[j + 1].flight_number);
				strcpy(ptrFlights[j + 1].flight_number, tmp_str);
			}
		}
	}
	//вывод записей
	for (int i = 0; i < n; i++) {
		cout << "flight: " << ptrFlights[i].flight_number;
		cout << "\tboard: " << ptrFlights[i].plane;
		cout << "\tdest: " << ptrFlights[i].destination;
		cout << "\th: " << ptrFlights[i].departure.h;
		cout << "\tm: " << ptrFlights[i].departure.min;
		cout << "\n";

	}
	system("PAUSE");
	return 0;
}
