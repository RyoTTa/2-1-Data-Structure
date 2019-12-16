#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node{
	int key;
}element;

element extra[100]={0,};
int link[100]={0,};

int d,n,s=1,r=10;
int pass=0;
void radixMake(element a[]);
void printList(element a[],int check,int first,int front[],int rear[]);
int radixSort(element a[], int d, int r, int n);
void printQueues(int front[],int rear[]);
int digit(element a,int i, int r);

int main (void){

	element a[100];


	radixMake(a);
	radixSort(a,d,r,n);
	return 0;
}
void radixMake(element a[]){

	FILE *f=fopen("input.txt","r");
	int i=0;

	fscanf(f,"%d%d",&d,&n);

	for(i=1;i<=n;i++){
		fscanf(f,"%d",&a[i].key);
	}
}
int radixSort(element a[], int d,int r,int n){

	int i,bin,current,first,last;
	int j=0;
	int *front,*rear;

	front=(int*)malloc(sizeof(int)*r);
	rear=(int*)malloc(sizeof(int)*r);

	for(i=0;i<r;i++){
		front[i]=0;
		rear[i]=0;
	}

	first=1;
	for(i=1;i<n;i++)link[i]=i+1;
	link[n]=0;

	printList(a,0,first,front,rear);

	for(i=0;i<=d-1;i++){
		for(j=0;j<r;j++){
			front[j]=0;
			rear[j]=0;
		}
		for(bin=0;bin<r;bin++)front[bin]=0;
		for(current=first;current;current = link[current]){
			bin=digit(a[current],i,r);
			if(front[bin]==0)front[bin]=current;
			else link[rear[bin]]=current;
			rear[bin]=current;
		}
		for(bin=0;!front[bin];bin++);
		first=front[bin];last=rear[bin];

		for(bin++;bin<r;bin++){
			if(front[bin]){
				link[last]=front[bin]; last = rear[bin];
			}
		}
		link[last]=0;
		printList(a,1,first,front,rear);
	}
	return first;
}
int digit(element A, int i, int r){

   return (A.key % (int)(pow((double)r,(double)(i+1))) / (int)pow((double)r,(double)i)); 

}
void printList(element a[],int check,int first,int front[],int rear[]){

	int i=0;

	if(check==0){
		printf("************************ initial chain ************************\n");
	}
	else{
		printf("*************************** pass %d ***************************\n",pass);
	}

	printf("\t ");
	for(i=1;i<=n;i++){
		printf("[%2d] ",i);
	}
	printf("\n   link:");
	for(i=1;i<=n;i++){
		printf("%5d",link[i]);
	}
	printf("\n      a:");
	for(i=1;i<=n;i++){
		printf("%5d",a[i]);
	}
	printf("\n  first:%5d",first);
	printf("\n");
	printf("\n result:");
	for(i=1;i<=n;i++){
		printf("%5d",a[first]);
		first=link[first];
	}
	printf("\n\n");
	if(check==1){
		printQueues(front,rear);
	}
	pass++;
}
void printQueues(int front[],int rear[]){

	int i=0;

	printf("\t ");
	for(i=0;i<r;i++){
		printf("[%2d] ",i);
	}
	printf("\n   rear:");
	for(i=0;i<r;i++){
		printf("%5d",rear[i]);
	}
	printf("\n  front:");
	for(i=0;i<r;i++){
		printf("%5d",front[i]);
	}
	printf("\n\n");
}