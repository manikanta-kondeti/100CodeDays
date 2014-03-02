#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct node
{
	int num;
	struct node *next;
	struct node *prev;
}Node;
	
void insert(Node *pointer,int data)
{
	printf("Inserted\n");
	while(pointer->next!=NULL)
	{
		pointer=pointer->next;
	}
	Node *temp;
	temp=(Node *)malloc(sizeof(Node));
	temp->num=data;
	temp->prev=pointer;
	pointer->next=temp;
	temp->next=NULL;
	return;
	
}

void Delete(Node *pointer,int data)
{
	while(pointer->next!=NULL && (pointer->next)->num!=data)
	{
		pointer=pointer->next;
	}
	if(pointer->next==NULL)
	{
		printf("Element not in the List\n");
		return;
	}
	else 
	{
		Node *temp;
		temp=(Node *)malloc(sizeof(Node));
		temp=pointer->next;
		pointer->next=temp->next;
		temp->prev=pointer;
		free(temp);
		printf("Successfully deleted\n");
		return;
	}
}


void find(Node *pointer,int data)
{
	while(pointer->next!=NULL && (pointer->next)->num!=data)
	{
		pointer=pointer->next;
	}
	if(pointer->next==NULL)
	{
		printf("Element Not found\n");
		return;
	}
	else
	{
		printf("Element Found\n");
		return;
	}
}

void print(Node *pointer)
{
	printf("Printed\n");
	while(1)
	{
	pointer=pointer->next;
	if(pointer==NULL)
	{
		return;
	}
	printf("Value in the Node %d\n",pointer->num);
	}
}
int main()
{
	Node *start,*temp;
	start=(Node *)malloc(sizeof(Node));
	temp=start;
	temp->next=NULL;
	temp->prev=NULL;
	int query;
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Find\n");
	printf("4.Print\n");
	while(1)
	{
		scanf("%d",&query);
		if(query==1)
		{
			//Insert
			int data;
			scanf("%d",&data);
			insert(start,data);
		}
		else if(query==2)
		{
			//Delete
			int data;
			scanf("%d",&data);
			Delete(start,data);
		}
		else if(query==3)
		{
			//Find
			int data;
			scanf("%d",&data);
			find(start,data);
		}
		else if(query==4)
		{
			//Print
			print(start);
		}
	
	}
	return 0;
}
