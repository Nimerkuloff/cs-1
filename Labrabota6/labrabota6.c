/*
ЗАДАНИЕ  НА РАБОТУ

- разработать шаблон структуры хранения информации;
- выбрать размер статического массива структур;
TODO- организовать ввод данных в массив структур и вывод результата обработки;
TODO- составить алгоритмы и написать функции выполнения заданных действий.
TODO- предусмотреть защиту от дурака

ВАРИАНТЫ  ЗАДАНИЙ
В справочной аэропорта хранится расписание вылета самолетов на следующие сутки. 
Для каждого рейса указаны: номер рейса, тип самолета, пункт назначения, время вылета.
Вывести все номера рейсов, типы самолетов и время вылета в заданный пункт назначения 
в порядке возрастания времени вылета.
*/
#include "stdafx.h"
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n, check;
	struct flight
	{
		int flight_number;
		char plane[20];
		char destination[20];
		struct {
			int h;
			int min;
		} departure;
	};
	
	
	printf("Skol'ko zapisei?\n");
	cin >> n;
	
	flight ptrFlights[59];
	
	//ввод записей
	for (int i = 0; i < n; i++) { 
		printf("Enter [%d] flight number\n",i);
		cin >> ptrFlights[i].flight_number;

		printf("Enter [%d] flight plane\n", i);
		cin >> ptrFlights[i].plane;

		printf("Enter [%d] flight destination\n", i);
		cin >> ptrFlights[i].destination;

		printf("Enter [%d] flight departure\n", i);
			printf("Hours in 24h format - ");
			do {
				cin >> ptrFlights[i].departure.h;
				check = ptrFlights[i].departure.h;
			} while (check < 0 || check > 23);

			printf("Minutes - ");
			do {
				cin >> ptrFlights[i].departure.min;
				check = ptrFlights[i].departure.min;
			} while (check < 1 || check > 59);

	}
	//сортировка записей
	for (int i = 0; i < n - 1; i++) {
		// сравниваем два соседних элемента.
		for (int j = 0; j < n - i - 1; j++) {
			if (ptrFlights[j].departure.h > 
				ptrFlights[j + 1].departure.h) {

				if(ptrFlights[j].departure.min >
				   ptrFlights[j + 1].departure.min){
		

					int tmp = ptrFlights[j].departure.h;
					ptrFlights[j].departure.h = ptrFlights[j + 1].departure.h;
					ptrFlights[j + 1].departure.h = tmp;

					 tmp = ptrFlights[j].departure.min;
					ptrFlights[j].departure.min = ptrFlights[j + 1].departure.min;
					ptrFlights[j + 1].departure.min = tmp;

					char* tmp_str;
					strcpy(tmp_str, ptrFlights[j].destination);
					strcpy(ptrFlights[j].destination, ptrFlights[j + 1].destination);
					strcpy(ptrFlights[j + 1].destination, tmp_str);

					
					strcpy(tmp_str, ptrFlights[j].plane);
					strcpy(ptrFlights[j].plane, ptrFlights[j + 1].plane);
					strcpy(ptrFlights[j + 1].plane, tmp_str);

					tmp = ptrFlights[j].flight_number;
					ptrFlights[j].flight_number = ptrFlights[j + 1].flight_number;
					ptrFlights[j + 1].flight_number = tmp;
				}
			
			}
		}
	}
	//вывод записей
	for (int i = 0; i < n; i++) {
		printf("h:%d m:%d %d \t2%s \t2%s\n", ptrFlights[i].departure.h,
			ptrFlights[i].departure.min, ptrFlights[i].flight_number,
			ptrFlights[i].plane);
	}
	return 0;
}