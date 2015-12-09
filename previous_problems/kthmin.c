/*
programer         :aiswarya
aim                       :kth min term of two sorted arrays
time complexity: O(k)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

int func(int *arr0,int len0,int *arr1,int len1,int k){
	int iter0=0,iter1=0,count=1;
	
	while((iter0!=len0)&&(iter1!=len1)&&(count<k)){
		if(arr0[iter0]<arr1[iter1])		iter0++;
		else							iter1++;
		count++;
	}
	if(count==k){
		if(arr0[iter0]<arr1[iter1])		return arr0[iter0];
		else							return arr1[iter1];
	}
	//if any of the array is exceded
	else{
		if(iter0==len0)					return arr1[iter1+k-count];
		else							return arr0[iter0+k-count];
	}								
}
void main(){
	int iter,len0,len1,*arr0,*arr1,found,k;
	
	//taking input of array1
	printf("enter length of first array");
	scanf_s("%d",&len0);
	fflush(stdin);
	arr0 =(int *)malloc(len0);
	printf("enter first array");
	for(iter=0;iter<len0;iter++)
		scanf_s("%d",(arr0+iter));
	fflush(stdin);
	
	//taking input of array2
	printf("enter length of second array");
	scanf_s("%d",&len1);
	fflush(stdin);
	arr1=(int *)malloc(len1);
	printf("enter second array");
	for(iter=0;iter<len1;iter++)
		scanf_s("%d",(arr1+iter));
	fflush(stdin);
	
	//taking k value
	printf("enter k value");
	scanf_s("%d",&k);
	fflush(stdin);

	found= func(arr0,len0,arr1,len1,k);

	printf("k th smallest element is: %d",found);
	_getch();
}