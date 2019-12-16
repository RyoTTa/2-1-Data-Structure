#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)\
	if(!((p) = (queuePointer)malloc(s))){\
	fprintf(stderr, "insufficient Memory");\
	exit(EXIT_FAILURE);\
	}
#define MAX_QUEUES 3 

//2015114398 �̿�ȣ	
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

typedef struct {
	int id;   	
	int grade;	
	} element;

typedef struct queue *queuePointer;
typedef struct queue {
	element data;
	queuePointer link;
	}Node;
queuePointer front[MAX_QUEUES], rear[MAX_QUEUES];

void addq(int , element);
element deleteq(int);
element queueEmpty();

void main(){
	element newQueue;
	int i;
	FILE *fin = fopen("input.txt","r");

	while(!feof(fin)){
		fscanf(fin,"%d %d %d",&i, &newQueue.id, &newQueue.grade);
		addq(i,newQueue);
	}
	i=0;
	printf("   �����ȣ,   �й�,  ����\n");
	printf("******************************\n");
	while(i != MAX_QUEUES){
		newQueue = deleteq(i);
		if(newQueue.id == -1){
			i++;
			newQueue = deleteq(i);
			if(i == MAX_QUEUES){
				break;
			}
			printf("******************************\n");
		}
		printf("%8d %8d %8d\n",i, newQueue.id, newQueue.grade);
	}
}

void addq(int i, element newQueue){

	queuePointer temp;

	MALLOC(temp, sizeof(*temp));

	temp->data = newQueue;
	temp->link = NULL;
	if(front[i]){
		rear[i]->link = temp;
	}
	else{
		front[i] = temp;
	}
	rear[i] = temp;
}

element deleteq(int i){

	queuePointer temp = front[i];
	element newQueue;

	if(!temp){
		return queueEmpty();
	}
	newQueue = temp->data;
	front[i] = temp->link;
	free(temp);
	return newQueue;
}

element queueEmpty()
{
	element error;

	error.id = -1;
	return error;
}