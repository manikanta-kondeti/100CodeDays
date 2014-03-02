#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
using namespace std;

#define maxVertices 500


typedef struct queue
{
	int capacity;
	int size;
	int front;
	int rear;
	int *elements;
}Queue;

Queue * Createqueue(int k)
{
	Queue *Q=(Queue *)malloc(sizeof(Queue ));
	Q->size=0;
	Q->capacity=k;
	Q->front=0;
	Q->rear=-1;
	Q->elements=(int *)malloc(sizeof(int)*k);
	return Q;
}

void Enqueue(Queue *Q,int num)
{
	if(Q->capacity==Q->size)
	{
		printf("Queue Full\n");
		exit(0);
	}
	else
	{
		Q->rear++;
		Q->size++;
		if(Q->rear==Q->capacity)
		{
			Q->rear=0;
		}
		Q->elements[Q->rear]=num;
		return;
	}
}

void Dequeue(Queue *Q)
{
	if(Q->size==0)
	{
		printf("Queue Empty\n");
		exit(0);
	}
	else
	{
		Q->front++;
		Q->size--;
		if(Q->front == Q->capacity)
		{
			Q->front =0;
		}
		return;
	}

}


int front(Queue *Q)
{
	if(Q->size==0)
	{
		printf("Queue Empty\n");
		exit(0);
	}
	return Q->elements[Q->front];
}

void bfs(int graph[][maxVertices],int visited[],int size[],int pv)
{
	visited[pv]=1;
	int level=0;
	Queue *Q=Createqueue(maxVertices);
	Enqueue(Q,pv);
	while(Q->size!=0)
	{
		pv=front(Q);
		printf("NOw we are visiting Vertex %d\n",pv);
		Dequeue(Q);

		for(int i=0;i<size[pv];i++)
		{
			if(visited[graph[pv][i]]==0)
			{
				Enqueue(Q,graph[pv][i]);
				visited[graph[pv][i]]=1;
			}
		}
	}
	return;
}

int main()
{
	int graph[maxVertices][maxVertices],visited[maxVertices]={0},size[maxVertices]={0},presentVertex,vertices,edges,vertex1,vertex2;
	scanf("%d%d",&vertices,&edges);
	for(int i=0;i<edges;i++)
	{
		scanf("%d%d",&vertex1,&vertex2);
		assert(vertex1 >=0 && vertex1 < vertices);
		assert(vertex2 >=0 && vertex2 < vertices);
		graph[vertex1][size[vertex1]++]=vertex2;
	}
	for(int i=0;i<vertices;i++)
	{
		if(visited[i]==0)
		{
			bfs(graph,visited,size,i);
		}
	}
	return 0;
}
