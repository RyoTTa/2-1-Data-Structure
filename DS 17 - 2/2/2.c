#include <stdio.h>
#include <stdio.h>
#define MALLOC(p,s) p=malloc(s);

typedef enum { FALSE, TRUE } tBoolean;
typedef struct edge* tEdgePointer;
typedef struct edge
{
	tBoolean marked; // TRUE or FALSE
	int vertex1;
	int vertex2;
	tEdgePointer link1;
	tEdgePointer link2;
}tEdge;

tEdgePointer* adjMulList;			// ※ 동적할당으로 구현
tEdgePointer* edgelist;
tEdgePointer print;
int vertex,edge;
int count=0;

void createEdge();	// create the edge node
void addEdge( int ver1, int ver2); 
void printMultilist(int choice);	// choice: 0 or 1

int vertex,edge;
char type;

int main (void){

	createEdge();
	printf("<<<<<<<<<<edges incident to each vertex>>>>>>>>>>\n\n");
	printMultilist(1);
	printMultilist(2);
	return 0;
}
void createEdge(){

	FILE *f=fopen("input.txt","r");
	int vtemp1=0,vtemp2=0,i=0,j=0;

	fscanf(f,"%d %d",&vertex,&edge);
	MALLOC(edgelist,sizeof(*edgelist)*edge);
	for(i=0;i<edge;i++){
		MALLOC(edgelist[i],sizeof(**edgelist));
	}
	MALLOC(adjMulList,sizeof(*adjMulList)*vertex);

	while(!feof(f)){
		fscanf(f,"%d %d",&vtemp1,&vtemp2);
		addEdge(vtemp1,vtemp2);
	}
	for(i=0;i<edge;i++){
		vtemp1=edgelist[i]->vertex1;
		vtemp2=edgelist[i]->vertex2;
		for(j=i+1;j<edge;j++){
			if(vtemp1==edgelist[j]->vertex1||vtemp1==edgelist[j]->vertex2){
				edgelist[i]->link1=edgelist[j];
				break;
			}
		}
		for(j=i+1;j<edge;j++){
			if(vtemp2==edgelist[j]->vertex1||vtemp2==edgelist[j]->vertex2){
				edgelist[i]->link2=edgelist[j];
				break;
			}
		}
	}
	for(i=0;i<edge;i++){
		vtemp1=edgelist[i]->vertex1;
		vtemp2=edgelist[i]->vertex2;
		for(j=0;j<edge;j++){
			if(i==edgelist[j]->vertex1||i==edgelist[j]->vertex2){
				adjMulList[i]=edgelist[j];
				break;
			}
		}
	}
	fclose(f);
}
void addEdge( int ver1, int ver2){

	edgelist[count]->marked=TRUE;
	edgelist[count]->vertex1=ver1;
	edgelist[count]->vertex2=ver2;
	edgelist[count]->link1=NULL;
	edgelist[count]->link2=NULL;
	count++;
}
void printMultilist(int choice){

	int vtemp1=0,vtemp2=0,i=0,j=0,vertemp=0;

	if(choice==1){
		printf("간선의 정점 출력 순서 - 입력데이터 순서대로\n");
		for(i=0;i<vertex;i++){
			print=adjMulList[i];
			printf("edges incident to vertex %d : ",i);
			while(print){
				printf("<%d, %d> ",print->vertex1,print->vertex2);
				if(i==print->vertex1){
					print=print->link1;
				}
				else{
					print=print->link2;
				}
			}
			printf("\n");
		}
	}
	else{
		printf("간선의 정점 출력 순서 - 헤더노드 정점이 먼저 오게\n");
		for(i=0;i<vertex;i++){
			print=adjMulList[i];
			printf("edges incident to vertex %d : ",i);
			while(print){
				if(print->vertex1==i){
					printf("<%d, %d> ",print->vertex1,print->vertex2);
				}
				else{
					printf("<%d, %d> ",print->vertex2,print->vertex1);
				}
				if(i==print->vertex1){
					print=print->link1;
				}
				else{
					print=print->link2;
				}
			}
			printf("\n");
		}
	}
	printf("\n");
}