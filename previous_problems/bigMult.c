#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

void right_shift(int *arr){
	//shifts the whole array to one bit right

	int becarry=0,prcarry=0,iter,highest_bitvalue=1073741824; //highest bit is the msb bit (here one bit is used for sigh so 2^30)

	for(iter=0;iter<15;iter++){
		if(arr[iter] & 01){
			//if last bit is 1 then carry it to next
			prcarry=1;
		}
		//shift array by one bit right
		arr[iter]=arr[iter]>>1;

		if(becarry==1){
			//if thers is a carry before add highest bitto this
			arr[iter]=arr[iter]+highest_bitvalue;
			becarry=0;
		}
		if(prcarry==1){
			becarry=1;
			prcarry=0;
		}
	}
}


void bigmult(int *lsb,int *msb,int *res){
	int carry[15],dup[15],iter;
	
	while((msb[0]+msb[1]+msb[2]+msb[3]+msb[4])!=0){
		if(msb[4] & 01){
			for(iter=0;iter<15;iter++)
				dup[iter]=lsb[iter];
			while((dup[0]+dup[1]+dup[2]+dup[3]+dup[4])!=0){
				for(iter=0;iter<15;iter++){
					carry[iter]=res[iter] & dup[iter];
					res[iter] =dup[iter] ^ res[iter];
				}
				right_shift(carry);
				for(iter=0;iter<15;iter++)
					dup[iter]=carry[iter];
			}
		}
		right_shift(msb);
		right_shift(lsb);
	}

}
void main(){
	
	int iter,lsb[15],msb[15],res[15];
	
	//the input value  to lsb is, the converted decimal value of every 32 bits of the number in the reverse order (i.e lsb is in the left side)

	//maximum of 10 decimals (i.e 320 bits)
	printf("enter 10 values lsb");
	for(iter=0;iter<10;iter++)
		scanf_s("%d",(lsb+iter));

	for(;iter<15;iter++)
		lsb[iter]=0;

	//the input value  to msb is, the converted decimal value of every 32 bits of the number  (i.e msb is in the left side)
	//maximum of 5 decimals
	printf("enter 5 values msb");
	for(iter=0;iter<5;iter++)

		scanf_s("%d",(msb+iter));

	for(;iter<15;iter++)
		msb[iter]=0;

	for(iter=0;iter<15;iter++)
		res[iter]=0;

	bigmult(lsb,msb,res);

	//the result printed is in decimal form of reverse order of the binary value
	printf("res with lsb bit on left side :");
	
	for(iter=0;iter<15;iter++)
		printf("%d ",res[iter]);

	_getch();
}