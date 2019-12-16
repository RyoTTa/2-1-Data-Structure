#include <stdio.h>
#include <stdlib.h>
//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
#define MAX_SIZE 100
#define INF_NUM 10000

// min - winner tree 
int nums[ MAX_SIZE+1 ] = { 0 };		// keys to sort
int winTree[ 2*MAX_SIZE ] = { NULL };		// winner tree
int sorted[ MAX_SIZE+1 ] = { 0 };		// sorted result
int initWinner(int cur, int k);
void adjustWinner(int k);
void inorder(int k);
void make();

int count=0;
int kcount=1;

int main (void){

	int i;

	make();
	printf("\n\ninitialization of min-winner tree\n\n");
	initWinner(1, count);
	printf("inorder traversal for min-winner tree\n\n");
	inorder(1,count);
	printf("\n");
	printf("\nsorting with min-winner tree...\n\n");
	for(i=0;i<count;i++){
		adjustWinner(count);
	}
	printf("sorting result\n");
	for(i=1;i<kcount;i++){
		printf("%3d",sorted[i]); 
	}
	printf("\n");
	return 0;
}

void make(){

	int seed,i,j=1;

	printf("<<<<<<<<<<<<<<<sorting with winner three >>>>>>>>>>>>>>>\n\n");
	printf("the number of key<8,16, or 32 as a power of 23 > >> ");
	scanf("%d",&count);
	printf("random numbers to use as key values <1~100>\nseed >> ");
	scanf("%d",&seed);
	srand(seed);
	
	for(i=1;i<count+1;i++){
		nums[i]=rand()%100+1;
	}
	for(i=count;i<count*2;i++){
		winTree[i]=j++;
	}
	for(i=1;i<count+1;i++){
		printf("%3d",nums[i]);
	}
}
int initWinner(int cur, int k){

	if(cur<k){
		initWinner(cur*2,k);
		initWinner(cur*2+1,k);
		winTree[cur]= (nums[winTree[cur*2]]<nums[winTree[cur*2+1]])?winTree[cur*2]:winTree[cur*2+1];
	}
	
	return *winTree;
}
void inorder(int root, int k){

	if(root<k*2){
		inorder(root*2,k);
		printf("%3d",nums[winTree[root]]);
		inorder(root*2+1,k);
	}
}
void adjustWinner(int k){

	int min=0,minindex=0,i=0;

	min=nums[1];
	for(i=1;i<k+1;i++){
		if(min>=nums[i]){
			min=nums[i];
			minindex=i;
		}
	}
	sorted[kcount]=min;
	nums[minindex]=200;
	initWinner(1, k);
	kcount++;
}