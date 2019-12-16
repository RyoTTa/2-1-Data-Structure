#include<stdio.h>
#include<stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node{
	int key;
}element;

element extra[100]={0,};
int link[100]={0,};
int n,s=1;

int rmergeSort(element a[],int link[], int left, int right);
int listMerge(element a[],int link[],int start1,int start2);

void mergeMake(element a[]);
void mergePrint(element a[],int start);

int main (void){

	element a[100]={0,};
	int i=1,j=1;
	int start=0;

	mergeMake(a);
	printf("<<<<<<<<<< Input List >>>>>>>>>>\n");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
	printf("<<<< excuting recursive merge sort >>>>\n");
	start=rmergeSort(a,link,1,n);
	printf("\n");
	printf("<<<<<<<<<< Sorted List >>>>>>>>>>\n");
	mergePrint(a,start);
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

void mergePrint(element a[],int start){

	int i=0;

	for(i=1;i<=n;i++){
		printf("%d ",a[start]);
		start=link[start];
	}

}

int rmergeSort(element a[],int link[], int left, int right){

	int mid;

	if(left>=right)return left;
	mid=(left+right)/2;
	printf("left : %d, right : %d\n",left,right);
	return listMerge(a,link,rmergeSort(a,link,left,mid),rmergeSort(a,link,mid+1,right));
}

int listMerge(element a[],int link[],int start1,int start2){

	int last1,last2,lastResult=0;
	for(last1=start1,last2=start2;last1&&last2;){
		if(a[last1].key<=a[last2].key){
			link[lastResult]=last1;
			lastResult=last1;last1=link[last1];
		}
		else{
			link[lastResult]=last2;
			lastResult=last2;last2=link[last2];
		}
	}
	if(last1==0)link[lastResult]=last2;
	else link[lastResult]=last1;

	return link[0];
}