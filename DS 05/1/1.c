#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) ((x) <(y)) ? -1: ((x) ==(y))? 0: 1)
#define MAX_TERMS 100

//2015114398 �̿�ȣ
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�

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
	 printf("<<D(x) = A(x) + B(x) >\n\n");
	 printf("Input the number of items of A(x) : ");
	 scanf("%d",&A);
	 printf("Input the number of items of B(x) : ");
	 scanf("%d",&B);
	 printf("Input in descending order \n");
	 for(i=0; i<A; i++)
	 {
		 printf("the %dth coefficient and exponent of A(x),(ex) 10 3 : ",i+1);
		 scanf("%f %d",&terms[i].coef,&terms[i].expon);
	 }
	 printf("\n");
	 for(i=A; i<A+B; i++)
	 {
		 printf("the %dth coefficient and exponent of B(x),(ex) 10 3 : ",i-A+1);
		 scanf("%f %d",&terms[i].coef,&terms[i].expon);
	 }
	 printf("A(x) = ");
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