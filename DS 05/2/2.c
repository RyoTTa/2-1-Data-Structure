#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) ((x) <(y)) ? -1: ((x) ==(y))? 0: 1)
#define MAX_TERMS 100

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다

void padd(int startA, int finishA, int startB, int finishB, int *startt, int *finishh);
void attach(float coefficient, int exponent);
void printpo(int start, int end);
typedef struct
{
	float coef;
	int expon;
}
term;
term terms[MAX_TERMS];
int avail = 0;
int main(void)
{
	int A, B;
	int i, startt = 0, finishh= MAX_TERMS;
	FILE *fp;
	fp=fopen("input.txt","r");

	printf("<<D(x) = A(x) + B(x) >\n");
	
	fscanf(fp,"%d",&A);
	fscanf(fp,"%d",&B);
	 for(i=0; i<A; i++)
	 {
		 fscanf(fp,"%f %d",&terms[i].coef,&terms[i].expon);
	 }
	 for(i=A; i<A+B; i++)
	 {
		 fscanf(fp,"%f %d",&terms[i].coef,&terms[i].expon);
	 }
	 printf("\nA(x) = ");
	 printpo(0,A);
	 printf("\nB(x) = ");
	 printpo(A,A+B);

	 avail = A+B;
	 startt = avail;

	 padd(0,A-1,A,A+B-1,&startt,&finishh);
	 printf("\nD(x) = ");
	 printpo(startt,finishh+1);
	 printf("\n");
	 return 0;
}
void padd(int startA, int finishA, int startB, int finishB, int *startt, int *finishh)
{
	float coefficient;
	*startt = avail;
	while(startA <= finishA && startB <= finishB)
		switch(COMPARE(terms[startA].expon, terms[startB].expon)
	{
		case -1 : attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0: coefficient = terms[startA].coef + terms[startB].coef;
			if(coefficient)
				attach(coefficient, terms[startA].expon);
			startA++;
			startB++;
			break;
		case 1: attach(terms[startA].coef, terms[startA].expon);
			startA++;
	}
	for(; startA<= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	for(;startB<= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);
	*finishh = avail-1;
}
void attach(float coefficient, int exponent)
{
	if(avail >= MAX_TERMS)
	{
		fprintf(stderr,"Too many terms in the polynominal\n");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}
void printpo(int start, int end)
{
	int i;
	 for(i = start ;i <end;i++)
	 {
		 if(terms[i].expon>0)
		 {
			 printf("%fx^%d + ",terms[i].coef,terms[i].expon);
		 }
		 else
		 {
			 printf("%f",terms[i].coef);
		 }
	 }
}