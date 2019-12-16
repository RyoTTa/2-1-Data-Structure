#include <stdio.h>
#include <stdlib.h>
 
#define MAX_STACK_SIZE 80
 
typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;
int stack[MAX_STACK_SIZE];
int top = 0;
 
char arr[80];
 
int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
 
void postfix(void);
void push(char);
int pop();
precedence getToken(char*, int*);
void printToken(int);
 
FILE* fi;
FILE* fo;
int main()
{
	fi = fopen("input.txt", "r");
	fo = fopen("output.txt", "w");
 
	fscanf(fi, "%s", &arr);
	printf("<<<<<<<< infix to postfix >>>>>>>>\n");
	printf("infix expression     : %s\n",arr);
	printf("postfix expression   : ");
	postfix();
 
	fcloseall();
}
 
void postfix(void)
{
	precedence token;
	char symbol;
	int n = 0;
	stack[0] = eos;
	
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n)){
		if (token == operand){
			printf("%c", symbol);
			fprintf(fo, "%c", symbol);
		}
		else if (token == rparen){
			while (stack[top] != lparen){
				printToken(pop());
			}
			pop();
		}
		else{
			while (isp[stack[top]] >= icp[token]){
				printToken(pop());
			}
			push(token);
		}
	}
	while ((token = pop()) != eos){
		printToken(token);
	}
	printf("\n");
}
 
void push(char item)
{
	stack[++top] = item;
}
 
int pop()
{
	return stack[top--];
}
 
precedence getToken(char * symbol, int * n)
{
	*symbol = arr[(*n)++];
 
	switch (*symbol){
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '*': return times;
	case '/': return divide;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}
}
 
void printToken(int i)
{
	switch (i){
	case lparen:
		printf("%c", '(');fprintf(fo, "%c", '(');
		break;
	case rparen:
		printf("%c", ')');fprintf(fo, "%c", ')');
		break;
	case plus:
		printf("%c", '+');fprintf(fo, "%c", '+');
		break;
	case minus:
		printf("%c", '-');fprintf(fo, "%c", '-');
		break;
	case times:
		printf("%c", '*');fprintf(fo, "%c", '*');
		break;
	case divide:
		printf("%c", '/');fprintf(fo, "%c", '/');
		break;
	case mod:
		printf("%c", '%');fprintf(fo, "%c", '%');
		break;
	}
}