#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#define maxElements 100
using namespace std;

typedef struct queue
{
	int capacity;
	int size;
	int front;
	int rear;
	int *elements;
}Queue;

Queue * CreateQueue( int x)
{
	Queue  *Q=(Queue *)malloc(sizeof(Queue));
	Q->capacity=x;
	Q->size=0;
	Q->front=0;
	Q->rear=-1;
	Q->elements= (int *)malloc(sizeof(int)*maxElements);
	return Q;
}

void Enqueue(Queue *Q,int element)
{
	if(Q->size==Q->capacity)
	{
		printf("Queue Full\n");
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
	}
	return;

}


void Dequeue(Queue *Q)
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
	return;
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


int main()
{
	Queue *Q=CreateQueue(100);
	Enqueue(Q,1);	
	Enqueue(Q,2);	
	Enqueue(Q,3);	
	Enqueue(Q,4);	
	Enqueue(Q,5);	
	Enqueue(Q,6);
	Dequeue(Q);	
	printf("front element %d\n",front(Q));
	Enqueue(Q,7);
	Enqueue(Q,8);	
	Dequeue(Q);	
	Dequeue(Q);	
	Dequeue(Q);	
	Dequeue(Q);	
	Dequeue(Q);	
	Dequeue(Q);	
	printf("front element %d\n",front(Q));
	Enqueue(Q,6);
	Dequeue(Q);	
	printf("front element %d\n",front(Q));
	Dequeue(Q);	
	return 0;
}


