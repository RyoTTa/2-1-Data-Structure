#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) ((x)<(y))?-1:((x)==(y))?0:1)
#define MALLOC(p,s)\
	if(!((p) = malloc(s))){\
	fprintf(stderr, "insufficient Memory");\
	exit(EXIT_FAILURE);\
	}
#define FALSE 0
#define TRUE 1

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct polyNode *polyPointer;
typedef struct polyNode{
	int coef;
	int expon;
	polyPointer link;
}polyNode;
polyPointer a, b, c, alast, blast, avail = NULL;
FILE *f, *fl;

void insertFront2(polyPointer *last, polyPointer node){

	if (!(*last)){
		*last = node;
		node->link = node;
	}
	else{
		node->link = (*last)->link;
		(*last)->link = node;
	}
}

void insertLast(polyPointer *last, polyPointer node){
	if (!(*last)){
		*last = node;
		node->link = node;
	}
	else{
		node->link = (*last)->link;
		(*last)->link = node;
		*last = node;
	}
}

void erase(polyPointer *ptr){

	polyPointer temp;
	while (*ptr){
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}

polyPointer getNode(void){
	
	polyPointer node;
	if (avail){
		node = avail;
		avail = avail->link;
	}
	else{
		node = (polyPointer)malloc(sizeof(polyNode));
	}
	return node;
}

void retNode(polyPointer node){
	
	node->link = avail;
	avail = node;

}

void cerase(polyPointer *ptr){
	
	polyPointer temp;
	if (*ptr){
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}
}

void attach(int coefficient, int exponent, polyPointer *ptr){
	
	polyPointer temp;
	temp = getNode();
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}

polyPointer cpadd(polyPointer a, polyPointer b){
	
	polyPointer startA, c, lastC;
	int sum, done = FALSE;
	startA = a;
	a = a->link; 
	b = b->link;
	c = getNode();
	c->expon = -1; lastC = c;
	do{
		switch (COMPARE(a->expon, b->expon){
		case -1:
			attach(b->coef, b->expon, &lastC);
			b = b->link;
			break;
		case 0:
			if (startA == a) done = TRUE;
			else{
				sum = a->coef + b->coef;
				if (sum) attach(sum, a->expon, &lastC);
				a = a->link; b = b->link;
			}
			break;
		case 1:
			attach(a->coef, a->expon, &lastC);
			a = a->link;
		}
	} while (!done);
	lastC->link = c;
	return c;
}


polyPointer inputPolyCL(char ad, FILE *f2, polyPointer *a, polyPointer *alast){

	polyPointer n;
	(*a) = getNode();
	(*a)->expon = -1;
	(*a)->link = (*a);
	alast = a;

	if (ad == 'd'){
		while (!feof(f2)){
			n = getNode();
			fscanf(f2, "%d %d", &n->coef, &n->expon);
			insertLast(alast, n);
		}
		return (*alast)->link;
	}
	else{
		while (!feof(f2)){
			n = getNode();
			fscanf(f2, "%d %d", &n->coef, &n->expon);
			insertFront2(alast, n);
		}
		return (*alast);
	}
}

void printCList(polyPointer last){
	polyPointer temp;
	if (last){
		temp = last;
		temp = temp->link;
		do{
			printf("\t%+dx^%d", temp->coef, temp->expon);
			temp = temp->link;
		} while (temp != last);
	}
}

int main(void){

	polyPointer c;
	char ad1, ad2;
	f = fopen("a.txt", "r");
	fl = fopen("b.txt", "r");
	fscanf(f, "%c", &ad1);
	fscanf(fl, "%c", &ad2);

	a = inputPolyCL(ad1, f, &a, &alast);
	b = inputPolyCL(ad2, fl, &b, &blast);

	c = cpadd(a, b);

	printf("    a :");
	printCList(a);
	printf("\n    b :");
	printCList(b);

	printf("\na+b=c :");
	printCList(c);
	printf("\n");

	cerase(&a);
	cerase(&b);
	cerase(&c);

	erase(&avail);

	fclose(f);
	fclose(fl);
}
