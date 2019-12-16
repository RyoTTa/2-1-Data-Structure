#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s) p=malloc(s);

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node *treePointer;
typedef struct node {	
	char data; // 문자출력을 위해 char 형으로 지정
	treePointer leftChild, rightChild;
}tNode;
treePointer root;
treePointer A,B,C,D,E;

void inorder(treePointer);
void preorder(treePointer);
void postorder(treePointer);
void createNode(treePointer *,char);
void createBinTree();

int main (void){

	createNode(&A,'A');createNode(&B,'B');createNode(&C,'C');createNode(&D,'D');createNode(&E,'E');
	createBinTree();
	root=A;
	printf("three binary tree traversals\n");
	printf("inorder traversal\t: ");
	inorder(root);
	printf("\n");
	printf("preorder traversal\t: ");
	preorder(root);
	printf("\n");
	printf("postorder traversal\t: ");
	postorder(root);
	printf("\n");
	return 0;
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
void createNode(treePointer *temp,char in){

	treePointer temp2;
	MALLOC(temp2,sizeof(*temp2));

	temp2->leftChild=NULL;
	temp2->rightChild=NULL;
	temp2->data=in;
	*temp=temp2;
}
void createBinTree(){

	printf("creating a binary tree\n\n");
	A->leftChild=B;
	B->leftChild=D;
	B->rightChild=E;
	A->rightChild=C;
}
