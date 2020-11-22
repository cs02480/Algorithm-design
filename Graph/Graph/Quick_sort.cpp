#include <iostream>
using namespace std;
//int A[10];
int Pivote_ind(int * A,int lo,int hi)
{
	int piv;
	piv = A[lo];
	int lo_lo=lo;
	int hi_hi=hi+1;
	do
	{
		do
		{
			lo_lo++;
		}while (A[lo_lo]<piv);

		do
		{
			hi_hi--;
		}while (A[hi_hi]>piv);

		if(lo_lo<hi_hi)
		{
			int tmp = A[lo_lo];
		    A[lo_lo]=A[hi_hi];
			A[hi_hi]=tmp;
		}
	}while(lo_lo < hi_hi);
	//if(lo_lo >= hi_hi)
	{
		int tmp = A[hi_hi];
		A[hi_hi]=piv;
		A[lo]=tmp;
	}
	return hi_hi;
}
void Quick_sort(int * A,int lo,int hi)
{
	if(lo<hi)
	{
		int piv = Pivote_ind(A,lo,hi);
		Quick_sort(A,lo,piv-1);
		Quick_sort(A,piv+1,hi);
	}

}

int main()
{
	int arr[] = {9, 10, -2, 7, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	Quick_sort(arr,0,n-1);
	for(int i=0;i<=n-1;i++)
	{

		cout<<arr[i]<<" ";
	}
	cout<<endl;
}