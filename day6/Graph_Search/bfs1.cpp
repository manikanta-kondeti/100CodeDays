#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define maxvertices 100
using namespace std;

typedef struct queue
{
	int capacity;
	int size;
	int front;
	int rear;
	int *elements;
}Queue;

Queue * Createqueue(int max)
{
	Queue *Q=(Queue *)malloc(sizeof(Queue));
	Q->size=0;
	Q->front=0;
	Q->rear=-1;
	Q->elements=(int *)malloc(sizeof(int)*max);
	Q->capacity=max;
	return Q;
}

void Enqueue(Queue *Q,int element)
{
	if(Q->size==Q->capacity)
	{
		printf("Queue Full\n");
		exit(0);
	}
	else
	{
		Q->size++;
		Q->rear++;
		if(Q->rear==Q->capacity)
		{
			Q->rear=0;
		}
		Q->elements[Q->rear]=element;
		return;
	}
}

int front(Queue *Q)
{
	if(Q->size==0)
	{
		printf("Queue Full\n");
		exit(0);
	}
	return Q->elements[Q->front];
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
		if(Q->front==Q->capacity)
		{
			Q->front = 0;
		}
		return;
	}
}


void bfs(int graph[][100],int visited[],int size[],int pv)
{
	visited[pv]=1;
	Queue *Q=Createqueue(1000);
	Enqueue(Q,pv);
	while(Q->size!=0)
	{
		pv=front(Q);
		printf("Now we are visiting %d\n",pv);
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
	int graph[maxvertices][maxvertices],visited[maxvertices]={0},size[maxvertices]={0};
	int vertices,edges,vertex1,vertex2;
	scanf("%d%d",&vertices,&edges);
	for(int i=0;i<edges;i++)
	{
		scanf("%d%d",&vertex1,&vertex2);
		assert(vertex1 >=0 && vertex1<vertices);
		assert(vertex2 >=0 && vertex2<vertices);
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
