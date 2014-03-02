#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct queue
{
	int capacity;
	int size;
	int front;
	int rear;
	int * elements;
}Queue;


Queue * CreateQueue(int maxElements)
{
	Queue *Q;
	Q=(Queue *)malloc(sizeof(Queue));
	Q->capacity=maxElements;
	//Capacity will store the maximum elements it can store 
	Q->size=0;
	//size of the present queue.
	Q->front=0;
	Q->rear=-1;
	Q->elements=(int *)malloc(sizeof(int)*maxElements);
	return Q;
	//It returns a pointer to the Queue which created recently using this function.
}


void Enqueue(Queue *Q, int element)
{
	if(Q->size==Q->capacity)
	{
		printf("Queue is full, cannot insert an element\n");
	}
	else
	{
		Q->size+=1;
		Q->rear+=1;
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
		printf("Queue is empty\n");
		return;
	}
	else
	{
		Q->front+=1;
		Q->size-=1;
		if(Q->front==Q->capacity)
		{
			Q->front=0;
		}
		return;
	}
}

int front(Queue *Q)
{
	if(Q->size==0)
	{
		printf("Queue is empty\n");
		exit(0);
	}
	else
	{
		return Q->elements[Q->front];
	}
}



int main()
{

	Queue *Q=CreateQueue(10);
	printf("Front element of the queue %d\n",front(Q));
	Enqueue(Q,1);
	Enqueue(Q,2);
	printf("Front element of the queue %d\n",front(Q));
	Enqueue(Q,3);
	Enqueue(Q,4);
	Enqueue(Q,5);
	Enqueue(Q,6);
	Dequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	printf("Front element of the queue %d\n",front(Q));
	Dequeue(Q);
	printf("Front element of the queue %d\n",front(Q));
	Enqueue(Q,1);
	Dequeue(Q);
	Dequeue(Q);
	printf("Front element of the queue %d\n",front(Q));
	return 0;
}






