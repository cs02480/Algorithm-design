#include <iostream>
using namespace std;
enum COLORE{WHITE=0,GRAY,BLACK,INPATH};
#define N 4
COLORE visit[N][N]={WHITE};
int countpath=0;
int Maze[N][N]={
					{1, 1, 0, 0},
					{1, 1, 0, 1},
					{0, 1, 0, 0},
					{1, 1, 1, 1}
				};
bool ValidaqteIndex(int i,int j)
{
		if((i>=0 && i<N)&& (j>=0 && j<N) && Maze[i][j] ==1 && visit[i][j] == WHITE)
			return true;
		return false;
}
bool Isinpath(int i,int j)
{
	if((i>=0 && i<N)&& (j>=0 && j<N) && Maze[i][j] ==1 && visit[i][j] == INPATH)
		return true;
	return false;
}

void printSolution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", visit[i][j]);
		printf("\n");
	}
}
bool findpath(int i,int j)
{
	bool ispath = false;
	visit[i][j]=GRAY;
	if(i == N-1 && j== N-1)
	{
			countpath++;
			return true;
	}
	if(ValidaqteIndex(i-1,j))
	{
		if(findpath(i-1,j))
		{
			visit[i-1][j]=INPATH;
			ispath = true;
		}

	}
	else if (Isinpath(i-1,j))
	{
		countpath++;
		ispath = true;
	}
	if(ValidaqteIndex(i+1,j))
	{
		if(findpath(i+1,j))
		{
			visit[i+1][j]=INPATH;
			ispath = true;
		}

	}
	else if (Isinpath(i+1,j))
	{
		countpath++;
		ispath = true;
	}
	if(ValidaqteIndex(i,j-1))
	{
		if(findpath(i,j-1))
		{
			visit[i][j-1]=INPATH;
			ispath = true;
		}

	}
	else if (Isinpath(i,j-1))
	{
		countpath++;
		ispath = true;
	}


	if(ValidaqteIndex(i,j+1))
	{
		if(findpath(i,j+1))
		{
			visit[i][j+1]=INPATH;
			ispath = true;
		}

	}
	else if (Isinpath(i,j+1))
	{
		countpath++;
		ispath = true;
	}
	//if(!ispath)
		visit[i][j]=WHITE;
	return ispath;
}

void main123()
{
	findpath(0,0);
	printSolution();
}