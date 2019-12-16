#include<stdio.h>
#include<stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#define SWAP(p,n,s) s=p,p=n,n=s

typedef struct node{
	int key;
}element;

int n;

void mergeMake(element a[]);
void mergePrint(element a[]);

void heapSort(element a[],int n);
void adjust(element a[],int root,int n);

int main (void){

	element a[100]={0,};
	int i=1,j=1;

	mergeMake(a);
	printf("<<<<<<<<<< Input List >>>>>>>>>>\n");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
	printf("<<<<<<<<<< excuting heap sort >>>>>>>>>>\n");
	heapSort(a,n);
	printf("\n");
	printf("<<<<<<<<<< Sorted List >>>>>>>>>>\n");
	mergePrint(a);
	printf("\n\n");
	return 0;
}

void mergeMake(element a[]){

	FILE *f=fopen("input.txt","r");
	int i=0;

	fscanf(f,"%d",&n);

	for(i=1;i<=n;i++){
		fscanf(f,"%d",&a[i].key);
	}
}

void mergePrint(element a[]){

	int i=0;

	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}

}


void heapSort(element a[],int n){

	int i,j=1,k=0;
	element temp;

	for(i=n/2;i>0;i--){
		adjust(a,i,n);
	}
	printf("after initializationof max heap...\n");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
	for(i=n-1;i>0;i--){
		SWAP(a[1],a[i+1],temp);
		adjust(a,1,i);
		printf("step%5d : ",j++);
		for(k=1;k<=n;k++){
			printf("%d ",a[k]);
		}
		printf("\n");
	}
}
void adjust(element a[],int root,int n){

	int child,rootkey;
	element temp;
	temp =a[root];
	rootkey = a[root].key;
	child = 2*root;

	while(child<=n){
		if((child<n)&&(a[child].key<a[child+1].key))
			child++;
		if(rootkey>a[child].key)
			break;
		else{
			a[child/2]=a[child];
			child*=2;
		}
	}
	a[child/2]=temp;
}