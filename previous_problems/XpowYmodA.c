/*
programmer		:aiswarya
aim				:find (x^y)%a;
time complexity :O(n)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

int func(int x,int y,int a){
	int iter,iter1,j,bin[50],arr[50],mo[50],mul,mulb,res,temp;

	//finding binary value of y
	iter=0;
	while(y>0){
		bin[iter]=y%2;
		y=y/2;
		iter++;
	}
	bin[iter]=99;

	//converting 1 value of binary into decimal
	temp=1;
	for(iter=0,iter1=0;bin[iter]!=99;iter++,temp=temp*2){
		if(bin[iter]==1){		
			arr[iter1]=temp;
			iter1++;
		}
	}
	arr[iter1]=99;

	//calculating the modulus values till max of arr[] value
	mo[1]=x%a;
	mulb=1;
	mul=2;
	for(iter=1;bin[iter]!=99;iter++,mul=mul*2,mulb=mulb*2){
		mo[mul]=(mo[mulb]*mo[mulb])%a;
	}

	//calculating final result by formula  - ((x %a)*(x%a))%a
	if(arr[0]!=99&&arr[1]!=99){
		res=(mo[arr[0]]*mo[arr[1]])%a;;
		for(iter=2;arr[iter]!=99;iter++)
			       res=(res*mo[arr[iter]])%a;
		//printf("\n %d ",res);
	}
	if(arr[0]!=99)		return mo[arr[0]];
	else	return -1;
}

void main(){

	int x,y,a,res;

	//taking inputs
	printf("enter x,y,a");	
	scanf_s("%d %d %d",&x,&y,&a);

	res = func(x,y,a);

	if(res != -1)		printf("modulo: %d",res);
	_getch();
}
