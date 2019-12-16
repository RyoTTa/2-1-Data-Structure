#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 24
#define FALSE 0
#define TRUE 1
#define MALLOC(p,s)\
	if(!((p) = malloc(s))){\
	fprintf(stderr, "insufficient Memory");\
	exit(EXIT_FAILURE);\
	}

//학번 이름
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct node *nodePointer;
typedef struct node{
	int data;
	nodePointer link;
}node;

void main(void){

	short int out[MAX_SIZE];
	nodePointer seq[MAX_SIZE];
	nodePointer x,y,top;
	FILE *f=fopen("input.txt","r");
	int i,j,n,count=0;;
	
	fscanf(f,"%d",&n);
	printf("/*MAX_SIZE of a set S : 24*/\n");
	printf("current size of S : %d\n",n);
	for(i=0;i<n;i++){
		out[i]=FALSE;seq[i]=NULL;
	}
	printf("S = <");
	for(i=0;i<n;i++){
		printf(" %d",i);
		if(i==n-1){
			printf(" >\n");
		}
		else{
			printf(",");
		}
	}
	printf("input pairs :");
	while(!feof(f)){
		fscanf(f,"%d%d",&i,&j);
		printf(" %dR%d",i,j);
		MALLOC(x,sizeof(*x));
		x->data=j;x->link=seq[i];seq[i]=x;
		MALLOC(x,sizeof(*x));
		x->data=i;x->link=seq[j];seq[j]=x;
	}
	printf("\n");
	for(i=0;i<n;i++){
		if(out[i]==FALSE){
			printf("\nNew class: %5d",i);
			out[i]=TRUE;
			x=seq[i];top=NULL;
			for(;;){
				while(x){
					j=x->data;
					if(out[j]==FALSE){
						printf("%5d",j);out[j]=TRUE;
						y=x->link;x->link=top;top=x;x=y;
					}
					else{
						x=x->link;
					}
				}
				if(!top)break;
				x=seq[top->data];top=top->link;
			}
		}
	}
	printf("\n");
}