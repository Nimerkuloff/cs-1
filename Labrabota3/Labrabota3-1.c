//Ищу длиннейшую последовательность одинаковых элементов массива
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
//#pragma hdrstop
#include <iostream>
using namespace std;
int main()
{
	printf("A[%i]=\n", max);
	int counter = 1, max = 0;
	const int A = 10;
	int array[A];
	cin >> array[0];
	for (int i = 1; i < A; i++) {
		cin >> array[i];

		if (array[i] == array[i - 1]) {
			counter++;
		}
		else { counter = 1; }

		if (counter >= max) {
			max = counter;
		}

	}
	printf("Answer is %i\n", max);
	return 0;
}
