#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int sumAry3D_f1( int ary[][2][3], int SEC, int ROW, int COL ); // 배열파라미터 //권장
int sumAry3D_f2( int (*ary)[2][3], int SEC, int ROW, int COL ); // 배열포인터
int sumAry3D_f3( int ary[2][2][3], int SEC, int ROW, int COL );

int main(void) 
{
	int ary3D[ ][2][3] = { {{1, 2, 3}, {4, 5, 6}},{{7, 8, 9}, {10, 11, 12}}};

	printf("sumAry3D_f1() %d\n", sumAry3D_f1(ary3D,2,2,3));
	printf("sumAry3D_f2() %d\n", sumAry3D_f2(ary3D,2,2,3));
	printf("sumAry3D_f3() %d\n", sumAry3D_f3(ary3D,2,2,3));

	return 0;
}

int sumAry3D_f1( int ary[][2][3], int SEC, int ROW, int COL ){

	int i,j,k,result=0;

	for(i=0;i<SEC;i++){
		for(j=0;j<ROW;j++){
			for(k=0;k<COL;k++){
				result=result+ary[i][j][k];
			}
		}
	}
	return result;
}

int sumAry3D_f2( int (*ary)[2][3], int SEC, int ROW, int COL ){

	int i,j,k,result=0;

	for(i=0;i<SEC;i++){
		for(j=0;j<ROW;j++){
			for(k=0;k<COL;k++){
				result=result+(*(*(*(ary+i)+j)+k));
			}
		}
	}
	return result;
}

int sumAry3D_f3( int ary[2][2][3], int SEC, int ROW, int COL ){

	int i,j,k,result=0;

	for(i=0;i<SEC;i++){
		for(j=0;j<ROW;j++){
			for(k=0;k<COL;k++){
				result=result+ary[i][j][k];
			}
		}
	}
	return result;
}

