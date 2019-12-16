#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
	if(!((p) = (stackPointer)malloc(s))){\
	fprintf(stderr, "insufficient Memory");\
	exit(EXIT_FAILURE);\
	}
#define MAX_STACKS 3 

//2015114398 이용호	
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct {
	int id;   	
	int grade;	
	} element;

typedef struct stack *stackPointer;
typedef struct stack {
	element data;
	stackPointer link;
	}Node;
stackPointer top[MAX_STACKS]=NULL;

void push(int,element);
element pop(int);
element stackEmpty();

void main()
{
	element item;
	int i;
	FILE *fin = fopen("input.txt","r");

	while(!feof(fin)){
		fscanf(fin,"%d %d %d",&i, &item.id, &item.grade);
		push(i,item);
	}

	i=0;
	printf("   과목번호,   학번,  성적\n");
	printf("******************************\n");
	while(i != MAX_STACKS){
		item = pop(i);
		if(item.id == -1){
			i++;
			item = pop(i);
			if(i == MAX_STACKS){
				break;
			}
			printf("******************************\n");
		}
		printf("%8d %8d %8d\n",i, item.id, item.grade);
	}
}

void push(int i, element item){

	stackPointer temp;

	MALLOC(temp, sizeof(*temp));

	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}

element pop(int i){

	stackPointer temp = top[i];

	element item;
	if(!temp){
		return stackEmpty();
	}
	item = temp->data;
	top[i] = temp->link;
	free(temp);
	return item;
}

element stackEmpty(){

	element error;

	error.id = -1;
	return error;
}