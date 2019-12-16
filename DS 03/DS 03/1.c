#include <stdio.h>
#include <time.h>
#include "selectionsort.h"
#define MAX_SIZE 2001

//2015114398
//"������ �� �ҽ������� �ٸ� ����� �ҽ��� �������� �ʰ� ���� �ۼ��Ͽ����ϴ�."

int main(void){

	int i,n,step = 10;
	int a[MAX_SIZE];
	double duration;
	FILE *f=fopen("out.txt","w");
	clock_t start;

	printf("     n     time\n");
	fprintf(f,"     %s      %s\n","n","time");
	for(n=0;n<=2000;n+=step){
		for(i=0;i<n;i++){
			a[i]=n-i;
		}
		start = clock();
		sort(a,n);
		duration = ((double) (clock() - start))/CLOCKS_PER_SEC;
		printf("%6d    %f\n",n,duration);
		fprintf(f,"%6d    %f\n",n,duration);
		if (n==100){
			step=100;
		}

	}

	return 0;
}