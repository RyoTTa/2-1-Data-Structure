#include <stdio.h>
#include <stdlib.h>

//2015114398 �̿�ȣ
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

void main(void){

	int *ary[3];
	int a=2,b=3,c=4;

	ary[0]=&a;
	ary[1]=&b;
	ary[2]=&c;

	printf("������ �迭�� �迭��Ҹ� �̿��� a,b,c ���\n");
	
	printf("a : %d, b : %d, c : %d\n",*ary[0],*ary[1],*ary[2]);
}