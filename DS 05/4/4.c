#include<stdio.h>
#include<stdlib.h>
#define MAX_COL 10
#define MAX_ROW 10

//2015114398 �̿�ȣ
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�

typedef struct{
	int col;
	int row;
	int value;
}term;

	term ac[9];
	term bc[9];

void fastTranspose1(term *a, term *b)
{
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a->col, numTerms = a->value;
	b->row = numCols; b->col = a->row;
	b->value = numTerms;
	if( numTerms>0)
	{
		for(i = 0; i< numCols; i++)
			rowTerms[i] = 0;
		for(i=1; i<=numTerms; i++)
			rowTerms[(a+i)->col]++;
		startingPos[0] = 1;
		for(i=1; i<numCols; i++)
			startingPos[i] = startingPos[i-1] + rowTerms[i-1];
		for(i=1; i<numTerms; i++)
		{
			j = startingPos[(a+i)->col]++;
			(b+j)->row = (a+i)->col; (b+j)->col = (a+i)->row;
			(b+j)->value = (a+i)->value;
		}
	}
}

void fastTranspose2(term *a, term *b)
{
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = (*a).col, numTerms = (*a).value;
	(*b).row = numCols; (*b).col = (*a).row;
	(*b).value = numTerms;
	if( numTerms>0)
	{
		for(i = 0; i< numCols; i++)
			rowTerms[i] = 0;
		for(i=1; i<=numTerms; i++)
			rowTerms[(*(a+i)).col]++;
		startingPos[0] = 1;
		for(i=1; i<numCols; i++)
			startingPos[i] = startingPos[i-1] + rowTerms[i-1];
		for(i=1; i<numTerms; i++)
		{
			j = startingPos[(*(a+i)).col]++;
			(*(b+j)).row = (*(a+i)).col; (*(b+j)).col =(*(a+i)).row;
			(*(b+j)).value = (*(a+i)).value;
		}
	}
}

void printTerm(char name,term a[],int num)
{
	int i,j;
	int **arry;

	arry=(int**)malloc(sizeof(int*)*a[0].row);

	for(i=0;i<a[0].row;i++)
	{
		arry[i]=(int*)malloc(sizeof(int)*a[0].col);
	}

	for(i=0;i<a[0].row;i++)
	{
		for(j=0;j<a[0].col;j++)
		{
			arry[i][j]=0;
		}
	}

	for(i=1;i<=num;i++)
	{
		if(a[i].value!=0)
		{
			arry[a[i].row][a[i].col]=a[i].value;
		}
	}

	printf("%c\n",name);

	for(i=0;i<a[0].row;i++)
	{
		for(j=0;j<a[0].col;j++)
		{
			printf("%4d",arry[i][j]);
		}
		printf("\n");
	}

}

int main (void){

	FILE *frd;
	FILE *fwr;

	int i=0;
	

	frd=fopen("a.txt","r");
	fwr=fopen("b.txt","w");

	for(i=0; i<9; i++)
	{
		fscanf(frd,"%d\t%d\t%d",&ac[i].row,&ac[i].col,&ac[i].value);
	}
	//fastTranspose1(ac,bc);
	fastTranspose2(ac,bc);
	for(i=0; i<9; i++)
	{
		fprintf(fwr,"%d\t%d\t%d\n",bc[i].row,bc[i].col,bc[i].value);
	}
	
	printTerm('A',ac,i);
	printTerm('B',bc,i);

}

