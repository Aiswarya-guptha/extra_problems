/*
programer			:aiswarya
aim                 :convert base2 to base8
time complexity		: O(n)
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#pragma warning(disable:4001)

void convert(char* base2,char *base8, int len2,int len8){
	
	for(len2=(len2-1),len8=(len8-1);len2>=0;len2--,len8--){
		base8[len8]='0';
		if(base2[len2]=='1')	base8[len8]=base8[len8]+1;
		if(len2>0&&base2[--len2]=='1' )	base8[len8]=base8[len8]+2;
		if(len2>0&&base2[--len2]=='1')	base8[len8]=base8[len8]+4;
	}
}
void main(){
	char *base2,*base8;
	int len2,len8,iter;
	//takin input length
	printf("enter len of string");
	scanf_s("%d",&len2);
	fflush(stdout);
	gets(&base2);
	base2=(char *) malloc (len2);
	
	//taking input string
	printf("enter string");
	gets(base2);
	fflush(stdout);
	     
	len8=((len2-1)/3)+1;
	base8=(char *) malloc (len8);
	convert(base2,base8,len2,len8);

	for(iter=0;iter<len8;iter++)
		printf("%c",base8[iter]);
	_getch();
}