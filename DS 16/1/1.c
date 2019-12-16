#include <stdio.h>
#include <stdlib.h>
//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.
int isPalindrome(char* str);

int main (void){

	char string[10];

	printf("Enter the string to check palindrome: ");
	scanf("%s",string);

	if(isPalindrome(string)){
		printf("%s is palindrome\n",string);
	}
	else{
		printf("%s is not palindrome\n",string);
	}

	return 0;
}
int isPalindrome(char* str){

	int i=0,check=0;

	for(i=0;str[i]!=NULL;i++){
		check=i;
	}
	for(i=0;i<=check;i++,check--){
		if(str[i]!=str[check]){
			return 0;
		}
	}
	return 1;
}