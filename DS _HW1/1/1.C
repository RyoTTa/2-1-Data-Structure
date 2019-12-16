#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_TERMS 100
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1 )

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다

typedef struct {
	float coef;
	int expon;
}term;

term terms[MAX_TERMS];

void readPoly(char In[]);
void addPoly(int startA, int finishA, int startB, int finishB, int *startD, int *finishD);
void attach(float coefficient, int exponent);
void mulPoly(int startA, int finishA, int startB, int finishB, int *startD, int *finishD, int A, int B);
void printPoly(int start, int finish);

int count=0;
int A,B;
int avail=0;

void main()
{
	int startA, finishA, startB, finishB, startD, finishD;
	char In[10];
	readPoly(In);

	startA = 0;
	finishA = A-1;
	startB = A;
	finishB = A+B-1;

	if(strcmp(In,"ADD") == 0)
	{
		addPoly(startA, finishA, startB, finishB, &startD, &finishD);
		printPoly(startA,finishA);
		printf(" +\n");
		printPoly(startB,finishB);
		printf(" =\n");
		printPoly(startD,finishD);
	}
	else if(strcmp(In,"MUL") == 0)
	{
		mulPoly(startA, finishA, startB, finishB, &startD, &finishD, A, B);
		printPoly(startA,finishA);
		printf(" *\n");
		printPoly(startB,finishB);
		printf(" =\n");
		printPoly(startD,finishD);
	}
}

void readPoly(char In[]){

	FILE *f=fopen("input.txt","r");
	int i=0;

	fscanf(f,"%d %d",&A,&B);

	for(i=0; i<A; i++){
		fscanf(f,"%f %d",&terms[i].coef,&terms[i].expon);
	}
	for(i=A; i<A+B; i++){
		fscanf(f,"%f %d",&terms[i].coef,&terms[i].expon);
	}
	fscanf(f,"%s",In);

	fclose(f);
}

void addPoly(int startA, int finishA, int startB, int finishB, int *startD, int *finishD){

	float coefficient;

	avail = finishB+1;
	*startD = avail;

	while(startA <= finishA && startB <= finishB)
		switch(COMPARE(terms[startA].expon, terms[startB].expon)){
		case -1:
			attach(terms[startB].coef,terms[startB].expon); 
			startB++; 
			break;
		case 0:
			coefficient = terms[startA].coef + terms[startB].coef;
			if(coefficient)
				attach(coefficient,terms[startA].expon);
			startA++;
			startB++;
			break;
		case 1:
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
	}
	for(; startA <= finishA; startA++){
		if(terms[startA].coef == 0)
			break;
		attach(terms[startA].coef,terms[startA].expon);
	}
	for(; startB <= finishB; startB++){
		if(terms[startB].coef == 0)
			break;
		attach(terms[startB].coef,terms[startB].expon);
	}
	*finishD = avail - 1;
}

void mulPoly(int startA, int finishA, int startB, int finishB, int *startD, int *finishD, int A, int B)
{
	int startT1, finishT1, startT2, finishT2,start1,finish1,start2,finish2,temp,i=0,j=0,k=0,menu=0;

	startT1 = finishB + 1;

	if(A>B) {
		menu=B;start1=startA;finish1=finishA;start2=startB;finish2=finishB;
	}
	else {
		menu=A;start1=startB;finish1=finishB;start2=startA;finish2=finishA;
	}
	finishT1 = startT1 + menu - 1;
	startT2 = finishT1 + 1;
	finishT2 = startT2 + menu - 1;
	for(i = start1; i<= finish1; i++){
		for(j = start2; j<= finish2; j++){
			terms[startT1].coef = terms[i].coef * terms[j].coef;
			terms[startT1++].expon = terms[i].expon + terms[j].expon;
		}
		startT1 = finishB + 1;
		addPoly(startT1, finishT1,startT2, finishT2, startD, finishD);
		if(i == finish1){
			break;
		}
		temp=startT2;
		for(k = *startD; k <= *finishD; k++){
			terms[temp++] = terms[k];
		}
		finishT2=temp-1;
	}
}
void attach(float coefficient, int exponent)
{
	if((avail) >= MAX_TERMS) {
		fprintf(stderr,"Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[(avail)].coef = coefficient;
	terms[(avail)++].expon = exponent;
}
void printPoly(int start, int finish)
{
	int i;

	for(i = start ;i <=finish;i++){
		if(abs(terms[i].coef)==1){
			if(terms[i].coef<0){
				if(terms[i].expon>0)
					printf("-x^%d + ",terms[i].expon);
				else
					printf("%f",terms[i].coef);
			}
			else{
				if(terms[i].expon>0)
					printf("x^%d + ",terms[i].expon);
				else
					printf("%f",terms[i].coef);
			}
		}
		else{
			if(terms[i].expon>0)
				printf("%fx^%d + ",terms[i].coef,terms[i].expon);
			else
				printf("%f",terms[i].coef);
		}
	}
	printf("\n");
}