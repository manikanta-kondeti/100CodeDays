#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int heap[1000000],heapsize=0;

void insert(int  element)
{
	heapsize++;
	heap[heapsize]=element;
	int now=heapsize;
	while(heap[now/2] > element)
	{
		heap[now]=heap[now/2];
		now /= 2;
	}
	heap[now]=element;
}


int Deletemin()
{
	int minelement,lastelement,now ,child;
	minelement=heap[1];
	lastelement=heap[heapsize];
	heapsize--;
	for(now=1;now*2<=heapsize;now=child)
	{
		child=now*2;
		if(child != heapsize && heap[child+1] < heap[child])
		{
			child++;
		}
		if(lastelement > heap[child])
		{
			heap[now]=heap[child];
		}
		else
		{
			break;
		}
	}
	heap[now]=lastelement;
	return minelement;
}

int main()
{
	int n;
	scanf("%d",&n);
	int element;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&element);
		insert(element);
	}
	for(int i=0;i<n;i++)
	{
		printf("min element %d --->  %d\n",i,Deletemin());
	}
	return 0;
}
