#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct node
{
	int num;
	struct node *next;
}Node;

void insert(Node *pointer,int data)
{
	printf("Successfully Inserted\n");
	Node *start=pointer;
	while(pointer->next!=start)
	{
		pointer=pointer->next;
	}
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->num=data;
	temp->next=start;
	pointer->next=temp;
	return;
}


void Delete(Node *pointer,int data)
{
	Node *start=pointer;
	while(pointer->next!=start && (pointer->next)->num!=data )
	{
		pointer=pointer->next;
	}
	if(pointer->next==start)
	{
		printf("Element Not found\n");
		return;
	}
	else
	{
		Node *temp;
		temp=(Node *)malloc(sizeof(Node));
		temp=pointer->next;
		pointer->next=temp->next;
		free(temp);
	}
	return;
}


void find(Node *pointer,int data)
{
	Node *start=pointer;
	while(pointer->next!=start && (pointer->next)->num!=data)
	{
		pointer=pointer->next;
	}
	if(pointer->next==start)
	{
		printf("Element Not found in the List \n");
		return;
	}
	else
	{
		printf("Element Found\n");
		return;
	}
}

void print(Node *start,Node *pointer)
{
	while(1)
	{
		if(pointer==start)
	{
		return;
	}
	printf("Now we are on the Node which contains the value %d\n",pointer->num);
	pointer=pointer->next;
	}
}

int main()
{
	Node *start,*temp;
	start=(Node *)malloc(sizeof(Node));
	temp=start;
	temp->next=start;
	int query;
	while(1)
	{
		scanf("%d",&query);
		if(query==1)
		{
			//insert
			int data;
			scanf("%d",&data);
			insert(start,data);
		}
		else if(query==2)
		{
			//delete
			int data;
			scanf("%d",&data);
			Delete(start,data);
		}
		else if(query==3)
		{
			//find
			int data;
			scanf("%d",&data);
			find(start,data);
		}
		else if(query==4)
		{
			//print
			print(start,start->next);
		}
	}
	return 0;
}
