//2015114398 이용호

#include <stdio.h>
#include <stdlib.h>
#define	HEADER_EXPON	-1
#define	TRUE	1
#define	FALSE	0
#define	COMPARE(a, b) a > b ? 1 : (a == b ? 0 : -1)
#define MALLOC(p,s) (p=malloc(s))

typedef struct term* tTermPointer;

typedef struct term {
	float coef;
	int expon;
	tTermPointer next;
} tTerm;

int A=0,B=0;
tTermPointer avail = NULL;
tTermPointer statA=NULL,startB=NULL;

/* Program 4.12를 참조하여 avail로부터 활용가능한 노드를 반환하는 코드를 작성해야 합니다.*/
tTermPointer getNode()
{
	tTermPointer newNode;
	if(avail){
		newNode=avail;
		avail=avail->next;
	}
	else{
		MALLOC(newNode,sizeof(*newNode));
	}

	return newNode;
}

/* Program 4.14를 참조하여 다항식 a를 avail에 반환하는 코드를 작성해야 합니다.*/
void retPoly(tTermPointer* a)
{
	tTermPointer temp;
	
	///< 코드작성
}

/* Program 4.10을 참조하여 
   coef, expon으로 구성된 노드를 생성하여
   주어진 node 뒤에 삽입하는 코드를 작성합니다. */
void attach(tTermPointer *node, float coef, int expon)
{
	tTermPointer temp=getNode();

	temp->coef=coef;
	temp->expon=expon;
	(*node)->next=temp;
	(*node)=temp;
}

/* 파일이름으로부터 파일을 열고
   파일로부터 다항식을 생성하여 반환합니다. */
tTermPointer initPoly(char* fileName)
{
	float coef;
	int expon;
	tTermPointer header, last;
	FILE* fp = fopen(fileName, "r");
	header = getNode();
	header->next = header;
	header->expon = HEADER_EXPON;

	last = header;
	while (!feof(fp)) {
		fscanf(fp, "%f %d", &coef, &expon);
		attach(&last,coef,expon);
		last->next=header;
	}

	return header;
}

/* Program 4.9를 참조하여 addPoly 함수를 작성해야 합니다.*/
tTermPointer addPoly(tTermPointer a, tTermPointer b)
{
	int done = FALSE;
	float coefSum;
	tTermPointer header = getNode();
	tTermPointer last = header;
	tTermPointer startA = a;
	
	header->expon = HEADER_EXPON;
	header->next = header;
	a = a->next;
	b = b->next;
	while (!done) {
		switch (COMPARE(a->expon, b->expon)) {
		case 1:
			attach(&last,a->coef,a->expon);
			a=a->next;
			break;
		case 0:
			coefSum=a->coef+b->coef;
			if(coefSum){
				attach(&last,coefSum,a->expon);
			}
			a=a->next;b=b->next;
			break;
		case -1:
			attach(&last,b->coef,b->expon);
			b=b->next;
			break;
		}
	}
	last->next=header;
	for(;a;a=a->next)attach(&last,a->coef,a->expon);
	for(;b;b=b->next)attach(&last,b->coef,b->expon);

	return header;
}

/* 입력으로 주어진 다항식 poly에 입력으로 주어진 항 term을 곱하여 
   새로운 다항식을 반환하는 코드를 작성해야 합니다. */
tTermPointer singleMult(tTermPointer poly, tTermPointer term)
{
	tTermPointer startPoly = poly;
	tTermPointer header = getNode(), last;
	header->next = header;
	header->expon = HEADER_EXPON;

	last = header;

	///< 코드 작성

	return header;
}

/* 다항식 a를 다항식 b에 복사하는 코드를 작성합니다.*/
void copyPoly(tTermPointer a, tTermPointer b)
{
	tTermPointer startA = a;
	tTermPointer startB = b;
	tTermPointer prevB;

	prevB = b;
	a = a->next;
	b = b->next;
	while (1) {
		///< 코드 작성
	}

	if (b != startB) {
		prevB->next = startB;
		retPoly(&b);
	}
}

tTermPointer multPoly(tTermPointer a, tTermPointer b)
{
	tTermPointer startA = a;
	tTermPointer tmp = getNode();
	tTermPointer header = getNode();
	header->next = header;
	header->expon = HEADER_EXPON;
	tmp->next = tmp;
	tmp->expon = HEADER_EXPON;

	for (a = a->next; a != startA; a = a->next) {
		tTermPointer tmp1 = singleMult(b, a);

		if (header == header->next) {
			/* header == header->next 인 경우에는 결과 다항식이 없는 경우이므로
			   초기에는 tmp1을 header에 복사한 후 tmp1을 avail에 반환합니다. */
		}
		else {
			tTermPointer tmp2 = addPoly(tmp, tmp1);

			/* tmp2 = tmp + tmp1을 수행한 후 tmp를 header에 복사하고, tmp2는 avail에 반환합니다. */
		}

		///< header를 tmp에 복사합니다.
	}
	return header;
}

/* 다항식을 출력하는 함수를 작성해야 합니다.*/
void printPoly(tTermPointer a)
{
	for(;a;a=a->next){
		printf("%fx^%d+",a->coef,a->expon);
	}
}

/* x가 주어졌을 때, 다항식 a로부터 a(x)를 구하는 함수를 작성합니다. */
float evalPoly(tTermPointer a, float x)
{
	int i;
	tTermPointer startA = a;
	float tmp, result = 0;
	
	a = a->next;
	while (a != startA) {
		///< 코드 작성
	}
	return result;
}

/* 프로그램 종료 직전에 avail에 있는 모든 노드를 삭제하는 코드를 작성해야 합니다.*/
void releaseAvailTerms(void)
{
}

void main(void)
{
	float x;
	tTermPointer a = initPoly("polyA.txt");
	tTermPointer b = initPoly("polyB.txt");

	tTermPointer c = addPoly(a, b);
	//tTermPointer d = multPoly(a, b);
	printf("Polynomial A(x): \n");
	printPoly(a);
	printf("Polynomial B(x): \n");
	printPoly(b);
	printf("Polynomial C(x) = A(x) + B(x): \n");
	printPoly(c);
	//printf("Polynomial D(x) = A(x) x B(x): \n");
	//printPoly(d);

	printf("Enter the x value for evaluation: ");
	scanf("%f", &x);
	//printf("evaluation of polynomial A for the given %f: %f\n", x, evalPoly(a, x));
	//printf("evaluation of polynomial B for the given %f: %f\n", x, evalPoly(b, x));
	//printf("evaluation of polynomial C for the given %f: %f\n", x, evalPoly(c, x));
	//printf("evaluation of polynomial D for the given %f: %f\n", x, evalPoly(d, x));
	
	/* 프로그램 종료직전 모든 항을 avail에 반환 후 avail을 삭제하는 코드를 작성해야 합니다.*/
}