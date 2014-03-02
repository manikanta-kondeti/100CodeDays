#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct stack
{
	int *elements;
	int capacity;
	int size;

}Stack;

Stack * CreateStack(int maxElements)
{
	Stack *S = (Stack *)malloc(sizeof(Stack));
	S->size=0;
	S->capacity=maxElements;
	S->elements=(int *)malloc(sizeof(int )*maxElements);
	return S;
}

void pop(Stack *S)
{
	if(S->size==0)
	{
		printf("Stack Empty\n");
	}
	else
	{
		S->size--;
	}
	return;
}

void push(Stack *S, int element)
{
	if(S->capacity==S->size)
	{
		printf("Stack Full\n");
	}
	else
	{	
		S->size++;
		S->elements[S->size]=element;
	}
	return;
}


int top(Stack *S)
{
	if(S->size==0)
	{
		printf("Stack Empty\n");
		exit(0);
	}
	return S->elements[S->size];
}


int main()
{
	Stack *S=CreateStack(100);
	push(S,9);
	push(S,8);
	push(S,7);
	push(S,6);
	printf("Top Element is %d\n",top(S));
	push(S,5);
	push(S,4);
	printf("Top Element is %d\n",top(S));
	pop(S);
	printf("Top Element is %d\n",top(S));
	pop(S);
	pop(S);
	printf("Top Element is %d\n",top(S));
	pop(S);
	pop(S);
	printf("Top Element is %d\n",top(S));
	return 0;
}
