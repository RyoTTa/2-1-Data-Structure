#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
	if(!((p) = (listPointer)malloc(s))){\
	fprintf(stderr, "insufficient Memory");\
	exit(EXIT_FAILURE);\
	}

//2015114398 이용호	
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct listNode *listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

listPointer first = NULL;

void insert(listPointer, int);
void deletee(listPointer *, listPointer, listPointer);
void printList();
listPointer find(int);

int main(void){

	FILE *f = fopen("input.txt","r");
	int num;
	listPointer newNode;

	fscanf(f,"%d",&num);
	insert(first, num);
	while(!feof(f)){
		fscanf(f,"%d",&num);
		newNode = find(num);
		insert(newNode, num);
	}
	
	printList();

	printf("Ater deleting nodes with data less than and equal to 50\n");
	while(first->data <= 50){
		deletee(&first,NULL,first);
	}
	printList();

	return 0;
}

listPointer find(int num){

	listPointer search;

	search = (first);
	while(search){
		if((first)->data >= num){
			return NULL;
		}
		else if(search -> link ==NULL){
			return search;
		}
		else if(search->data <= num && num <= search->link->data){
			return search;
		}
		search = search->link;
	}
}

void insert(listPointer x, int num){

	listPointer temp;
	MALLOC(temp,sizeof(*temp));

	temp->data = num;
	if(x == NULL){
		temp->link = first;
		first = temp;
	}
	else if(x->link == NULL){
		temp->link = NULL;
		x->link = temp;
	}
	else{
		temp->link = x->link;
		x->link = temp;
	}
}

void deletee(listPointer *first, listPointer trail, listPointer x){

	*first = (*first)->link;

	free(x);
}

void printList(){

	int count = 1;
	listPointer printing;

	printing = first;
	printf("The list contains :\n");
	for(;printing;printing = printing->link,count++){
		printf("%4d ",printing->data);
		if(count%10 == 0){
			printf("\n");
		}
	}
	printf("\n");
}