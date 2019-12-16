#include <stdio.h>
#include <stdio.h>
#define MALLOC(p,s) p=malloc(s);

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

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
void connected();

int main (void){

	int i=0,j=0;
	graphListMake();
	printGraph();
	printf("<<<<<<<<<< Depth First Search >>>>>>>>>>\n");
	connected();
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
void connected(){

	int i,j=1;

	for(i=0;i<vertex;i++){
		if(!visited[i]){
			printf("connected component %d : ",j);
			j++;
			dfs(i);
			printf("\n");
		}
	}
}