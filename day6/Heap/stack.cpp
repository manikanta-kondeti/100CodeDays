#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct node
{
	int capacity ;
	int size;
	int *elements;
}Stack ;
Stack *Createstack(int maxVertices)
{
	Stack *S= (Stack *)malloc(sizeof(Stack));
	S->capacity=maxVertices;
	S->size=0;
	S->elements=(int *)malloc(sizeof(int)*maxVertices);
	return S;
}
void push(Stack *S,int element )
{
	if(S->size==S->capacity)
	{
		printf("Stack Full\n");
		exit(0);
	}
	else
	{
		S->size++;
		S->elements[S->size]=element;
		return;
	}
}
void pop(Stack *S)
{
	if(S->size==0)
	{
		printf("Stack Empty\n");
		exit(0);
	}
	else
	{
		S->size--;
		return;
	}
}

int top(Stack *S)
{
	if(S->size==0)
	{
		printf("Stack empty\n");
		exit(0);
	}
	return S->elements[S->size];
}

int main()
{
	Stack *S= Createstack(1000);
	push(S,1);
	push(S,4);
	printf("Top element %d\n",top(S));
	push(S,3);
	push(S,2);
	pop(S);
	printf("Top element %d\n",top(S));
	push(S,7);
	push(S,8);
	pop(S);
	push(S,9);
	printf("Top element %d\n",top(S));
	pop(S);
	pop(S);
	pop(S);
	pop(S);
	printf("Top element %d\n",top(S));
	return 0;
}
