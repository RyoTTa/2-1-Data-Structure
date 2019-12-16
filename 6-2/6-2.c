#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)\
	if(!((p)=malloc(s))){\
	fprintf(stderr,"Insufficient memory");\
	exit(EXIT_FAILURE);\
	}

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int main(void) 
{
	int i, *pi;
	float f, *pf;
	
	MALLOC(pi,sizeof(int));
	MALLOC(pf,sizeof(float));
	*pi=1024;
	*pf=3.14;
	printf("an integer = %d, a float = %f\n",*pi,*pf);
	free(pi);
	free(pf);

	return 0;
}
