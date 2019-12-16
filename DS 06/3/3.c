#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//2015114398
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

#define MAX_QUEUE_SIZE 5
#define MAX_NAME_SIZE 50
#define MALLOC(p,s)\
	if(!((p)=malloc(s))){\
	fprintf(stderr,"Insufficient memory\n");\
	exit(EXIT_FAILURE);\
	}

typedef struct{
	int id;
	char name[MAX_NAME_SIZE];
}element;

void addq(element item);
element deleteq();
element queueEmpty();
void queueFull();
void copy(int start,int rear2, element *newQueue);

element *queue;
int capacity = 2;
int rear = 0;
int front = 0;


void addq(element item)
{
	rear = (rear +1) % capacity;
	if(front == rear){
		queueFull();
	}
	queue[rear] = item;
}

element deleteq()
{
	element item;
	if(front == rear){
		return queueEmpty();
	}
	front = (front + 1) % capacity;
	return queue[front];
}

element queueEmpty()
{
	element ERROR;
	printf("queue is empty, cannot delete element.\n");
	ERROR.id = -1;
	return ERROR;
}

void copy(int start,int rear2, element *newQueue){

	int cap=capacity,i;
	int j,k=0,qq=0;


	if(start==0){
		for(i=0;i<capacity;i++){
			newQueue[i]=queue[i];
		}
	}
	else if(start==1){
		for(i=0;i<capacity;i++){
			newQueue[i]=queue[i+1];
		}
	}
	else{
		for(j=start;j<capacity;j++){
			newQueue[k]=queue[j];
			k++;
			qq=k;

		}
		for(i=0;i<rear+1;i++){
			newQueue[k]=queue[i];
			k++;
		}
	}
}
void queueFull()
{
	int i = 0;
	int start;
	element * newQueue;
	MALLOC(newQueue, 2*capacity*sizeof(*queue));
	start = (front + 1) % capacity;
	rear--;

	copy(start, rear, newQueue);

	front = 2*capacity -1;
	rear = capacity -1;
	capacity *=2;
	free(queue);
	queue = newQueue;
	printf("queue capacity is doubled,\ncurrent queue capacity is %d\n",capacity);
}


int main (void){

	char command[20];
	element item;
	int i=0;

	printf("<< linear queue operation where MAX_QUEUE_SIZE is %d\n",MAX_QUEUE_SIZE);
	printf("add 1 Jung\ndelete\n\n******************************************************\n");
	MALLOC(queue,2*sizeof(*queue));

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
			printf("deleted item : %d %s\n",queue[front].id,queue[front].name);
		}
		else{
			printf("wrong command! try again!\n");
		}
	}
	return 0;
}