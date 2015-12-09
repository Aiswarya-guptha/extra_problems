/*
programer			:aiswarya
aim                 :convert decimal into base(-2)
time complexity		: O(n)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int* func(int in){
	int carry=0,iter=31,*base;
	base=(int *) malloc(sizeof(int)*(32));

	while(in>0 || carry == 1){
		//if carry and input both are 1 input =0 and carry =1
		if((in & 01) == carry)
			base[iter]=0;
		//else if any one of it is 1
		else {
			base[iter]=1;
			carry=0;
		}
		//if there is 1 in even position from right then set carry
		if(!(iter & 01) && base[iter]==1)
			carry=1;
		iter--;
		in >>=1;
	}
	//inisialize others with 0
	while(iter>=0)
		base[iter--]=0;
	return base;
}

void main(){
	int iter, in ,*base;
	base=(int *) malloc(sizeof(int)*32);
	//taking input
	printf("enter a number");
	scanf_s("%d",&in);

	base=func(in);
	//printing output
	for(iter=0;iter<32;iter++){
		printf("%d",base[iter]);
	}
	_getch();
}