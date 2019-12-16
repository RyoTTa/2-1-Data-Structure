#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int main(void) 
{
	int i, *pi;
	float f, *pf;
	
	if((pi=(int*)malloc(sizeof(int)))==NULL||(pf=(float*)malloc(sizeof(float)))==NULL){
		fprintf(stderr,"Insufficient memory");
		exit(EXIT_FAILURE);
	}
	*pi=1024;
	*pf=3.14;
	printf("an integer = %d, a float = %f\n",*pi,*pf);
	free(pi);
	free(pf);

	return 0;
}
