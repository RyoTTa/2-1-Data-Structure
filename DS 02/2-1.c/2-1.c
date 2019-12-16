#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//"본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다."

void func(int num){

	int *pNum = (int*)malloc(sizeof(int));
	*pNum = num;

	printf("%d\n",*pNum);
	free(pNum);
}

int main(void){

	int num=1;
	func(num);
	printf("%d\n",num);

	return 0;
}