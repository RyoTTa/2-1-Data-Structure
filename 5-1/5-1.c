#include <stdio.h>
#include <stdlib.h>

//2015114398 �̿�ȣ
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

int sumAry3D_f1( int ary[][2][3], int SEC, int ROW, int COL ); // �迭�Ķ���� //����
int sumAry3D_f2( int (*ary)[2][3], int SEC, int ROW, int COL ); // �迭������
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
				result=result+(*ary[i][j]+k);
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

