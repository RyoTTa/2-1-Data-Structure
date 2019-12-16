#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COMPARE(x,y) ((x) <(y)) ? -1: ((x) ==(y))? 0: 1
#define MALLOC(p,s)\
	if(!((p) = malloc(s))){\
	fprintf(stderr, "insufficient Memory");\
	exit(EXIT_FAILURE);\
	}

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct polyNode *polyPointer;
typedef struct polyNode{
	int coef;
	int expon;
	polyPointer link;
}polyNode;
polyPointer a=NULL,b=NULL,c=NULL;
polyPointer alast,blast;

polyPointer padd(polyPointer ,polyPointer);
void attach(float, int ,polyPointer *);
void insert(polyPointer *,int,int,char,polyPointer *);
void erase(polyPointer *);
void inputPoly();
void printList(polyPointer ,polyPointer,polyPointer,char);

int main (void){

	int coef=0,expon=0;
	char order;
	int i=0;

	FILE *aopen = fopen("a.txt","r");
	FILE *bopen = fopen("b.txt","r");

	fscanf(aopen,"%c",&order);
	while(!feof(aopen)){
		fscanf(aopen,"%d %d",&coef,&expon);
		insert(&a,coef,expon,order,&alast);
	}
	fscanf(bopen,"%c",&order);
	while(!feof(bopen)){
		fscanf(bopen,"%d %d",&coef,&expon);
		insert(&b,coef,expon,order,&blast);
	}
	printList(a,b,c,'a');
	printList(a,b,c,'b');
	c=padd(a,b);
	printList(a,b,c,'c');
	return 0;
}

void insert(polyPointer *input,int coef,int expon,char order,polyPointer *last){
	
	polyPointer temp;
	int i=0;

	MALLOC(temp,sizeof(*temp));

	if((*input)!=NULL){
		if(order=='a'){//첫노드로 삽입
			temp->coef=coef;
			temp->expon=expon;
			temp->link=(*input);
			(*input)=temp;
		}
		if(order=='d'){//후노드로 삽입
			(*last)->link=temp;
			temp->coef=coef;
			temp->expon=expon;
			temp->link=NULL;
			*last=temp;
		}
	}
	else{
		temp->coef=coef;
		temp->expon=expon;
		temp->link=NULL;
		*input=temp;
		*last=*input;
	}
}

void printList(polyPointer aa,polyPointer bb,polyPointer cc,char order){

	if(order=='a'){
		printf("     a:");
		for(;aa!=NULL;aa=aa->link){
			printf("%+5dx^%d",aa->coef,aa->expon);
		}
		printf("\n");
	}
	else if(order=='b'){
		printf("     b:");
		for(;bb!=NULL;bb=bb->link){
			printf("%+5dx^%d",bb->coef,bb->expon);
		}
		printf("\n");
	}
	else if(order=='c'){
		printf(" a+b=c:");
		for(;cc!=NULL;cc=cc->link){
			printf("%+5dx^%d",cc->coef,cc->expon);
		}
		printf("\n");
	}
	
}

polyPointer padd(polyPointer aa,polyPointer bb){

	polyPointer c,rear,temp;
	int sum,compare;
	
	MALLOC(rear,sizeof(*rear));
	c=rear;

	while(aa&&bb){
		switch(COMPARE(aa->expon,bb->expon)){
		case -1:
			attach(bb->coef,bb->expon,&rear);
			bb=bb->link;
			break;
		case 0:
			sum=aa->coef+bb->coef;
			if(sum)attach(sum,aa->expon,&rear);
			aa=aa->link;bb=bb->link;
			break;
		case 1 :
			attach(aa->coef,aa->expon,&rear);
			aa=aa->link;
		}
	}
	for(;aa;aa=aa->link)attach(aa->coef,aa->expon,&rear);
	for(;bb;bb=bb->link)attach(bb->coef,bb->expon,&rear);
	rear->link=NULL;
	temp=c;c=c->link;free(temp);
	return c;
}
void attach(float coef, int expon ,polyPointer *ptr){

	polyPointer temp;
	MALLOC(temp,sizeof(*temp));
	temp->coef=coef;
	temp->expon=expon;
	(*ptr)->link=temp;
	*ptr=temp;
}
void erase(polyPointer *ptr){

	polyPointer temp;
	while(*ptr){
		temp=*ptr;
		*ptr=(*ptr)->link;
		free(temp);
	}
}