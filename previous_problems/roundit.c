/*programmer   -aiswarya
 question      -round it
 compiler      -microsoft visualstudio 2010
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int funct(int n,int b){
	float mul;
	int mult;
	mul=(float)n/b;
	mult=(int)mul;
	//if N is exactly halfway between return large number
	if((mul-mult)>=0.5)
		mult++;
	return (mult*b);
}

void main(){
	int i,iter,n,b,*ans;
	//taking inputs
	scanf_s("%d",&iter);
	ans=(int *)malloc(iter-1);

	for(i=iter;i>0;i--){
		scanf_s("%d %d",&n,&b);
		ans[i-1]=funct(n,b);
	}
	//printing outputs
	for(i=iter;i>0;i--)
		printf_s("\n%d",ans[i-1]);

	_getch();
}