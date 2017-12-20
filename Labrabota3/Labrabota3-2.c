/*Функция переписывает строку.
Если она находит в строке число, то вместо него она переписывает в выходную строку
соответствующее по счету слово из входной строки.
(например, "aaa bb1bb cc2cc" - "aaa bbaaabb ccbb1bbcc").
Вывести результат на экран.
*/
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#pragma hdrstop
#include <iostream>



using namespace std;
int countWords(char *str) {
	char space = ' ';
	int numOfSpaces = 0;
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] == space) {
			numOfSpaces++;
		}
	}
	if (numOfSpaces == 0) {
		return 1;
	}
	else {
		return numOfSpaces;
	}
}

char* selectWordByNumber(int num, char *str) {
	char *outStr;
	outStr = (char *)malloc(200 * sizeof(char));
	char space = ' ';
	int tabCount = 0;
	int i = 0;
	if (num == 1) {
		while (str[i] != space) {
			strcpy(outStr, &str[i]);
			i++;
		}
	}
	else if (num>1) {
		while (tabCount < (num - 1)) {
			if (str[i] == space) {
				tabCount++;
			}
			i++;
		}
		i++;
		while (str[i] != space) {
			strcpy(outStr, &str[i]);
			i++;
			outStr++;
		}
	}
	outStr[i + 1] = '\0';
	return outStr;
}


//char doTheJob(char *str) {}
int main()
{
	char str;
	char *pointerToString;
	cout << "Dai stroku\n";
	cin >> str;

	pointerToString = &str;
	//doTheJob(pointerToString);
	char *out = selectWordByNumber(2, pointerToString);
	int g = 0;
	while (out[g] != '\0') {
		cout << out[g];
		g++;
	}

	return 0;

}
