#include<stdio.h>
#include<math.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y),(y)=(t))

void sort(int arr[],int n){

	int i,j,min,temp;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
			SWAP(arr[i],arr[min],temp);
		}
	}

}