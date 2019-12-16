//2015114398 이용호

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS	101
#define MAX_ROW	100
#define MAX_COL	100

typedef struct {
	int row;
	int col;

	int r;
	int i;	
} tTermComplex;

int compare(int a, int b);

int compareComplex(tTermComplex a, tTermComplex b){
	
	if ((compare(a.row,b.row)==-1)||(((compare(a.row,b.row)==0)&&(compare(a.col,b.col)==-1))));//a가 작을때
		return -1;
	if (a.row==b.row&&a.col==b.col)//같을떄
		return 0;
	return 1; //b가 작을때
}

int compare(int a, int b){

	if (a < b)
		return -1;
	if (a == b)
		return 0;
	return 1;
}

/* 두 희소행을 a, b로부터 d = a+b를 수행하는 코드를 작성해야 합니다.*/
void addSparseMat(tTermComplex a[], tTermComplex b[], tTermComplex d[]){

	int currenta, currentb, currentd;
	int i;

	if (a[0].col!=b[0].col&&a[0].row!=b[0].row) {
		fprintf(stderr, "Incompativel matrices\n");
		exit(EXIT_FAILURE);
	}

	d[0].row = a[0].row;
	d[0].col = a[0].col;
	d[0].r = 0;


	currenta = currentb = currentd = 1;
	while (currenta <= a[0].r && currentb <= b[0].r) {
		switch (compareComplex(a[currenta], b[currentb])) {
		case -1:
			d[currentd]=a[currenta];
			currentd++;currenta++;
			d[0].r++;
			break;
		case 0:
			if((a[currenta].r+b[currentb].r)!=0||(a[currenta].i+b[currentb].i)!=0){
				d[currentd].col=a[currenta].col;
				d[currentd].row=a[currenta].row;
				d[currentd].r=a[currenta].r+b[currentb].r;
				d[currentd].i=a[currenta].i+b[currentb].i;
				currentd;
				d[0].r++;
			}
			currenta++;currentb++;
			break;
		case 1:
			d[currentd]=b[currentb];
			currentd++;currentb++;
			d[0].r++;
			break;
		}
	}
	for (; currenta <= a[0].r; currenta++, currentd++) {
		d[currentd]=a[currenta];
	}
	for (; currentb <= b[0].r; currentb++, currentd++) {
		d[currentd]=b[currentb];
	}
}


void fastTranspose(tTermComplex a[], tTermComplex b[])
{
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a[0].col, numTerms = a[0].r;

	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].r = numTerms;

	if (numTerms > 0) {
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;
		for (i = 1; i <= numTerms; i++)
			rowTerms[a[i].col]++;
		startingPos[0] = 1;
		for (i = 1; i <= numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
		for (i = 1; i <= numTerms; i++) {
			j = startingPos[a[i].col]++;
			b[j].row=a[i].col;b[j].col=a[i].row;
			b[j].r=a[i].r;b[j].i=a[i].i;
		}
	}
}


void storeSum(tTermComplex d[], int* totalD, int row, int  col, int* sumR, int* sumI)
{
	if (!(*sumR) && !(*sumI)) {
		return;
	}
	else {
		if (*totalD < MAX_TERMS) {
			d[++*totalD].row=row;
			d[*totalD].col=col;
			d[*totalD].i=*sumI;
			d[*totalD].r=*sumR;
		}
		else {
			fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
			exit(EXIT_FAILURE);
		}
	}
}


void printSparseMat(tTermComplex a[])
{
	int i,j,k=1;

	for(i=0;i<a[0].row;i++){
		for(j=0;j<a[0].col;j++){
			if(a[k].row-1==i&&a[k].col-1==j){
				printf("%-d%+di\t ",a[k].r,a[k].i);
				k++;
			}
			else{
				printf("%d\t ",0);	
			}
		}
		printf("\n");
	}
}

void multSparseMat(tTermComplex a[], tTermComplex b[], tTermComplex d[])
{
	int i, j, column, totalB = b[0].r, totalD = 0;
	int rowsA = a[0].row, colsA = a[0].col, totalA = a[0].r;
	int colsB = b[0].col;
	int rowBegin = 1, row = a[1].row, sumR = 0, sumI = 0;
	tTermComplex newB[MAX_TERMS];

	if (colsA != b[0].row) {
		fprintf(stderr, "Incompatible matrices\n");
		exit(EXIT_FAILURE);
	}

	fastTranspose(b, newB);

	a[totalA + 1].row = rowsA;
	newB[totalB + 1].row = colsB;
	newB[totalB + 1].col = 0;

	for (i = 1; i <= totalA;) {
		column = newB[1].row;
		for (j = 1; j <= totalB + 1;) {
			if (a[i].row != row) {
				storeSum(d,&totalD,row,column,&sumR,&sumI);
				i=rowBegin;
				for(;newB[j].row==column;j++)
					;
				column = newB[j].row;
			}
			else if (newB[j].row != column) {
				storeSum(d,&totalD,row,column,&sumR,&sumI);
				i=rowBegin;
				column=newB[j].row;
			}
			else {
				switch (compare(a[i].col, newB[j].col)) {
				case -1:
					i++;break;
					break;
				case 0:
					sumR+=(a[i++].r*newB[j++].r);
					break;
				case 1:
					j++;
				}
			}
			for(;a[i].row==row;i++)
				;
			rowBegin=i;row=a[i].row;
		}
	}
	d[0].row = rowsA;
	d[0].col = colsB;
	d[0].r = totalD;
}

/* 파일이름으로부터 파일을 열고 
   파일로부터 희소행렬을 생성합니다. */
void initSparseMat(tTermComplex a[], char* filename)
{
	int count;
	int row, col;
	int r, i, j;
	FILE* fp = fopen(filename, "r");

	fscanf(fp, "%d %d %d", &row, &col, &count);
	a[0].row = row;
	a[0].col = col;
	a[0].r = count;
	for (j = 1; j <= count; j++) {
		fscanf(fp, "%d %d %d %d", &row, &col, &r, &i);
		a[j].row=row;
		a[j].col=col;
		a[j].r=r;
		a[j].i=i;
	}
}

void main(void)
{
	tTermComplex a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS], d[MAX_TERMS];
	int i=0;

	initSparseMat(a, "sparseA.txt");
	initSparseMat(b, "sparseB.txt");

	printf("Sparse Matrix A:\n");
	printSparseMat(a);
	
	printf("Sparse Matrix B:\n");
	printSparseMat(b);

	addSparseMat(a, b, c);
	printf("Sparse Matrix D = A + B:\n");
	printSparseMat(c);

	multSparseMat(a, b, d);
	printf("Sparse Matrix D = A * B:\n");
	printSparseMat(d);
}