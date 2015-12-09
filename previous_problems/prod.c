/*
programer         :aiswarya
aim                       :product of array excluding itself
time complexity: O(n)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

int *function(int* arr,int length){
	int iter,lma[100],store;
	lma[0]=1;
	for(iter=1;iter<length;iter++)		//left multiplied values
		lma[iter]=lma[iter-1]*arr[iter-1];
	store=1;
	for(iter=(length-1);iter>=0;iter--){	//right multiplied values
		lma[iter]=lma[iter]*store;
		store=store*arr[iter];
	}	
	return lma;
}
void main(){

	int iter,length,arr[100],*prod;
	
	//taking input
	printf("enter length");
	scanf_s("%d",&length);

	printf("enter arr");
	for(iter=0;iter<length;iter++)	scanf("%d",(arr+iter));

	prod=function(arr,length);

	for(iter=0;iter<length;iter++)	printf("%d ",prod[iter]);

	_getch();
}
