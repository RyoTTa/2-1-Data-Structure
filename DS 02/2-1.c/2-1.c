#include <stdio.h>
#include <stdlib.h>

//2015114398 �̿�ȣ
//"������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�."

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