// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "uitil.h"
extern void prims(int graph[V][V]);
extern int FindDiameter();
extern void FloydWarshall(int graph[V][V]);
int graph_main(int argc, _TCHAR* argv[])
{

	 /* int graph[6][6]={{0,95,133,271,0,0},
					 {95,0,0,290,409,0},
					 {133,0,0,0,0,445},
					 {271,290,0,0,112,291},
					 {0,409,0,112,0,275},
					 {0,0,445,291,275,0}};*/

/*int i;
cout<<sizeof(long long);
				    //0 1 2 3 4 5 6 7
	int graph[8][8]={{0,1,0,0,0,1,0,0}, //0
					 {1,0,0,0,1,0,0,0}, //1
	                 {0,0,0,1,0,1,1,0},	//2
	                 {0,0,1,0,0,0,1,1}, //3
	                 {0,1,0,0,0,0,0,0}, //4
	                 {1,0,1,0,0,0,1,0}, //5
					 {0,0,1,0,0,1,0,1}, //6
					 {0,0,0,1,0,0,1,0}};//7
	int visit[8];
	int dis[8];
	int pre[8];

	BFS_FAMILY_ALGO::BFS(graph,8,visit,pre,dis,0);*/
	/*int graph[V][V] = {{0, 2, 0, 6, 0},
						{2, 0, 3, 8, 5},
						{0, 3, 0, 0, 7},
						{6, 8, 0, 0, 9},
						{0, 5, 7, 9, 0},
					  };
	prims(graph);*/
	int graph[V][V] = { {0,   5,  0, 10},
						{0, 0,   3, 0},
						{0, 0, 0,  1},
						{0, 0, 0, 0}
	};

	
	FloydWarshall(graph);
	FindDiameter();

	return 0;
}

