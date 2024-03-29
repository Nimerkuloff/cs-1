#pragma once
#pragma hdrstop
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void intToBin(unsigned x);

unsigned getSignFloat(unsigned k);

unsigned getMantFloat(unsigned k);

unsigned getСharacFloat(unsigned k);

unsigned getIntpartFloat(unsigned long long k, int p);

unsigned getFracpartFloat(unsigned long long k, int p);

int main()
{
	union 
	{
		unsigned toUnsig;
		int toInt;
		float value;
	}floatConv;

	floatConv.value;
	printf("Please, input a float number\n");
	scanf("%f",&floatConv.value);
	if ((getSignFloat(floatConv.toUnsig)) == 1) {
		printf("Sign is -\n");
	}
	else {
		printf("Sign is +\n");
	}
	printf("Characteristic is %u\n", getСharacFloat(floatConv.toUnsig));
	printf("Mantissa is %u\n",getMantFloat(floatConv.toUnsig));
	
	int order = getСharacFloat(floatConv.toUnsig) - 127;
	printf("Integer part  is %d\n", getIntpartFloat(floatConv.toUnsig,order));
	printf("Fractional part  is %u\n", getFracpartFloat(floatConv.toUnsig, order));
	
	return 0;
}

unsigned getSignFloat(unsigned k) {
	k >>= 31;
	return k;
}

unsigned getMantFloat(unsigned k)
{
	{
		k <<= 9;
		k >>= 9;
		return k;
	}
}

unsigned getСharacFloat(unsigned k)
{
	{
		k <<= 1;
		k >>= 1;
		k >>= 23;
		return k;
	}

}

void intToBin(unsigned x)
{
	int i;
	char a[32];

	for (i = 0; i < 32; i++) {
		a[i] = x % 2;  x = x / 2;
	}
	printf("\n");
	for (i = 31; i >= 0; i--) {
		printf("%d", a[i]);
	}
	return;
}

unsigned getIntpartFloat(unsigned long long k, int p)  // p - порядок
{
	
	unsigned long long a = 23 - p;
	k >>= a;
	return k;
}
unsigned getFracpartFloat(unsigned long long k, int p)
{
	unsigned long long b = k;

	k <<= 41 + p;                           // 41=9+32. 
	k >>= 41 + p;
	return k;
}
