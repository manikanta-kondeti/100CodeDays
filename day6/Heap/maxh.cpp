#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

using namespace std;

int heap[1000000],heapsize;
void init()
{
	heapsize=0;
	heap[0]=1000000;
}


void insert(int e)
{
	heapsize++;
	printf("Inserted\n");
	heap[heapsize]=e;
	int now=heapsize;
	while(heap[now/2]<e)
	{
		printf("hii %d\n",e);
		heap[now]=heap[now/2];
		now /= 2;
	}
	heap[now]=e;
	printf("Inserted\n");
	return;
}
int Deletemax()
{
	int max,last,now,child;
	max=heap[1];
	last=heap[heapsize--];
	for(now=1;now*2<=heapsize;now=child)
	{
		child=now*2;
		if(child!=heapsize && heap[child] < heap[child+1])
		{
			child++;
		}
		if(last < heap[child])
		{
			heap[now]=heap[child];
		}
		else
		{
			break;
		}
	}
		heap[now]=last;
		return max;
}

int main()
{
	int n,e;
	scanf("%d",&n);
	init();
	for(int i=0;i<n;i++)
	{
		scanf("%d",&e);
		insert(e);
	}
	for(int i=0;i<n;i++)
	{
		printf("elements %d\n",Deletemax());
	}
	return 0;
}
