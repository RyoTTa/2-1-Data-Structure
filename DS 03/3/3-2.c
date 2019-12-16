#include<stdio.h>
#include<time.h>
#include"selectionsort.h"
#define MAX_SIZE 2001

//2015114398
//"본인은 이 소스파일을 다른 사람의 소스를 복사하지 않고 직접 작성하였습니다."

int main(void){

	int i,n,step=10;
	int arr[MAX_SIZE];
	double duration;
	FILE *f=fopen("out.txt","w");

	fprintf(f,"     %s      %s       %s\n","n","repetitions","time");
	printf("     n     repetitions     time\n");
	for(n=0;n<=2000;n+=step){
		long repetitions = 0;
		clock_t start = clock();
		do{
			repetitions++;
			for(i=0;i<n;i++){
				arr[i]=i;
			}
			sort(arr,n);
		}while(clock()-start<1000);

		duration = ((double) (clock()-start))/CLOCKS_PER_SEC;
		duration /= repetitions;
		printf("%6d    %9d        %f\n",n,repetitions,duration);
		fprintf(f,"%6d       %9d       %f\n",n,repetitions,duration);
		if(n==100)step=100;

	}


	return 0;
}