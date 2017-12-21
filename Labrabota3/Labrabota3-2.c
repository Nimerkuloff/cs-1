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

#include <conio.h>
#include <string.h>
#include <string>
using namespace std;


string selectWordByNumber(int num, string str) {
	string out;
	int i = 0;
	if (num == 1) {//если требуют первое слово
		while ((str[i] != ' ') && (i != str.size())) {
			out.insert(i, str.substr(i, 1));
			i++;
		}
	}
	else if (num > 1) {//если требуют не первое слово
		int b = 0; int c = 0;
		while (b != (num - 1)) {//чтобы найти позицию Н-го слова, ищу позицию (Н-1)-ого пробела
			c = str.find(" ", c + 1);
			b++;
		}

		while ((str[c + 1] != ' ') && (c != str.size())) {
			out.insert(i, str.substr(c + 1, 1));
			i++;
			c++;
		}
	}
	return out;
}
int wordsCount(string str) {
	int cntr = 0, j = 0;
	while (j != -1) {
		j = str.find(' ', j + 1);
		cntr++;
	}

	return cntr;
}
string doTheJob(string str) {
	string out;
	int someSize = 1, g = 0, i_out = 0;
	for (int i = 0; i <= str.size(); i++) {
		//раньше здесь был костыль
		if (isdigit(str[i]) == false) {			//если символ не цифра, то
			out.insert(i_out, str.substr(i, 1));//поставь на позицию i_out-го элемента выходной строки i-ый элемент входной строки
			i_out++;
		}
		else if ((str[i] - '0') <= wordsCount(str)) {				 //если символ - цифра - Н, то
			out.insert(i_out, selectWordByNumber(str[i] - '0', str));//возьми слово, которое в исходной строке стоит Н-ным
			someSize = selectWordByNumber(str[i] - '0', str).size();   //вычисли длину взятого слова
			i_out += someSize;										 //подправь счетчик для внешней строки(которая отвечает за результат переписывания) 
		}
		else { out.insert(i_out, str.substr(i, 1)); i_out++; }       //если символ - цифра, но её величина больше, чем слов в исходной строке, то просто добавь её к внешней строке 
	}
	return out;
}



int main()
{
	string s;
	printf("Dai stroku\n");
	getline(cin, s);
	printf("\n");
	cout << doTheJob(s);
	printf("\n");
	return 0;

}
