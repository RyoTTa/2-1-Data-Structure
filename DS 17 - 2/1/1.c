#include <stdio.h>
#include <stdio.h>
#define MALLOC(p,s) p=malloc(s);

typedef struct listNode *listPointer;
typedef struct listNode {
	int vertex;
	listPointer link;
}listNode;

listPointer adjLists[100] = {NULL,};
int vertex,edge;
char type;
void graphListMake();
void unDirectMake(FILE *);
void DirectMake(FILE *);
void printGraph();

int main (void){

	graphListMake();
	printGraph();

	return 0;
}

void graphListMake(){

	FILE *f=fopen("input.txt","r");
	
	fscanf(f,"%c %d %d",&type,&vertex,&edge);

	if(type=='u'){
		unDirectMake(f);
	}
	if(type=='d'){
		DirectMake(f);
	}
	fclose(f);
}
void unDirectMake(FILE *f){

	int temp=0,etemp1=0,etemp2=0;
	listPointer listtemp,ltemp;

	while(!feof(f)){
		fscanf(f,"%d %d",&etemp1,&etemp2);

		if(adjLists[etemp1]==NULL){
			MALLOC(listtemp,sizeof(*listtemp));
			listtemp->vertex=etemp2;
			listtemp->link=NULL;
			adjLists[etemp1]=listtemp;
		}
		else{
			MALLOC(listtemp,sizeof(listtemp));
			listtemp->vertex=etemp2;
			ltemp=adjLists[etemp1];
			adjLists[etemp1]=listtemp;
			listtemp->link=ltemp;
		}
		temp=etemp1;
		etemp1=etemp2;
		etemp2=temp;
		if(adjLists[etemp1]==NULL){
			MALLOC(listtemp,sizeof(*listtemp));
			listtemp->vertex=etemp2;
			listtemp->link=NULL;
			adjLists[etemp1]=listtemp;
		}
		else{
			MALLOC(listtemp,sizeof(listtemp));
			listtemp->vertex=etemp2;
			ltemp=adjLists[etemp1];
			adjLists[etemp1]=listtemp;
			listtemp->link=ltemp;
		}
	}
}
void DirectMake(FILE *f){

	int temp=0,etemp1=0,etemp2=0;
	listPointer listtemp,ltemp;

	while(!feof(f)){
		fscanf(f,"%d %d",&etemp1,&etemp2);

		if(adjLists[etemp1]==NULL){
			MALLOC(listtemp,sizeof(*listtemp));
			listtemp->vertex=etemp2;
			listtemp->link=NULL;
			adjLists[etemp1]=listtemp;
		}
		else{
			MALLOC(listtemp,sizeof(listtemp));
			listtemp->vertex=etemp2;
			ltemp=adjLists[etemp1];
			adjLists[etemp1]=listtemp;
			listtemp->link=ltemp;
		}
	}
}

void printGraph(){

	listPointer temp;
	int i=0;
	
	printf("<<<<<<<<<< Adjacency List>>>>>>>>>>\n");
	for(i=0;i<vertex;i++){
		printf("adjLists[%d] : ",i);
		temp=adjLists[i];
		while(temp!=NULL){
			printf("%5d",temp->vertex);
			temp=temp->link;
		}
		printf("\n");
	}
}