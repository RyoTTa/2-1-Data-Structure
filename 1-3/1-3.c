#include <stdio.h>
#include <stdlib.h>

//2015114398 �̿�ȣ
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

void main(void){

	int ary[2][2][3]={1,2,3,4,5,6,7,8,9,10,11,12}, *p;
	int i,j,k;

	p=&ary[0][0][0];

	printf("ary�� �̿��� ���\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(k=0;k<3;k++){
				printf("%4d ",ary[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("p�� �̿��� ���\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(k=0;k<3;k++){
				printf("%4d ",*(p++));
			}
			printf("\n");
		}
		printf("\n");
	}
}