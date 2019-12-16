#include <stdio.h>
#include <stdio.h>
#define MALLOC(p,s) p=malloc(s);

//2015114398 �̿�ȣ
//������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�.

typedef struct listNode *listPointer;
typedef struct listNode {
	int vertex;
	listPointer link;
}listNode;

listPointer adjLists[100] = {NULL,};
int vertex,edge;
int visited[100]={0,};

void graphListMake();
void unDirectMake(FILE *);
void printGraph();
void dfs(int v);

int main (void){

	int i=0,j=0;
	graphListMake();
	printGraph();
	printf("<<<<<<<<<< Depth First Search >>>>>>>>>>\n");
	for(i=0;i<vertex;i++){
		printf("dfs<%d> : ",i);
		dfs(i);
		printf("\n");
		for(j=0;j<vertex;j++){
			visited[j]=0;
		}
	}

	return 0;
}

void graphListMake(){

	FILE *f=fopen("input.txt","r");
	
	fscanf(f,"%d %d",&vertex,&edge);

	unDirectMake(f);

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
	printf("\n");
}
void dfs(int v){

	listPointer w;

	visited[v]=1;
	printf("%5d",v);
	for(w=adjLists[v];w;w=w->link){
		if(!visited[w->vertex]){
			dfs(w->vertex);
		}
	}
}