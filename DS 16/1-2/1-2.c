#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s) p=malloc(s)
//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
typedef struct node *tListNodePointer;
typedef struct node {
	char data;
	tListNodePointer link;
}tListNode;

tListNodePointer head=NULL;
tListNodePointer copyhead=NULL;

tListNodePointer initList(char* str);
int isPalindrome(tListNodePointer head);
tListNodePointer copy(tListNodePointer head);
tListNodePointer invert(tListNodePointer lead);

int main(void){

	char string[30];
	int check=0;
	tListNodePointer temp;

	printf("Enter the string to check palindrome: ");
	scanf("%s",string);
	head=initList(string);
	temp=head;
	printf("initial linked list: ");
	while(temp!=NULL){
		printf("%c ",temp->data);
		temp=temp->link;
	}
	printf("\n");
	check=isPalindrome(head);
	temp=copyhead;
	printf("inverted linked list: ");
	while(temp!=NULL){
		printf("%c ",temp->data);
		temp=temp->link;
	}
	printf("\n");
	if(check==1){
		printf("%s is palindrome\n",string);
	}
	else{
		printf("%s in not palindrome\n",string);
	}
	return 0;
}
tListNodePointer initList(char* str){

	int i;
	tListNodePointer temp,check;

	for(i=0;str[i]!=NULL;i++){
		if(head==NULL){
			MALLOC(temp,sizeof(*temp));
			temp->data=str[i];
			temp->link=NULL;
			head=temp;
		}
		else{
			MALLOC(temp,sizeof(*temp));
			check=head;
			while(check->link!=NULL) check=check->link;
			temp->data=str[i];
			temp->link=NULL;
			check->link=temp;
		}
	}
	return head;
}
int isPalindrome(tListNodePointer head){

	tListNodePointer HEAD,COPY;

	copyhead=copy(head);
	copyhead=invert(copyhead);
	HEAD=head;COPY=copyhead;
	while(HEAD!=NULL||COPY!=NULL){
		if(HEAD->data!=COPY->data){
			return 0;
		}
		else{
			HEAD=HEAD->link;
			COPY=COPY->link;
		}
	}
	return 1;
	
}
tListNodePointer copy(tListNodePointer head){

	tListNodePointer copy=NULL,temp,tempF,check;
	temp=head;

	while(temp!=NULL){
		if(copy==NULL){
			MALLOC(tempF,sizeof(*tempF));
			tempF->data=temp->data;
			tempF->link=NULL;
			copy=tempF;
		}
		else{
			MALLOC(tempF,sizeof(*tempF));
			check=copy;
			while(check->link!=NULL) check=check->link;
			tempF->data=temp->data;
			tempF->link=NULL;
			check->link=tempF;
		}
		temp=temp->link;
	}
	return copy;
}
tListNodePointer invert(tListNodePointer lead){

	tListNodePointer middle,trail;
	middle=NULL;
	while(lead){
		trail=middle;
		middle=lead;
		lead=lead->link;
		middle->link=trail;
	}
	return middle;
}