#include "uitil.h"
int dist[V][V];
int path[V][V];
void FloydWarshall(int graph[V][V])
{
	
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
		{
			if(graph[i][j])
				dist[i][j]=graph[i][j];
			else
				dist[i][j]= ((i == j)?0:INT_MAX);
				path[i][j]=graph[i][j]?j:0;
		}

		for(int k=0;k<V;k++)
			for (int s=0;s<V;s++)
			{
				if(path[s][k])
				{
					for(int u=0;u<V;u++)
					{	
						if(	dist[s][k] != INT_MAX && dist[k][u] != INT_MAX && dist[s][u]> dist[s][k]+dist[k][u])
						{
							dist[s][u]= dist[s][k]+dist[k][u];
							path[s][u]=k;
						}
					}
				}
			}

}
int FindDiameter()
{
	int maxs=0,maxu=0;
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
		{
			if(dist[i][j] !=INT_MAX)
			{
				if(dist[i][j]>dist[maxs][maxu])
				{
					maxs=i;
					maxu=j;
				}
			}
		}

		cout<<"end::"<<endl;
		int start = maxs;
		int endv =maxu;
		int i=0;
		while(endv != path[start][endv])
		{
			
			if(path[start][endv])
			{
				cout<<endv<<"<-";
				endv =path[start][endv];
			}
			 //if(endv == path[start][endv]))
		}
		cout<<endv<<"<-"<<start<<endl;
return dist[maxs][maxu];
}