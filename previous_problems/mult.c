/*
programer         :aiswarya
aim                       :multiply with bitwise operators
time complexity: O(n^2)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

int func(int num,int num1){
	int temp,res,carry,dup;
	if(num>num1){
		temp=num;
		num=num1;
		num1=temp;
	}

	res=0;

	while(num!=0){
		if(num & 01){
			dup=num1;
			while(dup){
				carry=res&dup;
				res=dup^res;
				dup=carry<<1;
			}
		}
		num=num>>1;
		num1=num1<<1;
	}
	return res;
}

void main(){
	int num,num1,res;

	//taking inputs
	printf("enter two numbers");
	scanf_s("%d %d",&num,&num1);

	res=func(num,num1);
	printf("multipication: %d",res);
	_getch();
}

