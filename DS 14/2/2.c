#define MAX_STACK_SIZE 60
#define MAX_QUEUE_SIZE 60
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s) p=malloc(s)
//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
typedef enum{lparen,rparen,and,or,not,divide,mod,eos,operand}precedence;

typedef struct node *treePointer;
typedef struct node {	
	char data; // 문자출력을 위해 char 형으로 지정
	treePointer leftChild, rightChild;
}tNode;
treePointer root;

treePointer stack[MAX_STACK_SIZE];
int top = -1;

char input[80];

treePointer createBinTree(void);
precedence getToken(char *symbol,int *n);
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

void main (void){

	root=createBinTree();

	printf("inorder traversal\t: ");
	inorder(root);
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

void push(treePointer item){

	stack[++top]=item;
}

treePointer pop(){

	return stack[top--];
}
treePointer createBinTree(void){

	FILE *f=fopen("input.txt","r");
	precedence token;
	char symbol;
	treePointer op1,op2;
	int n=0;
	treePointer temp;
	
	fscanf(f,"%s",input);

	printf("input string<postfix>\t: %s\n",input);
	printf("creating its binary tree\n");
	top=-1;
	token=getToken(&symbol,&n);
	while(token!=eos){
		MALLOC(temp,sizeof(tNode));
		if(token==operand){
			temp->data=symbol;
			temp->leftChild=NULL;
			temp->rightChild=NULL;
			push(temp);
		}
		else if(token==not){
			op1=pop();
			temp->data=symbol;
			temp->rightChild=op1;
			temp->leftChild=NULL;
			push(temp);
		}
		else{
			op2=pop();
			temp->data=symbol;
			temp->rightChild=op2;
			op1=pop();
			temp->leftChild=op1;
			push(temp);
		}
		token=getToken(&symbol,&n);
	}
	return pop();

}

precedence getToken(char *symbol,int *n){
	
	*symbol=input[(*n)++];
	
	switch(*symbol){
	case '(' : return lparen;
	case ')' : return rparen;
	case '&' : return and;
	case '|' : return or;
	case '/' : return divide;
	case '~' : return not;
	case '%' : return mod;
	case '\0' : return eos;
	default : return operand;
	}
}