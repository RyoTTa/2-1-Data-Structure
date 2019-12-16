#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다.

int sumAry1D_f1( int ary[], int size ); // 배열파라미터, 배열크기  // 권장
int sumAry1D_f2( int *ary,  int size ); // 배열포인터, 배열크기
int sumAry1D_f3( int ary[6],  int size ); 

int main(void) 
{
	int ary1D[ ] = {1, 2, 3, 4, 5, 6};
	return 0;
}

	printf("sumAry1D_f1() %d\n", sumAry1D_f1(ary1D,6));
	printf("sumAry1D_f2() %d\n", sumAry1D_f2(ary1D,6));
	printf("sumAry1D_f3() %d\n", sumAry1D_f3(ary1D,6));


int sumAry1D_f1( int ary[], int size ){

	int i, result=0;

	for(i=0;i<size;i++){
		result=result+ary[i];
	}
	return result;
}

int sumAry1D_f2( int *ary,  int size ){

	int i, result=0;

	for(i=0;i<size;i++){
		result=result+*(ary++);
	}
	return result;
}

int sumAry1D_f3( int ary[6],  int size ){

	int i, result=0;

	for(i=0;i<size;i++){
		result=result+ary[i];
	}
	return result;
}

