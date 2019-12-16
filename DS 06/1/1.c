#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//2015114398
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 50

typedef struct{
	int id;
	char name[MAX_NAME_SIZE];
}element;

element stack[MAX_STACK_SIZE];

void stackFull();
void push(element item);
element pop();

int top = -1;

void push(element item){

	if (top>=MAX_STACK_SIZE-1){
		stackFull();
	}
	stack[++top]=item;
}

element stackEmpty(){

	element err;
	printf("stack is empty,cannot delete element\n");
	err.id=-1;
	return err;
}

element pop(){

	if(top == -1){
		return stackEmpty();
	}
	return stack[top--];
}

void stackFull(){

	int i=0;
	element Full;

	fprintf(stderr,"Stack is full. cannot add element\ncurrent stack element : \n");
	
	for(i=MAX_STACK_SIZE-1;i>=0;i--){
		Full=pop();
		printf("%d %s\n",Full.id,Full.name);
	}
	exit(EXIT_FAILURE);
}

int main (void){

	char command[20];
	element item;

	printf("<< stack operation where MAX_STACK_SIZE is %d\n",MAX_STACK_SIZE);
	printf("push 1 Jung\npop\n\n******************************************************\n");

	while(1){
		scanf("%s",command);

		if(strcmp(command,"push")==0){
			scanf("%d %s",&item.id,item.name);
			push(item);
			fflush(stdin);
		}
		else if(strcmp(command,"pop")==0){
			if(pop().id == -1){
				exit(EXIT_FAILURE);
			}
		}
		else{
			printf("wrong command! try again!\n");
		}
	}
	return 0;
}