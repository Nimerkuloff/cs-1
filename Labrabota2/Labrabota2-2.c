// Labrabota22.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma hdrstop
int main(void)
{
	int number, sum = 0;
	printf("Type a number\n");
	scanf("%3i",&number);
	int backup = number;
	if ((number > 99) && (number < 1000)) {
		while (number != 0) {
			sum += number % 10;
			number /= 10;
		}

		if ((pow(backup, 2) == (pow(sum,3)))) {
			printf("Are equivalent");
			system("PAUSE");
		}
		else{printf("sorry...\n");}
}	else {printf("Try with a valid number next time...\n");}
	return 0;
	}
