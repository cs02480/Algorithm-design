#include <iostream>
#include <cstdlib>
using namespace std;

struct _talk 
{
	int start;
	int end;
	int w;
};
typedef struct _talk talk;
int compare_talk(const void * a ,const void * b)
{
	talk * f=(talk *)a;
	talk * s=(talk *)b;
	if(f->end<s->end) return -1;
	if(f->end == s->end) return 0;
	if(f->end > s->end) return 1;
}
int find_max_schedule(talk ptr[],int talk_count)
{
	int * P=new int[talk_count+1];
	int * T=new int[talk_count+1];
	qsort(ptr+1,talk_count,sizeof(talk),compare_talk);
	memset(P,0,talk_count+1);
	for(int j=2;j<=talk_count;j++)
	{
		for(int i=j-1;i>0;i--)
		{
			if(ptr[i].end <= ptr[j].start)
			{
				P[j]=i;
				break;
			}
		}
	}
	//T[1]=ptr[1].w;
	for(int i=1;i<=talk_count;i++)
	{
		T[i]=max(ptr[i].w+T[P[i]],T[i-1]);
	}
return T[talk_count];
}
void main()
{
	int num=1;
	int N=9;
	cin>>N;
	bool flag[10001];
	memset(flag,false,10001);
	for(int i=2;i<=N;i++)
	{
		num+=1;
		memset(flag,false,10001);
		for(int j=2;j<=i;j++)
		{
			if(i%j == 0 && i/j >1 && flag[j] == false)
			{
				num+=1;
				flag[j]=true;
				flag[i/j]=true;
			}
		}
	}

	cout<<num<<endl;
}