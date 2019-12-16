#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

void add(int **a,int **b,int **c,int rows, int cols){

	int i,j;

	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}

void printf2dArray(int **ary,int rows,int cols){

	int i,j;

	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("%3d ",ary[i][j]);
		}
		printf("\n");
	}

}

void init2dArray(int **ary,int rows,int cols,int x){

	int r,c;

	for(r=0;r<rows;r++){
		for(c=0;c<cols;c++){
			ary[r][c]=r+c+x;
		}
	}
}

int** make2dArray(int rows,int cols){

	int r,c;
	int **ary=(int**)malloc(sizeof(int*)*rows);

	for(r=0;r<rows;r++){
		ary[r]=(int*)malloc(sizeof(int)*cols);
	}
	
	return ary;
}

void freeAry2D(int **ary,int x,int y){

	int i=0,j=0;

	for(i=0;i<x;i++){
		free(ary[i]);
	}
	free(ary);
	
	printf("2d array - free!\n");
}

int main (void){

	int rows=0,cols=0;
	int i=0,j=0;
	int **a,**b,**c;

	printf("Enter row size and column size (ex) 3 4 : ");
	scanf("%d %d",&rows,&cols);

	a=make2dArray(rows,cols);
	init2dArray(a,rows,cols,1);
	printf("matrix A\n");
	printf2dArray(a,rows,cols);

	b=make2dArray(rows,cols);
	init2dArray(b,rows,cols,2);
	printf("matrix B\n");
	printf2dArray(b,rows,cols);

	c=make2dArray(rows,cols);
	add(a,b,c,rows,cols);
	printf("matrix C\n");
	printf2dArray(c,rows,cols);

	freeAry2D(a,rows,cols);
	freeAry2D(b,rows,cols);
	freeAry2D(c,rows,cols);

	return 0;
}