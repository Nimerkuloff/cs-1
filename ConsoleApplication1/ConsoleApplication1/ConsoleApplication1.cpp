/*
В файле хранится текст из произвольного количества строк (длина каждой строки не более 80 символов).
Прочитать содержимое файла и записать его в массив строк. Вывести строки на экран,
предварительно заменив заданное пользователем слово (с клавиатуры) на замену.
Организовать обработку ошибок и некорректного ввода.
*/

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#define STRLEN 81  
using namespace std;


int main()
{
	//проверяю наличие hello.txt
	int lines_count = 0;
	FILE *myfile;
	myfile = fopen("\hello.txt", "r");
	if (myfile == NULL) {
		perror("\hello.txt");
		return 1;
	}

	//считаю строки в hello.txt
	while (!feof(myfile))
	{
		if (fgetc(myfile) == '\n') {
			lines_count++;
		}

	}

	//выделение памяти под массив строк 
	char** strMtx = new char*[lines_count];
	for (int i = 0; i < lines_count; i++) {
		strMtx[i] = (char*)calloc(STRLEN, sizeof(char));
	}

	//читаю hello.txt в массив строк
	int iter = 0;
	fclose(myfile);
	myfile = fopen("\hello.txt", "r");
	char ch;
	while (iter<lines_count)
	{
		int j = 0;
		do {
			ch = fgetc(myfile);
			strMtx[iter][j] = ch;
			j++;
		} while ((j < 80) && (ch != '\n'));
		iter++;
	}
	fclose(myfile);

	//спрашиваю ЧТО (chto_menaem) и НА ЧТО (na_chto_menaem) меняем	
	char chto_menaem[81];
	char na_chto_menaem[81];
	printf("Chto menyaem?\n");
	cin >> chto_menaem;
	printf("Na chto menyaem?\n");
	cin >> na_chto_menaem;
	printf("-------------------------------------\n");

	//замена всех вхождений одной подстроки на другую
	long sLen;
	long sPos;
	char sBuf[1024];
	for (int i = 0; i < lines_count; i++) {

		//strlen возвращает количество символов в строке до первого вхождения символа конца строки.
		//strstr возращает NULL – если строка strA не входит в строку strB, указатель на первое вхождение строки strA в строку strB.
		//strcat возвращает указатель на массив, в который добавлена строка.

		//проверим, входит ли chto_menaem в i-ую строку
		char * s = strstr(strMtx[i], chto_menaem);

		//пока входит
		while (s) {
			//присвоим sLen длину i-той строки
			sLen = strlen(strMtx[i]);

			//присвоим sPos количество символов ДО вхождения chto_menaem в i-ую строку
			//(то есть, sPos - номер первой буквы chto_menaem в i-ой строке)
			sPos = sLen - strlen(s);

			//поместим в sBuf символы ПОСЛЕ вхождения chto_menaem
			strcpy(sBuf, s + strlen(chto_menaem));

			//разделим i-ую строку из файла на: 1) строку с символами ДО вхождения chto_menaem 
			//									2) строку с  chto_menaem и остальными символами
			strMtx[i][sPos] = '\0';

			//добавим к строке 1) содержимое na_chto_menaem
			strcat(strMtx[i], na_chto_menaem);
			//и еще добавим sBuf
			strcat(strMtx[i], sBuf);

			//проверим входит ли chto_menaem в измененную строку снова
			s = strstr(strMtx[i], chto_menaem);
		}

		cout << strMtx[i];
	}


	//убираю за собой
	for (int i = 0; i < lines_count; i++)
		free(strMtx[i]);
	delete[] strMtx;

	return 0;
}

