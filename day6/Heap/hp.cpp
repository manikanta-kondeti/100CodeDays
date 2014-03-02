#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<limits.h>
using namespace std;

int heap[1000000],heapsize;
void init()
{
	heapsize=0;
	heap[0]=-INT_MAX;
}

void insert(int element)
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
	printf("Inserted\n");
	return;
}

int Deletemin()
{
	int min,last,now,child;
	min=heap[1];
	last=heap[heapsize--];
	for(now=1;now*2<=heapsize;now=child)
	{
		child=now*2;
	printf("Deleted\n");
		if(child != heapsize)
		{
				if(heap[child] > heap[child+1])
		{
			child++;
		}
		}
		printf("hii\n");
			if(last > heap[child])
		{
			heap[now]=heap[child];
		}
		else
		{
			break;
		}
	}
	heap[now]=last;
	printf("Deleted\n");
	return min;
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
		printf("Elements %d\n",Deletemin());
	}
	return 0;
}

