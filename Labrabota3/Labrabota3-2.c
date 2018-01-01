/*Функция переписывает строку.
Если она находит в строке число, то вместо него она переписывает в выходную строку
соответствующее по счету слово из входной строки.
(например, "aaa bb1bb cc2cc" - "aaa bbaaabb ccbb1bbcc").
Вывести результат на экран.
*/
#include "stdafx.h" 
#include "stdio.h" 
#include "stdlib.h" 

int main()
{
	char str_in[15];
	char str_out[1024];
	char space = ' ';
	for (int i = 0; i < 15; i++) {
	scanf("%c", &str_in[i]);
	}
	int i_str_out=0;

	for (int i_str_in = 0; i_str_in<15; i_str_in++) {
		// если этот символ - цифра
		if (str_in[i_str_in] >= '1' && str_in[i_str_in] <= '9') {
			int num = str_in[i_str_in] - '0';
			int space_count = num - 1;
			int space_pos = 0;
			int space_iter = 0;
			if (num == 1) {
				int iter = 0;
				int i_copy = i_str_in;
				while (str_in[iter] != space) {
					str_out[i_copy] = str_in[iter];
					iter++;
					i_copy++;
				}
				i_str_out = i_copy;
			}else{
				//ищу индекс пробела перед num-ым словом
				while (space_iter != space_count) {
					if (str_in[space_pos] == space) {
						space_iter++;
					}
					space_pos++;
				}
				//копирую num-ное слово 
				int iter = 0;
				int word_start = space_pos ;
				while ((str_in[word_start+iter]) != space) {
					str_out[i_str_out + iter] = str_in[word_start + iter];
					iter++;
				}
				i_str_out += iter;
			}
		}
		// копирую не цифру
		else {
			str_out[i_str_out] = str_in[i_str_in];
			i_str_out++;
		}
	}
	
	str_out[i_str_out + 1] = '\0';
	int g = 0;
	do {
		printf("%c", str_out[g]);
		g++;
	} while (str_out[g+1] != '\0');
	printf("\n");

}
