/*
programer         :aiswarya
aim               :median of linked list using slow poiter and fast pointer
time complexity	  : O(n)
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

struct linkedList{
	int value;
	int link;
};

void insertIntoLinkedlist(int input, struct linkedList *head){
	struct linkedList *insert;
	for (insert = head; insert->link != NULL; insert = insert->link){}
	//insert at last node
	struct linkedList *newNode = (struct linkedList *)malloc(sizeof(struct linkedList *));
	newNode->value = input;
	newNode->link = NULL;
	insert->link = newNode;
}

float findMedian(struct linkedList *head){
	struct linkedList *end,*median, *dup;
	for (median = head, end = head, dup = end->link; end->link != 0 && median->link != 0 && dup->link != 0; ){
		//end moving two nodes
		end = (dup)->link;
		//median moving one node
		median = median->link;
		dup = end->link;
	}
	if (end->link == NULL){
		//when two numbers in between
		int a= median->value;
		median = median->link;
		return  ((median->value) + a) /2.0;
	}
	//for odd length
	median = median->link;
	return median->value;
}

void main(){
	struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList *));
	head->link = NULL;
	int input=0,len,iter;
	//taking inputs
	printf_s("enter length of linked list");
	scanf_s("%d", &len);
	if (len > 0){
		printf_s("enter elements of linked list");
		for (iter = 0; iter < len; iter++){
			scanf_s("%d", &input);
			insertIntoLinkedlist(input, head);
		}
		//finding median
		printf("%f", findMedian(head));
	}
	_getch();
}