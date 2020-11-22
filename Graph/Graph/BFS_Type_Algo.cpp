#include "uitil.h"

void BFS_FAMILY_ALGO::BFS(int arr[][8],const int m,int visit[],int predecessor [],int d [],int sourceVertex)
{
	memset(visit,0,m*4);
	memset(d,0,m*4);
	memset(predecessor,0,m*4);
	std::queue<int> bfsQueue;
	bfsQueue.push(sourceVertex);
	while(!bfsQueue.empty())
	{
		int ver = bfsQueue.front();
		bfsQueue.pop();
		for(int i=0;i<m;i++)
		{
			if(ver == i)
				continue;

			if((arr[ver][i] == PRESENT )&&(visit[i] == WHITE) )
			{
				visit[i]=GRAY;
				predecessor[i]=ver;
				d[i]=d[ver]+1;
				bfsQueue.push(i);
			}
		}
		visit[ver] = BLACK;
	}
}
