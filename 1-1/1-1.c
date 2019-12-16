#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

void main(void){

	int ary[3]={8,2,8}, *p;

	p=ary;

	printf("ary를 이용한 출력\n");
	printf("%d %d %d\n\n",ary[0],ary[1],ary[2]);

	printf("p를 이용한 출력\n");
	printf("%d %d %d\n",*p,*(p+1),*(p+2));
}