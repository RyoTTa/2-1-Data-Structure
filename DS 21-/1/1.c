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

int rmergeSortRLV(element a[],int link[], int left, int right);
int rmergeSortLRV(element a[],int link[], int left, int right);

int listMergeRLV(element a[],int link[],int start1,int start2);
int listMergeLRV(element a[],int link[],int start1,int start2);

void mergeMake(element a[]);
void mergePrint(element a[],int start);
void mergePrint2(element a[],int left,int right);
void RLV();
void LRV();
int main (void){

	//RLV();
	LRV();
	return 0;
}
void RLV(){

	element a[100]={0,};
	int i=1,j=1;
	int start=0;

	mergeMake(a);
	printf("<<<<<<<<<< starting from initail %d chains, >>>>>>>>>>\n",n);
	printf("<<<<<<<<<<<<< each of which has one node >>>>>>>>>>>>>\n",n);
	mergePrint2(a,-1,-1);
	printf("");
	printf("<<<<<<<<<<<< excuting recursive merge sort >>>>>>>>>>>\n");
	start=rmergeSortRLV(a,link,1,n);
	printf("\n");
	printf("<<<<<<<<<< Sorted List >>>>>>>>>>\n");
	mergePrint(a,start);
	printf("\n\n");

}
void LRV(){

	element a[100]={0,};
	int i=1,j=1;
	int start=0;

	mergeMake(a);
	printf("<<<<<<<<<< starting from initail %d chains, >>>>>>>>>>\n",n);
	printf("<<<<<<<<<<<<< each of which has one node >>>>>>>>>>>>>\n",n);
	mergePrint2(a,-1,-1);
	printf("");
	printf("<<<<<<<<<<<< excuting recursive merge sort >>>>>>>>>>>\n");
	start=rmergeSortLRV(a,link,1,n);
	printf("\n");
	printf("<<<<<<<<<< Sorted List >>>>>>>>>>\n");
	mergePrint(a,start);
	printf("\n\n");
}
void mergePrint2(element a[],int left,int right){

	int i=0;

	if(left!=-1&&right!=-1){
			printf("\nlistMerged<a, link, %d, %d>\n",left,right);
	}
	printf("\t");
	for(i=0;i<=n;i++){
		printf("[%2d]",i);
	}
	printf("\n  link:");
	for(i=0;i<=n;i++){
		printf("%4d",link[i]);
	}
	printf("\n     a:");
	for(i=0;i<=n;i++){
		if(i==0)
			printf("%4c",'-');
		else
			printf("%4d",a[i]);
	}
	printf("\n\n");
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

int rmergeSortRLV(element a[],int link[], int left, int right){

	int mid;

	printf("rmergeSort<a, link, %d, %d>\n",left,right);
	if(left>=right)return left;
	mid=(left+right)/2;
	return listMergeRLV(a,link,rmergeSortRLV(a,link,left,mid),rmergeSortRLV(a,link,mid+1,right));
}
int rmergeSortLRV(element a[],int link[], int left, int right){

	int mid;

	printf("rmergeSort<a, link, %d, %d>\n",left,right);
	if(left>=right)return left;
	mid=(left+right)/2;
	return listMergeLRV(a,link,rmergeSortLRV(a,link,mid+1,right),rmergeSortLRV(a,link,left,mid));
}
int listMergeRLV(element a[],int link[],int start1,int start2){

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

	mergePrint2(a,start1,start2);
	return link[0];
}
int listMergeLRV(element a[],int link[],int start1,int start2){

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

	mergePrint2(a,start2,start1);
	return link[0];
}