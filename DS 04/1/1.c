#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int sumAry2D_f1(int ary2D[2][3],int x,int y);
int sumAry2D_f2(int ary2D[][3],int x,int y);
int sumAry2D_f3(int (*ary2D)[3],int x,int y);
int sumAry2D_f4(int **ary,int x,int y);
int sumAry2D_f5(int ***ary,int x,int y);
void freeAry2D(int **ary,int x,int y);


int main (void){

	int ary2D[][3]={{1,2,3},{4,5,6}};
	int r,c;
	int **ary=(int**)malloc(sizeof(int*)*2);


	for(r=0;r<2;r++){
		ary[r]=(int*)malloc(sizeof(int)*3);
	}
	for(r=0;r<2;r++){
		for(c=0;c<3;c++){
			ary[r][c]=r+c;
		}
	}

	printf("sumAry2D_f1() %d\n",sumAry2D_f1(ary2D,2,3));
	printf("sumAry2D_f2() %d\n",sumAry2D_f2(ary2D,2,3));
	printf("sumAry2D_f3() %d\n",sumAry2D_f3(ary2D,2,3));

	printf("sumAry2D_f4() %d\n",sumAry2D_f4(ary,2,3));
	printf("sumAry2D_f5() %d\n",sumAry2D_f5(&ary,2,3));

	freeAry2D(ary,2,3);


}
int sumAry2D_f1(int ary2D[2][3],int x,int y){
	
	int i=0,j=0,sum=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			sum=sum+ary2D[i][j];
		}
	}
	return sum;
}
int sumAry2D_f2(int ary2D[][3],int x,int y){

	int i=0,j=0,sum=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			sum=sum+ary2D[i][j];
		}
	}
	return sum;
}
int sumAry2D_f3(int (*ary2D)[3],int x,int y){

	int i=0,j=0,sum=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			sum=sum+ary2D[i][j];
		}
	}
	return sum;

}
int sumAry2D_f4(int **ary,int x,int y){

	int i=0,j=0,sum=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			sum+=**(ary+i)+j;
		}
	}
	return sum;
}
int sumAry2D_f5(int ***ary,int x,int y){

	int i=0,j=0,sum=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			sum+=(**(*ary)+i+j);
		}
	}
	return sum;
}
void freeAry2D(int **ary,int x,int y){

	int i=0,j=0;

	for(i=0;i<x;i++){
		free(ary[i]);
	}
	free(ary);
	
	printf("2d array - free!\n");
}