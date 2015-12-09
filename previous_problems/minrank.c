/*
programer         :aiswarya
aim                       :print date in words
time complexity: O(n^2)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

void main(){
	int num,array[50],iter,len,fact,iter1,iter2,res,count;

	//taking input
	printf("enter number");
	scanf_s("%d",&num);

	//converting number into digits in reverse order
	for(iter=0;num>0;num=num/10,iter++){
		array[iter]=num%10;
	}
	len=iter;

	res=0;
	for(iter=(len-1);iter>=0;iter--){
		count=0;
		fact=1;
		//finding number of digits smaller than it and finding factorial
		for(iter1=(iter-1),iter2=1;iter1>=0;iter1--,iter2++){
			if(array[iter1]<array[iter]){
				count++;
			}
			fact=fact*iter2;
		}
		//finding result
		res=res+(count*fact);
	}
	printf("\nmin rank is: %d",res);
	_getch();
}