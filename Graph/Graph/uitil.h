#ifndef UITIL_H
#define UITIL_H


#include <iostream>
using namespace std;
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

class BFS_FAMILY_ALGO
{
	enum COLORE{WHITE=0,GRAY,BLACK};
	enum EDGE{NOTPRESENT=0,PRESENT};
public:
	void static BFS(int arr[][8],int m,int visit[],int predecessor [],int d [],int sourceVertex);
};
#define V 4
#endif //UITIL_H