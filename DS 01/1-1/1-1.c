#include <stdio.h>
#include <stdlib.h>

//2015114398 �̿�ȣ
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

void main(void){

	int ary[3]={8,2,8}, *p;

	p=ary;

	printf("ary�� �̿��� ���\n");
	printf("%d %d %d\n\n",ary[0],ary[1],ary[2]);

	printf("p�� �̿��� ���\n");
	printf("%d %d %d\n",*p,*(p+1),*(p+2));
}