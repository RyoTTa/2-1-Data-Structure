#include <stdio.h>
#include <stdlib.h>

//2015114398 �̿�ȣ
//"������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�."

int *alloc(int num){

	int *pum=(int*)malloc(sizeof(int)*num);

	return pum;
}

void input(int *pNum,int num, FILE *fpIn){

	int i;

	for(i=0;i<10;i++){
		fscanf(fpIn,"%d ",&pNum[i]);
	}
}

void increase(int *pNum,int num){

	int i;

	for(i=0;i<10;i++){
		pNum[i]=pNum[i]+1;
	}
}

void output(int *pNum,int num, FILE *fpOut){

	int i;

	fprintf(fpOut,"%d\n",num);

	for(i=0;i<10;i++){
		fprintf(fpOut,"%d ",pNum[i]);
	}
}

int main(void){

	int num,*pNum;
	int i;

	FILE *fpIn = fopen("input.txt","r");
	FILE *fpOut = fopen("output.txt","w");

	fscanf(fpIn,"%d",&num);
	pNum=alloc(num);
	input(pNum,num,fpIn);
	increase(pNum,num);
	output(pNum,num,fpOut);

	free(pNum);
	fclose(fpIn);
	fclose(fpOut);

	return 0;
}