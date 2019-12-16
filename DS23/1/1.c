#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HT 11
#define BUCKET_SIZE 11
#define STRING_MAX 10
#define MALLOC(p,s)\
	if(!((p) = malloc(s))){\
	fprintf(stderr, "insufficient Memory");\
	exit(EXIT_FAILURE);\
	}
typedef struct{
	char item[STRING_MAX];
	int key;
}element;

typedef struct node *nodePointer; 
typedef struct node{
	element data;
	nodePointer link;
}node;

nodePointer ht[BUCKET_SIZE]={NULL,};

unsigned int stringToInt(char *key);
void makeHash();
int h(int k);
void insert(nodePointer k);
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

	while(*key){
		number+=*key++;
	}
	return number;
}
void makeHash(){

	nodePointer temp;
	FILE *f=fopen("input.txt","r");

	printf(" input strings : ");
	while(!feof(f)){
		temp=(nodePointer)malloc(sizeof(*temp));
		fscanf(f,"%s",temp->data.item);
		temp->data.key=stringToInt(temp->data.item);
		temp->link=NULL;
		insert(temp);
		printf("%s ",temp->data.item);
	}
	printf("\n\n");
	fclose(f);
}
int h(int k){

	return k%MAX_HT;
}
void insert(nodePointer k){

	int homeBucket;
	nodePointer current,temp,temp2;

	homeBucket=h(k->data.key);

	if(ht[homeBucket]==NULL){
		ht[homeBucket]=k;
	}
	else{
		for(temp=ht[homeBucket];temp!=NULL;temp=temp->link){
			if(temp->data.key==k->data.key){
				printf("중복된 key가 존재 합니다.\n");
				exit(1);
			}
			temp2=temp;
		}
		temp2->link=k;
	}
}
void printHT(){

	int i=0;
	nodePointer temp;
	printf("      %7s%7s\n","item","key");
	for(i=0;i<MAX_HT;i++){
		printf("ht[%2d] : ",i);
		if(ht[i]!=NULL){
			for(temp=ht[i];temp!=NULL;temp=temp->link){
				printf("<%s %d>   ",temp->data.item,temp->data.key);
			}
			printf("\n");
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
	int homeBucket;
	nodePointer current;


	printf("input ^Z to quit\n");
	printf("string to search >> ");

	while(EOF != scanf("%s",searItem))
	{
		searKey=stringToInt(searItem);
		homeBucket=h(searKey);

		if(ht[homeBucket]!=NULL){
			for(current=ht[homeBucket];current;current=current->link){
				if(current->data.key==searKey) break;
				count++;
			}
			if(current!=NULL){
				printf("item : %s, key : %d, the number of comparions : %d\n",current->data.item,current->data.key,count);
			}
			else{
				printf("it dosen't exist!\n");
			}
		}
		else{
			printf("it dosen't exist!\n");
		}
		printf("input ^Z to quit\n");
		printf("\nstring to search >> ");
	}
}