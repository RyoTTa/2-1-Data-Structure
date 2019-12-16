//2015114398 이용호

/***************************************************
// 자료구조응용 Lab 6. Q3. 
//  stack - infix to postfix expression
// input.txt    : a*(b+c)*d 
// output.txt  : abc+*d*
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

// infix to postfix
typedef enum { lparen, rparen, and, or, nots, divide,
							mod, eos, operand } precedence;
/* isp and icp arrays -- index is value of precedence
	lparen, rparen, and, or, nots, divide, mod, eos */
int isp[] = { 0, 19, 12, 12, 13, 13,13, 0};
int icp[] = { 20, 19, 12, 12, 13, 13,13, 0};
void postfix(void);
precedence getToken(char *symbol, int *n);
void printToken(precedence);

// stack 
precedence stack[MAX_STACK_SIZE];
int top = -1;
void push(precedence item);
void stackFull();
precedence pop();
precedence stackEmpty();

// infix expression 
char expr[81];
FILE *fpI, *fpP;	// input(infix), output(postfix)

int main(void)
{
	int result;                      

	if( !(fpI = fopen("infix.txt", "r")) || !(fpP = fopen("postfix.txt", "w")) )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fgets(expr, 80, fpI); // input infix expression
	printf("<<<<<<<<<< infix to postfix >>>>>>>>>>>>>\n");
	printf("infix expression\t: %s\n", expr);
	printf("postfix expression\t: ");	
	
	postfix();	// infix to postfix

	fclose(fpI);
	fclose(fpP);

	return 0;
}

// Program 3.15: Function to convert from infix to postfix
void postfix(void)
{
	char symbol;
	precedence token;
	int n = 0;
	top = -1;	
	stack[++top] = eos; /* place eos on stack */

	for ( token = getToken( &symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if ( token == operand )
		{
			printf("%c", symbol);
			fprintf( fpP, "%c", symbol );
		}
		else if ( token == rparen)	{
			/* unstack tokens until left parenthesis */
			while (stack[top] != lparen)
				printToken(pop());
			pop();	/* discard the left parenthesis */
		}
		else { // operator, lparen
			/* remove and print symbols whose isp is greater
				than or equal to the current token's icp */
			while ( isp[stack[top]] >= icp[token] )
				printToken(pop());
			push(token);
		}
	}

	while ( ( token = pop()) != eos )
		printToken(token);
	printf("\n");
}

// Program 3.14: Function to get a token from the input string
precedence getToken(char *symbol, int *n)
{ /* get the next token, symbol is the character representation, 
	whichis returned, the tokenis represented by its enumerated value, 
	which is returned inthe function name */
	*symbol = expr[ (*n)++ ];
	switch ( *symbol) 
	{
			case '('		: return lparen;
			case ')'		:  return rparen;
			case '&'		: return and;
			case '|'		: return or;
			case '~'		: return nots;
			case '%'	: return mod;
			case '\0'	: return eos;
			default		: return operand; /* no error checking, default is operand */
	}
}

void printToken(precedence pre)
{
	switch ( pre) 
	{
		// in postfix expression, there are no parentheses
		case and		:	printf( "%c", '&' );	fprintf( fpP, "%c", '&' );	break;
		case or		:	printf( "%c", '|' );	fprintf( fpP, "%c", '|' );	break;
		case nots		:	printf( "%c", '~' );	fprintf( fpP, "%c", '~' );	break;
		case mod		:	printf( "%c", '%' );	fprintf( fpP, "%c", '%' );	break;
		case eos		:	printf( "%c", '\0' );	fprintf( fpP, "%c", '\0' );	break;
		default			:	;	// operand
	}

}

/////////////////////// stack operations ///////////////////////////////////
precedence pop()
{/* delete and return the top int from the stack */
	if ( top == -1 )
		return stackEmpty();	/* returns an error key */
	return stack[top--];
}

precedence stackEmpty()
{
	precedence item;
	item = operand;  // error key! In this program, operand is used for error key, since stack has only operators.
	return item;
}

void push(precedence item)
{/* add an item to the global stack */
	if ( top >= MAX_STACK_SIZE-1 )
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	precedence item;
	fprintf(stderr, "stack is full, cannot add int\n");
	exit(EXIT_FAILURE);
}
