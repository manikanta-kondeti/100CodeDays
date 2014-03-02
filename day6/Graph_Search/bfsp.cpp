#include<stdio.h>
#include<stdlib.h>

#define max_vertices 1000
using namespace std;

//queue
struct node
{

	int capacity;
	int size;
	int *elements;
	int front;
	int rear;

}Queue;

//queue create
Queue *Createqueue(int max)
{
	Queue *Q;
	Q->capacity=max;
	Q->size=0;
	Q->front=0;
	Q->rear=-1;
	Q->elements=(Queue *)malloc(sizeof(int)*max);
	return Q;
}

void enqueue(int num,Queue *Q)
{
	if(Q->size==Q->capacity)
	{
		printf("Max Size\n");
		exit(0);
	}
	else
	{
		Q->rear++;
		if(Q->rear==Q->capacity)
		{
			Q->rear=0;
		}
		Q->size++;
		Q->elements[Q->rear]=num;
		return;
	}
}


void dequeue(Queue *Q)
{
	if(Q->size==0)
	{
		printf("Queue Empty\n");
	}
	else
	{
		Q->front++;
		Q->size--;
		if(Q->front==Q->capacity)
		{
			Q->front=0;
		}
	}

}

int front(Queue *Q)
{
	if(Q->size==0)
	{
		printf("Queue Empty\n");
	}
	else
	{
		return Q->elements[Q->front];
	}
}


int main()
{
	int graph[max_vertices][max_vertices], vertices[max_vertices]={0},size[max_vertices]={0};
	int vertices, vetex1,vertex2,edges;
	scanf("%d%d",&vertices,&edges);	
	for(int i=0;i<edges;i++)
	{
		scanf("%d%d",&vertex1,&vertex2);
		graph[vertex1][size[vertex1++]]=vertex2;
	}
	for(int i=;i<edges;i++)
	{
		if(vistied[i]==0)
		{
			bfs(graph,,size[i],i);
		}
	}
	return 0;
}
