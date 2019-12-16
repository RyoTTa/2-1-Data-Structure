#include <stdio.h>
#include <stdlib.h>

//2015114398 이용호
//"본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다."

int count=0;

void add(int a[][4],int b[][4]){

	int i,j;
	
	for(i=0;i<3;i++){
		count++;
		for(j=0;j<4;j++){
			count++;
			a[i][j]=a[i][j]+b[i][j];
			count++;
		}
		count++;
	}
	count++;

}

int main(void){

	int a[3][4],b[3][4];
	int i,j;

	FILE *fa = fopen("a.txt","r");
	FILE *fb = fopen("b.txt","r");

	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			fscanf(fa,"%d",&a[i][j]);
		}		
	}
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			fscanf(fb,"%d",&b[i][j]);
		}
	}
	
	add(a,b);

	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%4d ",a[i][j]);
		}
		printf("\n");
	}

	printf("Matrix additon Program Step count = %d\n",count);
	fclose(fa);
	fclose(fb);

	return 0;
}