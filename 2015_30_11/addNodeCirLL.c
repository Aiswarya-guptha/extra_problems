/*
programer         :aiswarya
aim               :add node to a circular linked list
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

struct circularLL{
	int data;
	struct circularLL *link;
};
//create circular linked list
void makeCircularLL(int *values,int len,struct circularLL *head){
	head->link=head;
	head->data=NULL;
	while(0<len){
		struct circularLL *newNode=(struct circularLL*)malloc(sizeof(struct circularLL));
		newNode->data=values[len-1];
		newNode->link=head->link;
		head->link=newNode;
		len--;
	}

}
//print circular linked list from head
void print(struct circularLL *head){
	head=head->link;
	while(head->data!=NULL){
		printf_s("%d ",head->data);
		head=head->link;
	}
}
//insert insertValue value into head
void insert(int insertValue,struct circularLL *head){
	struct circularLL *newNode=(struct circularLL*)malloc(sizeof(struct circularLL));	
	while(head->link->data != NULL && head->link->data < insertValue)
		head=head->link;
	newNode->data=insertValue;
	newNode->link=head->link;
	head->link=newNode;
}

void main(){
	//inputs
	int values[]={2,3,4,5,9};
	int len=5;
	int insertValue;
	//create circular linked list
	struct circularLL *head=(struct circularLL*)malloc(sizeof(struct circularLL));
	makeCircularLL(values,len,head);
	print(head);
	//insert given value into linked list
	printf_s("\nenter a value to insert ");
	scanf_s("%d",&insertValue);
	insert(insertValue,head);
	printf_s("\nafter insert ");
	print(head);
	_getch();
}