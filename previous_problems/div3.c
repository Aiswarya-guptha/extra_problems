/*
programer         :aiswarya
aim                       :print date in words
time complexity: O(1)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

int funct(char* in,int len,int k){
	int iter,count=0,num=0;
	
	while(k > 0){
		//adds odd positioned binary bit
		if(k & 01)		count++;
		k>>=1;
		//substracts even positioned binary bit
		if(k & 01)		count--;
		k>>=1;
	}
	
	//converts negative count to positive
	if(count<0)			count=count-(2*count);
	if(count % 3==0)	return 1;
	
	//converts to number 
	for(iter=0,num=0;iter<len;iter++)
		num=(num*10)+(in[iter]-'0');
	
	//checks if it is divisible by 3
	count=0;
	while(num>0){
		if(num&01)		count++;
		num>>=1;
		if(num&01)		count--;
		num>>=1;
	}
	
	//converts negative count to positive
	if(count<0)			count=count-(2*count);
	if(count % 3==0)	return 1;
	return 0;
}

void main(){

	char *p;
	int lenp,k;

	printf("enter length of p : ");
	scanf_s("%d",&lenp);
	fflush(stdin);

	p=(char *)malloc(lenp);
	printf("enter input : ");
	gets(p);
	fflush(stdin);

	printf("enter value of k : ");
	scanf_s("%d",&k);
	fflush(stdin);
	
	if(funct(p,lenp,k)==1)		printf("\nQ divisible");
	else						printf("\nQ not divisible");
	_getch();
}