#define MAX_STACK_SIZE 60
#define MAX_QUEUE_SIZE 60
#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s) p=malloc(s)
//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;

typedef struct node *treePointer;
typedef struct node {	
	char data; // 문자출력을 위해 char 형으로 지정
	treePointer leftChild, rightChild;
}tNode;
treePointer root;

treePointer stack[MAX_STACK_SIZE];
int top = -1;
int capacity=MAX_QUEUE_SIZE;
treePointer queue[MAX_QUEUE_SIZE];
int front=0, rear=0;
char input[80];

treePointer createBinTree(void);
precedence getToken(char *symbol,int *n);
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);
void interInorder(treePointer node);
void levelOrder(treePointer ptr);
void addq(treePointer item);
treePointer deleteq();

void main (void){

	root=createBinTree();

	printf("inorder traversal\t:");
	interInorder(root);
	printf("\n");
	printf("level order traversal\t:");
	levelOrder(root);
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
void addq(treePointer item)
{
	rear = (rear +1) % capacity;
	queue[rear] = item;
}

treePointer deleteq()
{
	front = (front + 1) % capacity;
	return queue[front];
}

void push(treePointer item){

	stack[++top]=item;
}
treePointer pop(){

	return stack[top--];
}
void interInorder(treePointer node){

	for(;;){
		for(;node;node=node->leftChild){
			push(node);
		}
		node=pop();
		if(!node)break;
		printf("%c",node->data);
		node=node->rightChild;
	}
}
void levelOrder(treePointer ptr){

	if(!ptr)return;
	addq(ptr);
	for(;;){
		ptr=deleteq();
		if(ptr){
			printf("%c",ptr->data);
			if(ptr->leftChild){
				addq(ptr->leftChild);
			}
			if(ptr->rightChild){
				addq(ptr->rightChild);
			}
		}
		else break;
	}
}
treePointer createBinTree(void){

	FILE *f=fopen("input.txt","r");
	precedence token;
	char symbol;
	treePointer op1,op2;
	int n=0;
	treePointer temp;
	
	fscanf(f,"%s",input);

	printf("The length of input string should be less than 80\ninput string <postfix expression> : %s\ncreating its binary tree\n\n",input);
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
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	case '%' : return mod;
	case '\0' : return eos;
	default : return operand;
	}
}