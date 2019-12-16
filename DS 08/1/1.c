#define MAX_STACK_SIZE 60

#include <stdio.h>
#include <stdlib.h>

typedef enum{lparen,rparen,plus,minus,times,divide,mod,eos,operand}precedence;

int stack[MAX_STACK_SIZE];
int top = -1;
char input[80];

int eval(void);
precedence getToken(char *symbol,int *n);

int main (void){

	int sum=0;
	FILE *f=fopen("input.txt","r");

	fscanf(f,"%s",input);

	printf("postfix expression : %s\n",input);
	sum=eval();

	printf("the evaluation value : %d\n",sum);
}

void push(int item){

	stack[++top]=item;
}

int pop(){

	return stack[top--];
}

int eval(void){

	precedence token;
	char symbol;
	int op1,op2;
	int n=0;
	
	top=-1;
	token=getToken(&symbol,&n);
	while(token!=eos){
		if(token==operand){
			push(symbol-'0');
		}
		else{
			op2=pop();
			op1=pop();
			switch(token){
			case plus : push(op1+op2);
				break;
			case minus : push(op1-op2);
				break;
			case times : push(op1*op2);
				break;
			case divide : 
				if(op2!=0){
					push(op1/op2);
				}
				break;
			case mod : push(op1%op2);
			}
		}
		token=getToken(&symbol,&n);
	}
	return pop();
}

precedence getToken(char *symbol,int *n){
	
	*symbol=input[(*n)++];
	
	switch(*symbol){
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	case '%' : return mod;
	case '\0' : return eos;
	default : return operand;
	}
}