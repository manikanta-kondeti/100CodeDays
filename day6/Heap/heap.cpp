#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

using namespace std;

int heap[1000000],heapsize;
void init()
{
	heapsize=0;
	heap[0]=-INT_MAX;
}


void insert(int e)
{
	heapsize++;
	heap[heapsize]=e;
	int now=heapsize;
	while(heap[now/2] > e)
	{
		heap[now]=heap[now/2];
		now /= 2;
	}
	heap[now]=e;
	return;
}

int Deletemin()
{
	int min,last,now,child;
	min = heap[1];
	last=heap[heapsize--];
	for(now=1;now*2<=heapsize;now=child)
	{
		child=now*2;
		if(child!=heapsize && heap[child+1]<heap[child])
		{
			child++;
		}
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
	return min;

}

int main()
{
	int n,e;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&e);
		insert(e);
	}
	for(int i=0;i<n;i++)
	{
		printf("Elements ->  %d\n",Deletemin());
	}
	return 0;
}
