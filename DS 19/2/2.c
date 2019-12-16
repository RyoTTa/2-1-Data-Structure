#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다

typedef struct Node{
	int key;
	char name[50];
	int grade;
}humanNode;

int total=0;
humanNode human[20];

void insert(humanNode,int i);
void insertionSort();
void makeHuman();
void printHuman();
void outputHuman();

int main(void){

	makeHuman();
	printf("<<<<<<<<<< Input List >>>>>>>>>>\n");
	printHuman();
	insertionSort();
	printf("<<<<<<<<<< Sorted List >>>>>>>>>>\n");
	printHuman();
	outputHuman();
	return 0;
}
void makeHuman(){

	FILE *f=fopen("input.txt","r");
	int i=0;

	fscanf(f,"%d",&total);
	for(i=1;i<=total;i++){
		fscanf(f,"%d %s %d",&human[i].key,human[i].name,&human[i].grade);
	}
	fclose(f);
}
void insert(humanNode e,int i){

	human[0]=e;
	while(e.key<human[i].key){
		human[i+1]=human[i];
		i--;
	}
	human[i+1]=e;
}
void insertionSort(){

	int j;
	for(j=2;j<=total;j++){
		humanNode temp=human[j];
		insert(temp,j-1);
	}
}
void printHuman(){

	int i=0;

	for(i=1;i<=total;i++){
		printf("<%3d, %s, %d>\n",human[i].key,human[i].name,human[i].grade);
	}
	printf("\n");
}
void outputHuman(){

	FILE *f=fopen("output.txt","w");
	int i=0;

	for(i=1;i<=total;i++){
		fprintf(f,"( %d, %s, %d )\n",human[i].key,human[i].name,human[i].grade);
	}
	fclose(f);
}