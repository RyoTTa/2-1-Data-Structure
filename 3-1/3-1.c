#include <stdio.h>
#include <stdlib.h>

//2015114398 �̿�ȣ
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

int sumAry1D_f1( int ary[], int size ); // �迭�Ķ����, �迭ũ��  // ����
int sumAry1D_f2( int *ary,  int size ); // �迭������, �迭ũ��
int sumAry1D_f3( int ary[6],  int size ); 

int main(void) 
{
	int ary1D[ ] = {1, 2, 3, 4, 5, 6};
	return 0;
}

	printf("sumAry1D_f1() %d\n", sumAry1D_f1(ary1D,6));
	printf("sumAry1D_f2() %d\n", sumAry1D_f2(ary1D,6));
	printf("sumAry1D_f3() %d\n", sumAry1D_f3(ary1D,6));


int sumAry1D_f1( int ary[], int size ){

	int i, result=0;

	for(i=0;i<size;i++){
		result=result+ary[i];
	}
	return result;
}

int sumAry1D_f2( int *ary,  int size ){

	int i, result=0;

	for(i=0;i<size;i++){
		result=result+*(ary++);
	}
	return result;
}

int sumAry1D_f3( int ary[6],  int size ){

	int i, result=0;

	for(i=0;i<size;i++){
		result=result+ary[i];
	}
	return result;
}

