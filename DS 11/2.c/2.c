#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
#define MALLOC(p,s)\
	if(!((p) = malloc(s))){\
	fprintf(stderr, "insufficient Memory");\
	exit(EXIT_FAILURE);\
	}

//학번 이름
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node *nodePointer;
typedef struct node{
	int data;
	nodePointer llink;
	nodePointer rlink;
}node;
nodePointer header=NULL;

void dinsert(nodePointer node,nodePointer newnode,int);
nodePointer getNode();
void ddelete(nodePointer node,nodePointer deleted);
void forprintPointer(nodePointer *);
void backprintPointer(nodePointer *);
void pung(nodePointer *head);
void freee(nodePointer *head);

void main(void){

	nodePointer temp;
	int input=0;
	FILE *f=fopen("input.txt","r");

	while(!feof(f)){
		fscanf(f,"%d",&input);
		temp=getNode();
		temp->data=input;
		dinsert(header->llink,temp,input);
	}
	printf("After creating a doubly linked circular list with a head node : \n");
	forprintPointer(&header);
	backprintPointer(&header);
	pung(&header);
	printf("After deleting numbers less than and equal to 50 : \n");
	forprintPointer(&header);
	printf("\n");
	backprintPointer(&header);
	printf("\n");
	freee(&header);
	printf("After deleting all nodes except for the header node : \n");
	forprintPointer(&header);
	backprintPointer(&header);

}
void dinsert(nodePointer node,nodePointer newnode,int input){

	newnode->llink=node;
	newnode->rlink=node->rlink;
	node->rlink->llink=newnode;
	node->rlink=newnode;
}
nodePointer getNode(){

	nodePointer temp;
	nodePointer temp2;

	MALLOC(temp,sizeof(*temp));
	MALLOC(temp2,sizeof(*temp2));

	if(header==NULL){
		header=temp;
		header->llink=header;
		header->rlink=header;
		return temp2;
	}
	else{
		return temp2;
		free(temp);
	}
}
void ddelete(nodePointer node,nodePointer deleted){

	if(node==deleted){
		printf("Deletion of header node not permitted.\n");
	}
	else{
		deleted->llink->rlink=deleted->rlink;
		deleted->rlink->llink=deleted->llink;
		free(deleted);
	}
}
void forprintPointer(nodePointer *head){

	nodePointer temp=*head;
	nodePointer temp2=(*head)->rlink;
	int i=1;

	printf("forward\n");
	if(*head!=NULL){
		for(;temp2!=temp;temp2=temp2->rlink){
			printf("% d",temp2->data);
			if(i%10==0){
				printf("\n");
			}
			i++;
		}
	}
	printf("\n");
}

void backprintPointer(nodePointer *head){

	nodePointer temp=*head;
	nodePointer temp2=(*head)->llink;
	int i=1;

	printf("backward\n");
	if(*head!=NULL){
		for(;temp2!=temp;temp2=temp2->llink){
			printf(" %d",temp2->data);
			if(i%10==0){
				printf("\n");
			}
			i++;
		}
	}
	printf("\n");
}
void pung(nodePointer *head){

	nodePointer temp=header;
	nodePointer temp2=(*head)->rlink;

	while(1){
		if(temp2->data<=50){
			ddelete(*head,temp2);
			temp2=temp->rlink;
			temp=temp2->llink;
		}
		else{
			temp2=temp2->rlink;
			temp=temp2->llink;
		}
		if(temp2==header){
			break;
		}
	}
}
void freee(nodePointer *head){

	nodePointer temp=header;
	nodePointer temp2=(*head)->rlink;

	while(1){
		ddelete(*head,temp2);
		temp2=temp->rlink;
		temp=temp2->llink;

		if(temp2==header){
			break;
		}
	}
}