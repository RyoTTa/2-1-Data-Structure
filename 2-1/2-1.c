#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

void main(void){

	int *ary[3];
	int a=2,b=3,c=4;

	ary[0]=&a;
	ary[1]=&b;
	ary[2]=&c;

	printf("포인터 배열의 배열요소를 이용한 a,b,c 출력\n");
	
	printf("a : %d, b : %d, c : %d\n",*ary[0],*ary[1],*ary[2]);
}