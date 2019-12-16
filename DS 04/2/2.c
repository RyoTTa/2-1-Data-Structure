#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int sumAry3D_f1(int ary3D[2][3][4],int x,int y,int z);
int sumAry3D_f2(int ary3D[][3][4],int x,int y,int z);
int sumAry3D_f3(int (*ary3D)[3][4],int x,int y,int z);
int sumAry3D_f4(int ***ary,int x,int y,int z);
int sumAry3D_f5(int ****ary,int x,int y,int z);
void freeAry3D(int ***ary,int x,int y);


int main (void){

	int ary3D[2][3][4]={{{1,2,3,4},{2,3,4,5},{3,4,5,6}},{{4,5,6,7},{5,6,7,8},{6,7,8,9}}};
	int s,r,c;
	int sum=0;
	int ***ary;
	
	ary=(int***)malloc(sizeof(int**)*2);

	for(r=0;r<2;r++){
		ary[r]=(int**)malloc(sizeof(int*)*3);
	}
	for(r=0;r<2;r++){
		for(s=0;s<3;s++){
			ary[r][s]=(int*)malloc(sizeof(int)*4);
		}
	}

	for(s=0;s<2;s++){
		for(r=0;r<3;r++){
			for(c=0;c<4;c++){
				ary[s][r][c]=s+r+c;
			}
		}
	}

	printf("sumAry3D_f1() %d\n",sumAry3D_f1(ary3D,2,3,4));
	printf("sumAry3D_f2() %d\n",sumAry3D_f2(ary3D,2,3,4));
	printf("sumAry3D_f3() %d\n",sumAry3D_f3(ary3D,2,3,4));

	printf("sumAry3D_f4() %d\n",sumAry3D_f4(ary,2,3,4));
	printf("sumAry3D_f5() %d\n",sumAry3D_f5(&ary,2,3,4));


	freeAry3D(ary,2,3);

}
int sumAry3D_f1(int ary3D[2][3][4],int x,int y,int z){

	int i=0,j=0,k=0,sum=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			for(k=0;k<z;k++){
				sum=sum+ary3D[i][j][k];
			}
		}
	}
	return sum;
}
int sumAry3D_f2(int ary3D[][3][4],int x,int y,int z){

	int i=0,j=0,k=0,sum=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			for(k=0;k<z;k++){
				sum=sum+ary3D[i][j][k];
			}
		}
	}
	return sum;
}
int sumAry3D_f3(int (*ary3D)[3][4],int x,int y,int z){

	int i=0,j=0,k=0,sum=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			for(k=0;k<z;k++){
				sum=sum+ary3D[i][j][k];
			}
		}
	}
	return sum;

}
int sumAry3D_f4(int ***ary,int x,int y,int z){

	int i=0,j=0,k=0,sum=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			for(k=0;k<z;k++){
				sum=sum+*(**(ary+i)+j)+k;
			}
		}
	}
	return sum;
}
int sumAry3D_f5(int ****ary,int x,int y,int z){

	int i=0,j=0,k=0,sum=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			for(k=0;k<z;k++){
				sum=sum+*(**(*ary)+i+j)+k;
			}
		}
	}
	return sum;
}
void freeAry3D(int ***ary,int x,int y){

	int i=0,j=0;

	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			free(ary[i][j]);
		}
	}
	free(ary);

	printf("3D array - free!\n");
}