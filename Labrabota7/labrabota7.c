/*
Â ôàéëå õðàíèòñÿ òåêñò èç ïðîèçâîëüíîãî êîëè÷åñòâà ñòðîê (äëèíà êàæäîé ñòðîêè íå áîëåå 80 ñèìâîëîâ).
Ïðî÷èòàòü ñîäåðæèìîå ôàéëà è çàïèñàòü åãî â ìàññèâ ñòðîê. Âûâåñòè ñòðîêè íà ýêðàí,
ïðåäâàðèòåëüíî çàìåíèâ çàäàííîå ïîëüçîâàòåëåì ñëîâî (ñ êëàâèàòóðû) íà çàìåíó.
Îðãàíèçîâàòü îáðàáîòêó îøèáîê è íåêîððåêòíîãî ââîäà.-
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
char** getData(int* size)//çàïîëíÿþ ìàññèâ ñòðîêàìè èç ôàéëà
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
	for (int i = 0; i < lines_qty; i++) { //çàìåíà âñåõ âõîæäåíèé îäíîé ïîäñòðîêè íà äðóãóþ
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



	for (i = 0; i < lines_qty; i++)//óáèðàþ çà ñîáîé
		free(data[i]);
	free(data);
	return 0;
}
