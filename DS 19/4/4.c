#include <stdio.h>
#include <stdlib.h>
#define SWAP(p,n,s) s=p,p=n,n=s

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다

typedef struct Node{
	int key;
}numNode;

int total=0;
numNode num[20];
int count=0;

void insert(numNode,int i);
void insertionSort();
void makenum();
void printnum();
void outputnum();
void quickSort(int left,int right);
int main(void){

	makenum();
	printf("<<<<<<<<<< Input List >>>>>>>>>>\n");
	printnum();
	printf("execution of quick sort ...\n");
	quickSort(1,total);
	printf("calls of quick sort: %d\n\n",count);
	printf("<<<<<<<<<< Sorted List >>>>>>>>>>\n");
	printnum();
	outputnum();
	return 0;
}
void makenum(){

	FILE *f=fopen("input.txt","r");
	int i=0;

	fscanf(f,"%d",&total);
	for(i=1;i<=total;i++){
		fscanf(f,"%d",&num[i].key);
	}
	fclose(f);
}
void insert(numNode e,int i){

	num[0]=e;
	while(e.key<num[i].key){
		num[i+1]=num[i];
		i--;
	}
	num[i+1]=e;
}
void insertionSort(){

	int j;
	for(j=2;j<=total;j++){
		numNode temp=num[j];
		insert(temp,j-1);
	}
}
void printnum(){

	int i=0;

	for(i=1;i<=total;i++){
		printf("%3d",num[i].key);
	}
	printf("\n");
}
void outputnum(){

	FILE *f=fopen("output.txt","w");
	int i=0;

	fprintf(f,"%d\n",total);
	for(i=1;i<=total;i++){
		fprintf(f,"%d ",num[i].key);
	}
	fclose(f);
}
void quickSort(int left,int right){

	int pivot,i,j;
	numNode temp;
	count++;
	printnum();
	if(left<right){
		i=left;j=right+1;
		pivot=num[left].key;
		do{
			do i++;while(num[i].key<pivot);
			do j--;while(num[j].key>pivot);
			if(i<j) SWAP(num[i],num[j],temp);
		}while(i<j);
		SWAP(num[left],num[j],temp);
		quickSort(left,j-1);
		quickSort(j+1,right);
	}
}