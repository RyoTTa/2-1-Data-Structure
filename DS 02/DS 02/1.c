#include <stdio.h>
#include <stdlib.h>

//2015114398 �̿�ȣ
//"������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�."
void swap1(int a,int b);
void swap2(int *a,int *b);
void swap3(int **a,int **b);

int main(void){

	int a,b;

	int *pa=&a;
	int **ppa=&pa;

	int *pb=&b;
	int **ppb=&pb;

	a=1;b=2;swap1(a,b);
	printf("After calling swap1(a,b),a:%d, b:%d\n\n",a,b);

	a=1;b=2;swap2(&a,&b);
	printf("After calling swap2(&a,&b),a:%d, b:%d\n\n",a,b);

	a=1;b=2;swap2(pa,pb);
	printf("After calling swap2(pa,pb),a:%d, b:%d\n\n",a,b);

	a=1;b=2;swap3(&pa,&pb);
	printf("After calling swap3(&pa,&pb),a:%d, b:%d\n\n",a,b);

	a=1;b=2;swap3(ppa,ppb);
	printf("After calling swap3(ppa,ppb),a:%d, b:%d\n\n",a,b);

	return 0;
}

void swap1(int a,int b){

	int temp;

	temp=a;
	a=b;
	b=temp;
}

void swap2(int *a,int *b){

	int temp;

	temp=*a;
	*a=*b;
	*b=temp;
}

void swap3(int **a,int **b){

	int temp;

	temp=**a;
	**a=**b;
	**b=temp;
}