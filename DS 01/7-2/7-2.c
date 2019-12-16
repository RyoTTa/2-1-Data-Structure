#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define COMPARE(x,y) (((x)<(y))?-1:((x)==(y))?0:1)

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

void sort(int [],int);
void swap(int[],int,int);
int compare(int,int);
int binsearch(int [],int,int,int);

int main(void) 
{

	int numb=0,i;
	int arr[100]={0,};
	int searchnum=0,set=0;
	int left=0,right;

	printf("Enter the number of numbers to generate : ");
	scanf("%d",&numb);
	if(numb<1||numb>100){
		fprintf(stderr,"Improper value of n\n");
		exit(EXIT_FAILURE);
	}
	for(i=0;i<numb;i++){
		arr[i]=rand()%1000;
		printf("%d  ",arr[i]);
	}
	sort(arr,numb);
	printf("\n Sorted array:\n");
	for(i=0;i<numb;i++){
		printf("%d  ",arr[i]);
	}
	printf("\n");
	left=0;
	right=numb-1;
	printf("Enter the number to search : ");
	scanf("%d",&searchnum);
	set=binsearch(arr,searchnum,left,right);

	if(set==-1){
		printf("The search number is not present\n");
	}
	else{
		printf("The search number is present in list[%d]\n",set);
	}
	return 0;
}

void sort(int arr[],int numb){

	int i,j,min,temp;
	for(i=0;i<numb-1;i++){
		min=i;
		for(j=i+1;j<numb;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		SWAP(arr[i],arr[min],temp);
	}
}
int binsearch(int arr[],int searchnum,int left, int right){

	int middle;

		middle=(left+right)/2;
		switch(COMPARE(arr[middle],searchnum)){
		case -1: return
					 binsearch(arr,searchnum,middle+1,right);
		case 0 : return middle;
		case 1 : return 
					 binsearch(arr,searchnum,left,middle-1);
		}

	return -1;
}