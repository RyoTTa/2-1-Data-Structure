#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FALSE 0
#define TRUE 1

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

typedef struct human{

	char name[50];
	int age;
	int salary;

}t_human;

int humanEqual(t_human *person1,t_human *person2);

int main (void){

	t_human s_human[2];
	int i=0;

	for(i=0;i<2;i++){
		printf("Input person%d's name, age, salary : \n",i+1);
		fflush(stdin);
		gets(s_human[i].name);
		scanf("%d",&s_human[i].age);
		scanf("%d",&s_human[i].salary);
	}
	if(humanEqual(&s_human[0],&s_human[1])){
		printf("The two human beings are the same\n");
	}
	else{
		printf("The two human beings are not the same\n");
	}
}

int humanEqual(t_human *person1,t_human *person2){

	if(strcmp((*person1).name,(*person2).name))
		return FALSE;
	if((*person1).age!=(*person2).age)
		return FALSE;
	if((*person1).salary!=(*person2).salary)
		return FALSE;
	return TRUE;
}