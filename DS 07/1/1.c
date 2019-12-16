#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0

//2015114398
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct{
	short int row;
	short int col;
	short int dir;
}element;

typedef struct{
	short int vert;
	short int horiz;
}offsets;

int top=-1;
int EXIT_ROW, EXIT_COL;
element stack[MAX_STACK_SIZE];
offsets move[8];
int mark[12][12];
int maze[12][12];

void path();
element stackEmpty();
element pop();
void push(element item);
void stacFull();
void First();

int main(void){

	int i=0,j=0;
	FILE *f=fopen("input.txt","r");

	First();

	fscanf(f,"%d",&EXIT_ROW);
	fscanf(f,"%d",&EXIT_COL);

	for(i=1;i<EXIT_ROW+1;i++){
		for(j=1;j<EXIT_COL+1;j++){
			fscanf(f,"%d",&maze[i][j]);
		}
	}
	path();
}

void First(){

	int i=0,j=0;

	move[0].vert=-1;move[0].horiz=0;
	move[1].vert=-1;move[1].horiz=1;
	move[2].vert=0;move[2].horiz=1;
	move[3].vert=1;move[3].horiz=1;
	move[4].vert=1;move[4].horiz=0;
	move[5].vert=1;move[5].horiz=-1;
	move[6].vert=0;move[6].horiz=-1;
	move[0].vert=-1;move[0].horiz=-1;

	for(i=0;i<12;i++){
		for(j=0;j<12;j++){
			mark[i][j]=0;
			maze[i][j]=1;
		}
	}
}

void push(element item){

	stack[++top]=item;
}

element pop(){

	return stack[top--];
}

void path(){

	int i,row,col,nextRow,nextCol,dir,found=FALSE;
	element position;
	mark[1][1]=1;top=0;
	stack[0].row=1;stack[0].col=1;stack[0].dir=0;

	while(top>-1&&!found){
		position=pop();
		row=position.row;col=position.col;
		dir=position.dir;
		while(dir<8&&!found){
			nextRow=row+move[dir].vert;
			nextCol=col+move[dir].horiz;
			if(nextRow==EXIT_ROW&&nextCol==EXIT_COL){
				found=TRUE;
			}
			else if(!maze[nextRow][nextCol]&&!mark[nextRow][nextCol]){
				mark[nextRow][nextCol]=1;
				position.row=row;position.col=col;
				position.dir=++dir;
				push(position);
				row=nextRow;col=nextCol;dir=0;
			}
			else{
				++dir;
			}
		}
	}
	if(found){
		printf("The path is:\n");
		printf("row  col\n");
		for(i=0;i<=top;i++){
			printf("%2d%5d\n",stack[i].row,stack[i].col);
		}
		printf("%2d%5d\n",row,col);
		printf("%2d%5d\n",EXIT_ROW,EXIT_COL);
	}
	else{
		printf("The maze does not have a path\n");
	}
}