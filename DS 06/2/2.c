#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//2015114398
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#define MAX_QUEUE_SIZE 5
#define MAX_NAME_SIZE 50


typedef struct{
	int id;
	char name[MAX_NAME_SIZE];
}element;

void addq(element item);
element deleteq();
element queueEmpty();
void queueFull();

element queue[MAX_QUEUE_SIZE];
int rear=-1;
int front=-1;

void addq(element item){
	if(rear==MAX_QUEUE_SIZE-1){
		queueFull();
	}
	queue[++rear]=item;
}

element deleteq(){
	if(front==rear){
		return queueEmpty();
	}
	return queue[++front];
}

element queueEmpty(){

	element err;
	printf("queue is empty,cannot delete element\n");
	err.id=-1;
	return err;
}

void queueFull(){

	int i=0,j;
	element Full;

	if(front==-1&&rear==MAX_QUEUE_SIZE-1){

		fprintf(stderr,"Queue is full. cannot add element\ncurrent stack element : \n");
		for(i=MAX_QUEUE_SIZE-1;i>=0;i--){
			Full=deleteq();
			printf("%d %s\n",Full.id,Full.name);
		}
		exit(EXIT_FAILURE);
	}
	else{
		j=front+1;
		for(i=0;i<rear-front;i++){
			queue[i]=queue[j];
			j++;
		}
		printf("array shifting...\n");
		rear=rear-(front+1);
		front=-1;
	}
}

int main (void){

	char command[20];
	element item;

	printf("<< linearqueue operation where MAX_QUEUE_SIZE is %d\n",MAX_QUEUE_SIZE);
	printf("add 1 Jung\ndelete\n\n******************************************************\n");

	while(1){
		scanf("%s",command);

		if(strcmp(command,"add")==0){
			scanf("%d %s",&item.id,item.name);
			addq(item);
			fflush(stdin);
		}
		else if(strcmp(command,"delete")==0){
			if(deleteq().id == -1){
				exit(EXIT_FAILURE);
			}
		}
		else{
			printf("wrong command! try again!\n");
		}
	}
	return 0;
}