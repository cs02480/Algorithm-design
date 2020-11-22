// PriortiQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <memory>
class MinHeap
{
private:
	int  tree[100];
	int Max_size;
	int used;
public:
	MinHeap(int max=100)
	{
		Max_size = max;
		//tree = new int[max];
		used=0;
		tree[used]=INT_MIN;
	}
	~MinHeap()
	{
		delete []tree;
	}
private:
	void Percolate_down(int i);
	void Percolate_up(int i);
public:
	void Insert(int i);
	int RemoveMin();
	//void Decrease_key();
	//void Increase_key();
	void Build_heap(int * arr,int size);
	/*{
		memcpy(&tree[1],arr,size);
		used = size+1;
	}*/
};
void MinHeap::Build_heap(int * arr,int size)
{
	memcpy(&tree[1],arr,size*4);
	used = size;
	for(int i=used/2  ;i>0;i--)
		Percolate_down(i);

	for(int i=1;i<used;i++)
		cout<<tree[i]<<endl;
}
int MinHeap::RemoveMin()
{

	int item = tree[1];
	 tree[1] = tree[used];
	used--;
	Percolate_down(1);
	return item;
}
void MinHeap::Insert(int i)
{
	if(used == Max_size)
	{
		cout<<"HeapFull"<<endl;
		return;
	}
	used++;
	tree[used]=i;
	Percolate_up(used);
}
void MinHeap::Percolate_up(int i)
{
	int prnt =i;
	int item = tree[i];
	while(tree[prnt/2]>item)
	{
		tree[prnt]=tree[prnt/2];	
		prnt=prnt/2;
	}
	tree[prnt] = item;
}
void MinHeap::Percolate_down(int i)
{
	int item=tree[i];
	int j = i;
	int child ;
	while(j<=used)
	{
		child=j*2;
		if(child > used)
			break;
		if( child != used  && tree[child] > tree[child +1])
			child++;
		
		if(item > tree[child])
		{
			tree[j]=tree[child];
			j=child;
		}
		else
		{
			break;
		}
	}
	tree[j]=item;


}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[]={150,80,40,30,10,70,110};

	MinHeap temp;
	temp.Build_heap(a,sizeof(a)/sizeof(int));
	
	return 0;
}

