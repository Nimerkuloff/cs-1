/*
В файле хранится текст из произвольного количества строк (длина каждой строки не более 80 символов).
Прочитать содержимое файла и записать его в массив строк. Вывести строки на экран,
предварительно заменив заданное пользователем слово (с клавиатуры) на замену.
Организовать обработку ошибок и некорректного ввода.
*/
#pragma once
#pragma hdrstop
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define STRLEN 81  
using namespace std;
char** getData(int* size)//заполняю массив строками из файла
{
	FILE*  file;
	char** text = NULL;
	int    last;
	char   buf[STRLEN];
	*size = 0;
	file = fopen("hello.txt", "rt");
	while (fgets(buf, STRLEN, file) != NULL)
	{
		last = strlen(buf) - 1;
		if (buf[last] == '\n')
			buf[last] = '\0';
		text = (char**)realloc(text, sizeof(char*) * (*size + 1));
		text[*size] = (char*)malloc(sizeof(char) * (strlen(buf) + 1));
		strcpy(text[(*size)++], buf);
	}
	fclose(file);
	return text;
}

int lines_count() {

	int lines_count = 0;
	FILE *myfile;
	myfile = fopen("hello.txt", "r");

	while (!feof(myfile))
	{
		if (fgetc(myfile) == '\n') {
			lines_count++;
		}
	}
	return lines_count;
}

int main()
{

	char** data;
	char*  filename;
	int    i;

	int lines_qty = lines_count();

	data = getData(&lines_qty);

	char chto_menaem[81];
	char na_chto_menaem[81];
	printf("Chto menyaem?\n");
	cin >> chto_menaem;
	printf("Na chto menyaem?\n");
	cin >> na_chto_menaem;

	long sLen;
	long sPos;
	char sBuf[1024];
	for (int i = 0; i < lines_qty; i++) { //замена всех вхождений одной подстроки на другую
		char * s = strstr(data[i], chto_menaem);
		while (s) {
			sLen = strlen(data[i]);
			sPos = sLen - strlen(s);
			strcpy(sBuf, s + strlen(chto_menaem));
			data[i][sPos] = '\0';
			strcat(data[i], na_chto_menaem);
			strcat(data[i], sBuf);
			s = strstr(data[i], chto_menaem);
		}
		printf("%s\n", data[i]);
	}



	for (i = 0; i < lines_qty; i++)//убираю за собой
		free(data[i]);
	free(data);
	return 0;
}
