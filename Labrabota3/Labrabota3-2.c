/*������� ������������ ������.
���� ��� ������� � ������ �����, �� ������ ���� ��� ������������ � �������� ������
��������������� �� ����� ����� �� ������� ������.
(��������, "aaa bb1bb cc2cc" - "aaa bbaaabb ccbb1bbcc").
������� ��������� �� �����.
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
	if (num == 1) {//���� ������� ������ �����
		while ((str[i] != ' ') && (i != str.size())) {
			out.insert(i, str.substr(i, 1));
			i++;
		}
	}
	else if (num > 1) {//���� ������� �� ������ �����
		int b = 0; int c = 0;
		while (b != (num - 1)) {//����� ����� ������� �-�� �����, ��� ������� (�-1)-��� �������
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
		//������ ����� ��� �������
		if (isdigit(str[i]) == false) {			//���� ������ �� �����, ��
			out.insert(i_out, str.substr(i, 1));//������� �� ������� i_out-�� �������� �������� ������ i-�� ������� ������� ������
			i_out++;
		}
		else if ((str[i] - '0') <= wordsCount(str)) {				 //���� ������ - ����� - �, ��
			out.insert(i_out, selectWordByNumber(str[i] - '0', str));//������ �����, ������� � �������� ������ ����� �-���
			someSize = selectWordByNumber(str[i] - '0', str).size();   //������� ����� ������� �����
			i_out += someSize;										 //�������� ������� ��� ������� ������(������� �������� �� ��������� �������������) 
		}
		else { out.insert(i_out, str.substr(i, 1)); i_out++; }       //���� ������ - �����, �� � �������� ������, ��� ���� � �������� ������, �� ������ ������ � � ������� ������ 
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
