#include "uitil.h"
int findminedje(int * wightRel,bool * mstSet);
void printPrimsMST(int* edgeTo,int n,int graph[V][V]);
void prims(int graph[V][V])
{
	int edgeto[V];  //contian parent
	int wightRel[V];  //
	bool mstSet[V];
	int noedje=0;
	for(int i=0;i<V;i++)
	{
		wightRel[i]=INT_MAX;
		mstSet[i]= false;
		edgeto[i]=-1;
	}
	wightRel[0]=0;
	edgeto[0]=-1;
	for(noedje =0;noedje<V-1;noedje++)
	{
		int v_node =findminedje(wightRel,mstSet);
		mstSet[v_node]=true;
		for(int u_node=0;u_node<V;u_node++)
		{
			if(graph[v_node][u_node] && (mstSet[u_node]==false) && graph[v_node][u_node]<wightRel[u_node])
			{
				edgeto[u_node]=v_node;
				wightRel[u_node]=graph[v_node][u_node];
			}
		}
	}
	printPrimsMST(edgeto,V,graph);
}

int findminedje(int * wightRel,bool * mstSet)
{
	int min_no=INT_MAX;
	int min_indx=-1;
	for(int i=0;i<V;i++)
	{
		if((mstSet[i]==false) && (wightRel[i]<min_no))
		{
			min_no = wightRel[i];
			min_indx=i;
		}
	}
	return min_indx;
}

void printPrimsMST(int* edgeTo,int n,int graph[V][V])
{
	for(int i=1;i<n;i++)
		printf("%d <--  w=%d --> %d\n",edgeTo[i],graph[edgeTo[i]][i],i);
}