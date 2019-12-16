#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

void main(void){

	int ary[2][2][3]={1,2,3,4,5,6,7,8,9,10,11,12}, *p;
	int i,j,k;

	p=&ary[0][0][0];

	printf("ary를 이용한 출력\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(k=0;k<3;k++){
				printf("%4d ",ary[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("p를 이용한 출력\n");
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