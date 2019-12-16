#include <stdio.h>
#include <stdlib.h>
//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
#define MAX_SIZE 100
#define INF_NUM 10000

// min - winner tree 
int nums[ MAX_SIZE+1 ][11] = { 0 };		// keys to sort
int winTree[ 2*MAX_SIZE ] = { NULL };		// winner tree
int sorted[ MAX_SIZE*10+1 ] = { 0 };	// sorted result
int sortedIdx[MAX_SIZE]={NULL};
int initWinner(int cur, int k);
void adjustWinner(int k);
void inorder(int k);
void make();

int count=0;
int kcount=1;

int main (void){

	int i;

	make();
	printf("\ninitialization of min-winner tree\n\n");
	initWinner(1, count);
	printf("inorder traversal for min-winner tree\n\n");
	printf("\nsorting with min-winner tree...\n\n");
	for(i=0;i<count*10;i++){
		adjustWinner(count);
	}
	printf("sorting result\n");
	for(i=1;i<count*10+1;i++){
		printf("%4d",sorted[i]);
		if(i%count==0){
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}

void make(){

	int seed,i,j=1,check=0;

	printf("<<<<<<<<<<<<<<<sorting with winner three >>>>>>>>>>>>>>>\n\n");
	printf("the number of key<8,16, or 32 as a power of 23 > >> ");
	scanf("%d",&count);
	printf("random numbers to use as key values <1~100>\nseed >> ");
	scanf("%d",&seed);
	srand(seed);

	for(j=1;j<count+1;j++){
		check=rand()%100+1;
		for(i=1;i<11;i++){
			nums[j][i]=check++;
		}
	}
	j=1;
	for(i=count;i<count*2;i++){
		winTree[i]=j++;
	}
	printf("initial records: \n");
	for(i=1;i<count+1;i++){
		printf("%d-th records:\n",i);
		for(j=1;j<11;j++){
			printf("%d ",nums[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<count+1;i++){
		sortedIdx[i]=1;
	}
}
int initWinner(int cur, int k){

	if(cur<k){
		initWinner(cur*2,k);
		initWinner(cur*2+1,k);
		winTree[cur]= (nums[winTree[cur*2]][sortedIdx[winTree[cur*2]]]<nums[winTree[cur*2+1]][sortedIdx[winTree[cur*2+1]]])?winTree[cur*2]:winTree[cur*2+1];
	}

	return *winTree;
}

void adjustWinner(int k){

	sorted[kcount]=nums[winTree[1]][sortedIdx[winTree[1]]];
	nums[winTree[1]][sortedIdx[winTree[1]]]=200;
	if(sortedIdx[winTree[1]]!=10){
		sortedIdx[winTree[1]]++;
	}
	initWinner(1, k);
	kcount++;
}