#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
	if(!((p) = (listNode*)malloc(s))){\
	fprintf(stderr, "insufficient Memory");\
	exit(EXIT_FAILURE);\
	}

//2015114398 이용호	
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct listNode {
	int data;
	struct listNode *link;
}listNode;

listNode *first = NULL;

listNode *find(int);
void insert(listNode *,int);
void deletee(listNode **, listNode *, listNode *);
void printList();

void main()
{
	FILE *f = fopen("input.txt","r");
	int num;
	listNode *newNode;

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
}

listNode *find(int num){

	listNode *search;

	search = (first);
	while(search)
	{
		if((first)->link == NULL){
			return first;
		}
		else if((first)->data >= num){
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

void insert(listNode *x, int num){
	listNode *temp;
	MALLOC(temp,sizeof(*temp));

	temp->data = num;
	if(x == NULL){
		temp->link = first;
		temp->data = num;
		first = temp;
	}
	else if(x->link == NULL){
		temp->link = NULL;
		temp->data = num;
		x->link = temp;
	}
	else{
		temp->link = x->link;
		temp->data = num;
		x->link = temp;
	}
}

void deletee(listNode **first, listNode *trail, listNode *x){

	if(trail){
		trail->link = x->link;
	}
	else{
		*first = (*first)->link;
	}
	free(x);
}

void printList(){

	int count = 1;
	listNode *printing;

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