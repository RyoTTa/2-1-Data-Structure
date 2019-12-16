#include <stdio.h>
#include <stdlib.h>
 
#define TRUE 1
#define FALSE 0
#define REALLOC(o, p, s) \
if (o == p && !((p) = (element*)realloc(p, s))) { \
        free(o); \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);\
}
typedef struct {
	short int vert;
	short int horiz;
} offsets;
 
typedef struct {
	short int row;
	short int col;
	short int dir;
} element;
 
offsets move[8] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };
 
element *stack = NULL;
element *p=NULL;
int **maze = NULL;
int capacity=1;
int **mark = NULL;
 
void path(void);
element pop();
void push(element item);
int **make2dArray(int, int);
void free2dArray(int **, int);
void initmaze(int row, int col);
void initmark(int row, int col);
void stackFull();
int EXIT_ROW;
int EXIT_COL;
int top = 0;
 
int main(void)
{
	FILE *f = fopen("input.txt", "r");
	int row, col, i, j;
	fscanf(f, "%d %d", &row, &col);
	EXIT_ROW = row;
	EXIT_COL = col;
	fclose(f);
 
	maze = make2dArray(row, col);
	initmaze(row,col);
	mark = make2dArray(row, col);
	initmark(row,col);
	stack = (element*)malloc(sizeof(element)*(capacity+6));
 
	path();
	free2dArray(maze, row);
	free2dArray(mark, row);
	free(stack);
	fclose(f);
 
	return 0;
}
 
void path(void)
{
	int i, row, col, nextRow, nextCol, dir, found = FALSE;
	element position;
	mark[1][1] = 1; top = 0;
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 0;
 
	while (top > -1 && !found)
	{
		position = pop();
		row = position.row; col = position.col; dir = position.dir;
 
		while (dir < 8 && !found)
		{
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
 
			if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
			{
				found = TRUE;
			}
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
			{
				mark[nextRow][nextCol] = 1;
				position.row = row; position.col = col; position.dir = ++dir;
				push(position);
				row = nextRow; col = nextCol; dir = 0;
			}
			else
				++dir;
		}
	}

	if (found)
	{
		printf("The path is : \n");
		printf("row col\n");
		for (i = 0; i < top; i++)
		{
			printf("%2d%5d\n", stack[i].row, stack[i].col);
		}
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
	}
	else
		printf("The maze does not have a path\n");
}
 
element pop()
{
	return stack[top--];
}
 
void push(element item)
{
	if (top==(capacity-1)){
		stackFull();
	}
	stack[++top] = item;
}
void stackFull(){
	
	REALLOC(p,stack,capacity*2);
	capacity=capacity*1;
}

int **make2dArray(int row, int col)
{
	int **temp;
	int i, j;
 
	temp = (int**)malloc(sizeof(int)*(row + 2));
	for (i = 0; i < row + 2; i++)
	{
		temp[i] = (int*)malloc(sizeof(int)*(col + 2));
	}
 
	for (i = 0; i < row + 2; i++)
	{
		for (j = 0; j < col + 2; j++)
		{
			temp[i][j] = 0;
		}
	}
 
	return temp;
}
 
void free2dArray(int ** a, int row)
{
	int i;
 
	for (i = 0; i < row + 2; i++)
	{
		free(a[i]);
	}
	free(a);
	/*for (i = 0; i < row + 2; i++)
	{
		free(mark[i]);
	}
	free(mark);*/
}
void initmaze(int row, int col)
{
	int i=0,j=0;
 
	FILE *f=fopen("input.txt","r");
	fscanf(f,"%d %d",&i,&j);
	for (i = 0; i < row + 2; i++)
	{
		for (j = 0; j < col + 2; j++)
		{
			if (i == 0 || i == (row + 1))
			{
				maze[i][j] = 1;
			}
			else if (j == 0 || j == (col + 1))
			{
				maze[i][j] = 1;
			}
			else
			{
				fscanf(f, "%d", &maze[i][j]);
			}
		}
	}
}
void initmark(int row, int col)
{
	int i=0, j=0;
 
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			mark[i][j]=0;
		}
	}
}
