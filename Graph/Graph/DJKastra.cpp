#include "uitil.h"

int visit[25];
int shortestPath[25];
#define VISIT 1
//int V=6;
int MinDist()
{
	int min=INT_MAX,min_indx=0;
	for(int i=0;i<V;i++)
	{
		if(visit[i]==0 && shortestPath[i]<=min)
		{
			min=shortestPath[i];
			min_indx=i;
		}
	}
	return min_indx;
}
void  DJKastra(int  graph[][6],int source)
{
	for (int i=0;i<25;i++)
	{
		visit[i]=0;
		shortestPath[i]=INT_MAX;
	}
	//visit[source]=VISIT;
	shortestPath[source]=0;
	for(int count=0;count<V-1;count++)
	{
		int u =MinDist();
		visit[u]=VISIT;
		for(int v=0;v<V;v++)
		{
			if(!visit[v] && graph[u][v]!=0 && shortestPath[u]!=INT_MAX && (shortestPath[u]+graph[u][v])<shortestPath[v])
			{
				shortestPath[v]=shortestPath[u]+graph[u][v];
			}
		}

	}
}