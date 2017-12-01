#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stdafx.h"
#include <windows.h>

char function(char *str1, char *str2) {
	char char1, char2;
	for (int i = 0; i < 10; i++) {
		char1 = *(str1 + i);
		char2 = *(str2 + i);
		if (char1 == char2) {
			char1 += 32;
			char2 += 32;
		
		}
	}
	return char1, char2;
}


int main()
{
	char *str1;
	char *str2;

	str1 = (char*)malloc(10 * sizeof(char));
	str2 = (char*)malloc(10 * sizeof(char));

	for (int i = 0; i < 10; i++) {
		printf("%d letter of first sentence is \n", i);
		scanf("%c", str1[i]);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d letter of second sentence is \n", i);
		scanf("%c", str2[i]);
	}
	
	//function(str1, str2);
	
	return 0;
}