/*
programer         :aiswarya
aim                       :adder
time complexity: O(n)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)


void func(char *str0,int len0,char *str1,int len1,char *res,int hlen,int llen){
	int num,carry=0,iter;
	//addes digits from right end
	for(iter=1;iter<=llen;iter++){
		num=carry+(str0[len0-iter]-'0')+(str1[len1-iter]-'0');
		res[hlen-iter+1]=((num%10)+'0');
		carry=num/10;
	}
	//addes the leftover digits
	for(;iter<=len0;iter++){
		num=carry+(str0[len0-iter]-'0');
		res[hlen-iter+1]=((num%10)+'0');
		carry=num/10;
	}
	for(;iter<=len1;iter++){
		num=carry+(str1[len1-iter]-'0');
		res[hlen-iter+1]=((num%10)+'0');
		carry=num/10;
	}
	//initializes first pplace with carry
	res[0]=carry;
}
void main(){
	int len0,len1,iter,hlen,llen;
	char *str0,*str1,*res;
	printf("enter first string length");
	scanf_s("%d",&len0);
	fflush(stdin);
	str0=(char *) malloc(len0);
	printf("enter first string");
	gets(str0);

	printf("enter second string length");
	scanf_s("%d",&len1);
	fflush(stdin);
	str1=(char *) malloc(len1);
	printf("enter second string");
	gets(str1);
	//finds lagest length
	if(len0<len1){
			llen=len0;
			hlen=len1;
		}
		else{
			hlen=len0;
			llen=len1;
		}
	res=(char *) malloc(hlen);
	
	func(str0,len0,str1,len1,res,hlen,llen);
	
	for(iter=0;iter<=hlen;iter++)
		printf("%c",res[iter]);
	_getch();
}