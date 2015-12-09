/*
programer         :aiswarya
aim                       :find length
time complexity: O(1)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4001)

int findn(int* in){
	int high=2,low=1;
	while(1==1){
		if(in[low-1]<in[high-1]){
			if(in[high-1]>in[high]){
				//if found the first 0 of array
				if(in[high]==0&&in[high-1]<in[high-2])	return (high-2);
				//if found the first decreasing value
				else			return (high-1);
			}
			//if there is still numbers in ascending order 
			low=high;
			high=high*2;
		}
		else if(in[high-1]==0)
			//if found 0 half it
			high=(low+high)/2;
		else
			//if found the first decreasing value
			return (low-1);
	}
}

void main(){
	//give input without using scanf
	int arr[]={1,4,5,6,7,8,9,10,11,67,77,88,99,106,108,111,222,333,444,555,666,777,888,1000,1111,2222,3333,4444,5555,6666,7777,8888,9999,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},len;

	len=findn(arr);
	
	printf("length: %d",len);

	_getch();
}

