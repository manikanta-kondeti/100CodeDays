#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<iostream>
#define maxVertices 100
using namespace std;

void dfs(int graph[][maxVertices],int visited[],int size[],int presentVertex)
{
	printf("Visiting Vertex %d\n",presentVertex);
	visited[presentVertex]=1;
	for(int i=0;i<size[presentVertex];i++)
	{
		if(visited[graph[presentVertex][i]]==0)
		{
			dfs(graph,visited,size,graph[presentVertex][i]);
		}
	}
}

int main()
{
	int graph[maxVertices][maxVertices],size[maxVertices]={0},visited[maxVertices]={0};
	int vertices,edges,vertex1,vertex2;
	scanf("%d%d",&vertices,&edges);
	for(int i=0;i<edges;i++)
	{
		scanf("%d%d",&vertex1,&vertex2);
		assert(vertex1 >=0 &&  vertex1<vertices);
		assert(vertex2 >=0 &&  vertex2<vertices);
		graph[vertex1][size[vertex1]++]=vertex2;
		graph[vertex2][size[vertex2]++]=vertex1;
	}
	for(int i=0;i<vertices;i++)
	{
		if(visited[i]==0)
		{
			dfs(graph,visited,size,i);
		}
	return 0;
	}
}
