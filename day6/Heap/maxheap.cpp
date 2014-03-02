#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int heap[1000000],heapsize;

void init()
{
	heapsize=0;
	heap[0]=1000000;
}
void insert(int element)
{
	printf("IN insert \n");
	heapsize++;
	heap[heapsize]=element;
	int now=heapsize;
	while(heap[now/2] < element)
	{
		heap[now]=heap[now/2];
		now /= 2;
	}
	heap[now]=element;
	printf("inserted \n");
	return;
}


int Deletemax()
{
	int maxelement,lastelement,now,child;
	maxelement=heap[1];
	lastelement=heap[heapsize];
	heapsize--;
	for(now=1;now*2<heapsize;now=child)
	{
		child=now*2;
		if(child != heapsize && heap[child] < heap[child+1])
		{
			child++;
		}
		if(lastelement < heap[child])
		{
			heap[now]=heap[child];
		}
		else
		{
			break;
		}
	}
		heap[now]=lastelement;
	return maxelement;
}
int main()
{
	init();
	int n,element;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&element);
		insert(element);
	}
	for(int i=0;i<n;i++)
	{
		printf("max elements -->  %d\n",Deletemax());
	}
	return 0;
}
