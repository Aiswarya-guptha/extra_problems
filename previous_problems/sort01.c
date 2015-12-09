/*
programer      :aiswarya
aim            :sorting array of 0's and 1's
time complexity:sort0 - O(n^2)   bubble sort
		sort1 - O(n)     count
		sort2 - O(n)     sum
		sort3 - O(log n) swap
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

void sort0(int *arr,int length){
	int iter,iter1,temp;
	printf("bubble \n");
	for(iter=0;iter<length-1;iter++)
		for(iter1=0;iter1<(length-iter-1);iter1++)
			if(arr[iter1]>arr[iter1+1]){
				//swap
				temp=arr[iter1];
				arr[iter1]=arr[iter1+1];
				arr[iter1+1]=temp;
			}
}

int *sort1(int *arr,int length){
	int count,iter,*res;
	for(iter=0;iter<length;iter++){
		if(arr[iter]==0){
			count++;
		}
	}
	for(iter=0;iter<=count;iter++){
		res[iter]=0;
	}
	for(;iter<length;iter++){
		res[iter]=1;
	}
}

void main(){

	int arr[100],length,iter,*res1,*dup=0;

	//takes inputs
	printf("enter length");
	scanf("%d",&length);
	printf("enter array of 0s and 1s ");
	for(iter=0;iter<length;iter++){
		scanf("%d",(arr+iter));
		if(arr[iter]!=1&&arr[iter]!=0){
			printf("error:wrong input");
			getch();
			return;
		}
		dup[iter]=arr[iter];
	}
	sort0(arr,length);
	for(iter=0;iter<length;iter++)	printf("%d ",arr[iter]);
	printf("count\n");
	res1=sort1(arr,length);
	for(iter=0;iter<length;iter++)	printf("%d ",res1[iter]);

	_getch();

}
