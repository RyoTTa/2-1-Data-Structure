#include <stdio.h>
#include <stdlib.h>

//2015114398 �̿�ȣ
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

void main(void){

	int ary[2][3]={4,2,3,5,2,3}, *p;
	int i,j;

	p=&ary[0][0];

	printf("ary�� �̿��� ���\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("%d ",ary[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("p�� �̿��� ���\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("%d ",*(p++));
		}
		printf("\n");
	}
}