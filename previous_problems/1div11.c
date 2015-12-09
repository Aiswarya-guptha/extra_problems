/*
programer         :aiswarya
aim                       :divisible by 11
time complexity: O(n/2)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

int funct(char* in,int len){
	int iter,count=0;
	//adds odd digits and substracts even digits
	for(iter=0;(iter+1)<len;iter++,iter++)
		count=count+in[iter]-in[iter+1];
	//adds the last digit
	if(iter<len)
		count=count+in[iter];
	if((count%11)==0)
		return 1;
	return 0;
}

void main(){

	char p[10000];
	int lenp,k,div;

	printf("enter length of p");
	scanf_s("%d",&lenp);
	fflush(stdin);
	
	printf("enter input");
	gets(p);
	fflush(stdin);

	printf("enter value of k");
	scanf_s("%d",&k);
	fflush(stdin);

	if((lenp & 01)&&(!(k & 01))){
		printf("\nQ divisible");
	}
	else{
		div=funct(p,lenp);

		if(div==1){
			printf("\nQ divisible");
		}
		else {
			printf("\nQ not divisible");
		}
	}
	_getch();
}