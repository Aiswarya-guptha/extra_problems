/*
programer         :aiswarya
aim               :merge two sorted array
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#pragma warning(disable:4001)

struct linkedList{
	int data;
	struct linkedList* link;
};
//crete linked list of arr at head
void makeLinkedList(int *arr,int len,struct linkedList* head){
	int iter;
	head->link=NULL;
	for(iter=0;iter<len;iter++){
		struct linkedList* node=(struct linkedList*)malloc(sizeof(struct linkedList));
		node->data=arr[iter];
		node->link=NULL;
		head->link=node;
		head=head->link;
	}
}
//print the linked list at head
void print(struct linkedList* head){
	while(head->link!=NULL){
		head=head->link;
		printf_s("%d ",head->data);
	}
}
//merge two linked list at head1 and head2 into head1
void merge(struct linkedList* head1,struct linkedList*head2){
	while(head1->link!=NULL && head2->link!=NULL){
		if(head1->link->data > head2->link->data){
			struct linkedList* insert=head2->link;
			head2->link=head2->link->link;
			insert->link=head1->link;
			head1->link=insert;
		}
		head1=head1->link;
	}
	if(head1->link==NULL)
		head1->link=head2->link;
}

void main(){
	//inputs
	int arr1[]={5,9,10,11};
	int arr2[]={2,4,12};
	int len1=4,len2=3;
	//create linked lists
	struct linkedList* head1=(struct linkedList*)malloc(sizeof(struct linkedList));
	struct linkedList* head2=(struct linkedList*)malloc(sizeof(struct linkedList));
	makeLinkedList(arr1,len1,head1);
	makeLinkedList(arr2,len2,head2);
	printf_s("first array ");
	print(head1);
	printf_s("\nsecond array ");
	print(head2);
	//merge them at head1
	merge(head1,head2);
	printf_s("\nmerged array ");
	print(head1);

	_getch();
}