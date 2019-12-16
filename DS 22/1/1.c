#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HT 11

typedef struct{
	char item[10];
	int key;
}element;

element *ht[MAX_HT]={NULL,};

unsigned int stringToInt(char *key);
void makeHash();
int h(int k);
int insert(int k);
void printHT();
void search();

int main (void){

	makeHash();
	printHT();
	search();
	return 0;
}

unsigned int stringToInt(char *key){

	int number=0;
	char temp[10];

	strcpy(temp,key);

	while(*key){
		number+=*key++;
	}
	return number;
}

void makeHash(){

	element* temp;
	FILE *f=fopen("input.txt","r");

	printf(" input strings : ");
	while(!feof(f)){
		temp=(element*)malloc(sizeof(element));
		fscanf(f,"%s",temp->item);
		temp->key=stringToInt(temp->item);
		ht[insert(temp->key)]=temp;
		printf("%s ",temp->item);
	}
	printf("\n\n");
	fclose(f);
}
int h(int k){

	return k%MAX_HT;
}
int insert(int k){

	int i=0;
	int homeBucket,currentBucket;

	homeBucket=h(k);

	for(currentBucket=homeBucket;ht[currentBucket]&&ht[currentBucket]->key!=k;){
		currentBucket=(currentBucket+1)%MAX_HT;
		if(currentBucket==homeBucket){
			printf("해시테이블에 더이상 추가 할 수 없습니다\n");
			exit(1);
		}
	}
	for(i=0;i<MAX_HT;i++){
		if(ht[i]!=NULL){
			if(ht[i]->key==k){
				printf("중복된 key가 존재합니다.\n");
				exit(1);
			}
		}
	}
	return currentBucket;
}
void printHT(){

	int i=0;

	printf("         %7s%7s\n","item","key");
	for(i=0;i<MAX_HT;i++){
		printf("ht[%2d] : ",i);
		if(ht[i]!=NULL){
			printf("%7s%7d\n",ht[i]->item,ht[i]->key);
		}
		else{
			printf("\n");
		}
	}
}
void search(){

	int i=0,count=1;
	char searItem[10];
	int searKey=0;
	int homeBucket,currentBucket;

	printf("\nstring to search >> ");
	scanf("%s",searItem);
	searKey=stringToInt(searItem);
	homeBucket=h(searKey);

	for(currentBucket=homeBucket;ht[currentBucket]&&ht[currentBucket]->key!=searKey;){
		currentBucket=(currentBucket+1)%MAX_HT;
		if(currentBucket==homeBucket){
			printf("it dosen't exits!\n");
			exit(1);
		}
		count++;
	}
	if(ht[currentBucket]!=NULL&&ht[currentBucket]->key==searKey){
		printf("item:%s,key : %d, the number of comparisons : %d\n",searItem,searKey,count);
	}
	else{
		printf("it dosen't exits!\n");
		exit(1);
	}
}