#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HT 8

typedef struct{
	int key;
}element;

element *ht[MAX_HT]={NULL,};
int randomNum[MAX_HT]={0,};
void makeHash();
int h(int k);
int s(int seed);
int insert(int k);
void printHT();
void search();

int main (void){

	int seed;
	FILE *f=fopen("input.txt","r");

	printf("key seqquence from file : ");
	while(!feof(f)){
		fscanf(f,"%d",&seed);
		printf("%d ",seed);
	}
	printf("\n");
	fclose(f);
	printf("input seed >> ");
	scanf("%d",&seed);
	printf("\n");
	s(seed);
	makeHash();
	printHT();
	search();

	return 0;
}

void makeHash(){

	element* temp;
	FILE *f=fopen("input.txt","r");

	while(!feof(f)){
		temp=(element*)malloc(sizeof(element));
		fscanf(f,"%d",&temp->key);
		ht[insert(temp->key)]=temp;
	}
	printf("\n\n");
	fclose(f);
}
int h(int k){

	return k%MAX_HT;
}
int insert(int k){

	int i=0;

	if(ht[h(k)]==NULL){
		return h(k);
	}
	else{
		for(i=0;i<MAX_HT-1;i++){
			if(ht[(h(k)+randomNum[i])%MAX_HT]==NULL){
				return (h(k)+randomNum[i])%MAX_HT;
			}
		}
	}

}
void printHT(){

	int i=0;

	printf("      %7s\n","key");
	for(i=0;i<MAX_HT;i++){
		printf("ht[%2d] : ",i);
		if(ht[i]!=NULL){
			printf("%4d\n",ht[i]->key);
		}
		else{
			printf("\n");
		}
	}
}
void search(){

	int i=0,count=1;
	int searKey=0;
	int homeBucket,currentBucket;

	while(1){
		count=1;
		printf("\ninput 0 to quit\nkey to search >> ");
		scanf("%d",&searKey);
		if(searKey==0){
			exit(1);
		}
		homeBucket=h(searKey);
		for(currentBucket=homeBucket;ht[currentBucket]==NULL||ht[currentBucket]->key!=searKey;){
			currentBucket=(currentBucket+1)%MAX_HT;
			if(currentBucket==homeBucket){
				printf("it dosen't exits!\n");
				break;
			}
			count++;
		}
		if(ht[currentBucket]!=NULL&&ht[currentBucket]->key==searKey){
			printf("key:%d, the number of comparisons : %d\n",searKey,count);
		}
	}
}
int s(int seed){

	int count=1,check=0;
	int temp=0,i=0;


	srand(seed);
	while(count!=8){
		check=-1;
		temp=rand()%(MAX_HT-1)+1;
		for(i=1;i<MAX_HT;i++){
			if(randomNum[i]==temp){
				check++;
			}
		}
		if(check==-1){
			randomNum[count]=temp;
			printf("randNum[%d] : %d\n",count,randomNum[count]);
			count++;
		}
	}
}