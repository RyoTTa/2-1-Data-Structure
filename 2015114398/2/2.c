//2015114398 �̿�ȣ

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

/* Program 4.12�� �����Ͽ� avail�κ��� Ȱ�밡���� ��带 ��ȯ�ϴ� �ڵ带 �ۼ��ؾ� �մϴ�.*/
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

/* Program 4.14�� �����Ͽ� ���׽� a�� avail�� ��ȯ�ϴ� �ڵ带 �ۼ��ؾ� �մϴ�.*/
void retPoly(tTermPointer* a)
{
	tTermPointer temp;
	
	///< �ڵ��ۼ�
}

/* Program 4.10�� �����Ͽ� 
   coef, expon���� ������ ��带 �����Ͽ�
   �־��� node �ڿ� �����ϴ� �ڵ带 �ۼ��մϴ�. */
void attach(tTermPointer *node, float coef, int expon)
{
	tTermPointer temp=getNode();

	temp->coef=coef;
	temp->expon=expon;
	(*node)->next=temp;
	(*node)=temp;
}

/* �����̸����κ��� ������ ����
   ���Ϸκ��� ���׽��� �����Ͽ� ��ȯ�մϴ�. */
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

/* Program 4.9�� �����Ͽ� addPoly �Լ��� �ۼ��ؾ� �մϴ�.*/
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

/* �Է����� �־��� ���׽� poly�� �Է����� �־��� �� term�� ���Ͽ� 
   ���ο� ���׽��� ��ȯ�ϴ� �ڵ带 �ۼ��ؾ� �մϴ�. */
tTermPointer singleMult(tTermPointer poly, tTermPointer term)
{
	tTermPointer startPoly = poly;
	tTermPointer header = getNode(), last;
	header->next = header;
	header->expon = HEADER_EXPON;

	last = header;

	///< �ڵ� �ۼ�

	return header;
}

/* ���׽� a�� ���׽� b�� �����ϴ� �ڵ带 �ۼ��մϴ�.*/
void copyPoly(tTermPointer a, tTermPointer b)
{
	tTermPointer startA = a;
	tTermPointer startB = b;
	tTermPointer prevB;

	prevB = b;
	a = a->next;
	b = b->next;
	while (1) {
		///< �ڵ� �ۼ�
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
			/* header == header->next �� ��쿡�� ��� ���׽��� ���� ����̹Ƿ�
			   �ʱ⿡�� tmp1�� header�� ������ �� tmp1�� avail�� ��ȯ�մϴ�. */
		}
		else {
			tTermPointer tmp2 = addPoly(tmp, tmp1);

			/* tmp2 = tmp + tmp1�� ������ �� tmp�� header�� �����ϰ�, tmp2�� avail�� ��ȯ�մϴ�. */
		}

		///< header�� tmp�� �����մϴ�.
	}
	return header;
}

/* ���׽��� ����ϴ� �Լ��� �ۼ��ؾ� �մϴ�.*/
void printPoly(tTermPointer a)
{
	for(;a;a=a->next){
		printf("%fx^%d+",a->coef,a->expon);
	}
}

/* x�� �־����� ��, ���׽� a�κ��� a(x)�� ���ϴ� �Լ��� �ۼ��մϴ�. */
float evalPoly(tTermPointer a, float x)
{
	int i;
	tTermPointer startA = a;
	float tmp, result = 0;
	
	a = a->next;
	while (a != startA) {
		///< �ڵ� �ۼ�
	}
	return result;
}

/* ���α׷� ���� ������ avail�� �ִ� ��� ��带 �����ϴ� �ڵ带 �ۼ��ؾ� �մϴ�.*/
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
	
	/* ���α׷� �������� ��� ���� avail�� ��ȯ �� avail�� �����ϴ� �ڵ带 �ۼ��ؾ� �մϴ�.*/
}