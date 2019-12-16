#include<stdio.h>
#include<stdlib.h>

//2015114398 이용호
//"본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다."

int *func1(){
	int *pNum=(int*)malloc(sizeof(int));

	*pNum=0;

	return pNum;
}
int *func2(int *pNum){

	*pNum=100;

	return pNum;
}
int **func3(int **pNum){

	**pNum=200;

	return pNum;
}
int main(void){

	int *pNum=func1();

	printf("%d\n",*pNum);
	printf("%d\n",*func2(pNum));
	printf("%d\n",**func3(&pNum));
	free(pNum);

	return 0;
}