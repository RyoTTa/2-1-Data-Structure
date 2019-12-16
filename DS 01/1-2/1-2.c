#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

void main(void){

	int ary[2][3]={4,2,3,5,2,3}, *p;
	int i,j;

	p=&ary[0][0];

	printf("ary를 이용한 출력\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("%d ",ary[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("p를 이용한 출력\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("%d ",*(p++));
		}
		printf("\n");
	}
}