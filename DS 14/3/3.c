#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)
//2015114398 �̿�ȣ
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.
typedef struct{
	int key;
}element;
element heap[MAX_ELEMENTS];
int n=0;

void push(element item,int *n);
element pop(int *n);
void print();

int main (void){
	
	FILE *f=fopen("input.txt","r");
	element temp;
	int i=0,num;
	printf("***** insertion into a max heap ****\n");
	while(!feof(f)){
		fscanf(f,"%d",&temp.key);
		push(temp,&n);
		print();
	}
	printf("***** deletion from a max heap ****\n");
	for(num=n,i=0;i<num;i++){
		pop(&n);
		print();
	}
	return 0;
}
void push(element item,int *n){
	
	int i;
	if(HEAP_FULL(*n)){
		fprintf(stderr,"The heap is full.\n");
		exit(EXIT_FAILURE);
	}
	i=++(*n);
	while((i!=1)&&(item.key>heap[i/2].key)){
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=item;
}
element pop(int *n){

	int parent,child;
	element item,temp;
	if(HEAP_EMPTY(*n)){
		fprintf(stderr,"The heap is empty\n");
		exit(EXIT_FAILURE);
	}
	item=heap[1];
	temp=heap[(*n)--];
	parent=1;
	child=2;
	while(child<=*n){
		if((child<*n)&&(heap[child].key<heap[child+1].key))
			child++;
		if(temp.key>=heap[child].key)break;
		heap[parent]=heap[child];
		parent = child;
		child*=2;
	}
	heap[parent]=temp;
	return item;
}
void print(){

	int i;

	for(i=1;i<=n;i++){
		printf("%3d",heap[i]);
	}
	printf("\n");
}