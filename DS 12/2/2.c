#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s) p=malloc(s)
#define MAX_QUEUE_SIZE 100

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node *treePointer;
typedef struct node {	
	char data;
	treePointer leftChild, rightChild;
}tNode;
treePointer root=NULL;
treePointer queue[MAX_QUEUE_SIZE];
int front=-1,rear=-1;

void inorder(treePointer);
void preorder(treePointer);
void postorder(treePointer);

void createCompBinTree(FILE *);
void insert( treePointer *); 
void addq(treePointer );
treePointer deleteq();
void queueFull();
treePointer deleteEmpty();
treePointer getFront();

int main (void){

	FILE *f=fopen("input.txt","r");
	createCompBinTree(f);

	printf("creating a complete binary tree\n\n");
	printf("inorder traversal\t: ");
	inorder(root);
	printf("\n");
	printf("preorder traversal\t: ");
	preorder(root);
	printf("\n");
	printf("postorder traversal\t: ");
	postorder(root);
	printf("\n");
}

void inorder(treePointer ptr){

	if(ptr){
		inorder(ptr->leftChild);
		printf("%c",ptr->data);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr){

	if(ptr){
		printf("%c",ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
void postorder(treePointer ptr){

	if(ptr){
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c",ptr->data);
	}
}
void addq(treePointer input){

	if(rear==MAX_QUEUE_SIZE){
		queueFull();
	}
	queue[++rear]=input;
}
treePointer deleteq(){

	if(front==rear){
		return deleteEmpty();
	}
	return queue[++front];
}

void createCompBinTree(FILE *f){

	treePointer temp;

	MALLOC(temp,sizeof(*temp));
	fscanf(f,"%c",&temp->data);
	while(!feof(f)){
		temp->leftChild=NULL;
		temp->rightChild=NULL;
		insert(&temp);
		MALLOC(temp,sizeof(*temp));
		fscanf(f,"%c",&temp->data);
	}
}
void queueFull(){

	printf("queue is Full\n");
}
treePointer deleteEmpty(){

	printf("ERROR\n");
	exit(0);
}
treePointer getFront(){
	
	int frontt=front;
	frontt++;
	return queue[frontt];
}
void insert( treePointer *temp){


	while(1){
		if(root==NULL){
			root=*temp;
			break;
		}
		else{
			if(getFront()->leftChild==NULL){
				getFront()->leftChild=*temp;
				break;
			}
			else if(getFront()->rightChild==NULL){
				getFront()->rightChild=*temp;
				break;
			}
			if(getFront()->leftChild!=NULL&&getFront()->rightChild!=NULL){
				deleteq();
			}
		}
	}
	addq(*temp);

}