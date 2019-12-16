#include<stdio.h>
#include<stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node{
	int key;
}element;

element extra[100]={0,};
int n,s=1;

void merge(element initList[], element mergedList[],int i, int m, int n);
void mergePass(element initList[],element mergedList[],int n, int s);
void mergeSort(element a[],int n);
void mergeMake(element a[]);
void mergePrint(element a[],element extra[],int s,int set);

int main (void){

	element a[100]={0,};
	int i=1;

	mergeMake(a);
	printf("<<<<<<<<<< Input List >>>>>>>>>>\n");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
	printf("<<<< excuting itterative merge sort >>>>\n");
	mergeSort(a,n);
	printf("<<<<<<<<<< Sorted List >>>>>>>>>>\n");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
	return 0;
}

void merge(element initList[], element mergedList[],int i, int m, int n){

	int j,k,t;
	j=m+1;
	k=i;

	while(i<=m && j<=n){
		if(initList[i].key<=initList[j].key){
			mergedList[k++]=initList[i++];
		}
		else{
			mergedList[k++]=initList[j++];
		}
	}
	if(i>m){
		for(t=j;t<=n;t++){
			mergedList[t]=initList[t];
		}
	}
	else{
		for(t=i;t<=m;t++){
			mergedList[k+t-i]=initList[t];
		}
	}
}
void mergePass(element initList[],element mergedList[],int n, int s){

	int i,j;
	for(i=1;i<=n-2*s+1;i+=2*s){
		merge(initList,mergedList,i,i+s-1,i+2*s-1);
	}
	if(i+s-1<n){
		merge(initList,mergedList,i,i+s-1,n);
	}
	else{
		for(j=i;j<=n;j++){
			mergedList[j]=initList[j];
		}
	}
}
void mergeSort(element a[],int n){

	while(s<n){
		mergePass(a,extra,n,s);
		mergePrint(a,extra,s,1);
		s*=2;
		mergePass(extra,a,n,s);
		mergePrint(extra,a,s,2);
		s*=2;
	}
}
void mergeMake(element a[]){

	FILE *f=fopen("input.txt","r");
	int i=0;

	fscanf(f,"%d",&n);

	for(i=1;i<=n;i++){
		fscanf(f,"%d",&a[i].key);
	}
}

void mergePrint(element a[],element extra[],int s,int set){

	int i=0;

	if(set==1){
		printf("segment size : %d\n",s);
		printf("           a : ");
		for(i=1;i<=n;i++){
			printf("%d ",a[i].key);
		}
		printf("\n");
		printf("       extra : ");
		for(i=1;i<=n;i++){
			printf("%d ",extra[i].key);
		}
		printf("\n\n");
	}
	else{
		printf("segment size : %d\n",s);
		printf("       extra : ");
		for(i=1;i<=n;i++){
			printf("%d ",a[i].key);
		}
		printf("\n");
		printf("           a : ");
		for(i=1;i<=n;i++){
			printf("%d ",extra[i].key);
		}
		printf("\n\n");
	}
}