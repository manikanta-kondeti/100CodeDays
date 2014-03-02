#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct node
{
	int num;
	struct node *next;
}Node;

void insert(Node *pointer,int num)
{
	while(pointer->next!=NULL)
	{
		pointer=pointer->next;
	}
	Node *temp;
	temp=(Node *)malloc(sizeof(Node));
	temp->num=num;
	temp->next=NULL;
	pointer->next = temp;
	printf("INserte\n");
	return;
}
void Delete(Node *pointer,int num)
{
	while(pointer->next !=NULL && (pointer->next)->num!=num)
	{
		pointer=pointer->next;
	}
	if(pointer->next==NULL)
	{
		printf("Element Not in the list\n");
		return;
	}
	else
	{
	Node *temp;
	temp=(Node *)malloc(sizeof(Node));
	pointer->next=temp;
	pointer->next=temp->next;
	free(temp);
	}
}
void find(Node *pointer,int num)
{
	while(pointer->next!=NULL && (pointer->next)->num!=num)
	{
		pointer=pointer->next;
	}
	if(pointer->next==NULL)
	{
		printf("Element Not in the list\n");
		return;
	}
	else
	{
		printf("Element Found\n");
		return;
	}
}
void print(Node *start)
{
	if(start==NULL)
	{
		return;
	}
	
	printf("Element in the Node is %d\n",start->num);
	print(start->next);

	return;
}

int main()
{
	Node *start,*temp;
	start=(Node *)malloc(sizeof(Node));
	temp=start;
	temp->next= NULL;
	int q;
	scanf("%d",&q);
	while(1)
	{
	scanf("%d",&q);
		if(q==1)
		{
			int num;
		 scanf("%d",&num);
			insert(start,num);
			//insert
		}
		else if(q==2)
		{
			int num;
		 scanf("%d",&num);
			Delete(start,num);
			//delete
		}
		else if(q==3)
		{
			int num;
		 scanf("%d",&num);
			//find
			find(start,num);
		}
		else if(q==4)
		{
			//print
			print(start);
		}
	}
	return 0;
}
