#include <stdlib.h>
#include <stdio.h>
//#include <iostream>
int main{
	int rows, cols;
	int ** pMatrix;
	//input
	pMatrix=InputMtx(rows,cols);
	OutputMtx=Mtx(pMatrix,rows,cols);
	return 0;
}
//input function
int ** InputMtx(int&i,int&c){
	int** pM;
		//1.
	printf("row count");
	scanf("%d",%r);
	printf("cols count");
	scanf("%d",%c);
		//2.I.
	pM=new int*[r];
		//2.II
	for (int i=0; i<r; i++){
	pM[i]=new int[c];
	}
		//3
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("M[%d][%d]",i,j);
			scanf("%d",&pM[i][j]);
		}
	}
		//4
	return pM;	
}

void OutputMtx(int**M,int r,int c){
	for (int i=0;i<r;i++){
		for(int j=0;j<c;j++){
		printf("M[%d][%d]"=%d,i,j,M[i][j]);
		printf("\n");
		}
	}
}
