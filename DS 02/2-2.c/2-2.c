#include <stdio.h>
#include <stdlib.h>

//2015114398 �̿�ȣ
//"������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�."

int *func(int num){

	int *pNum = (int*)malloc(sizeof(int));
	*pNum = num;
	printf("%d\n",*pNum);

	return pNum;
}

int main(void){

	int num=1;
	int *pNum=func(num);
	printf("%d\n",num);
	free(pNum);

	return 0;
}