// NumberTheroy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int gcd(int n,int m)
{
	if(n ==0)
		return m;
	return gcd(m%n,n);
}
extern void main_PostFix();
int _tmain(int argc, _TCHAR* argv[])
{
	main_PostFix();
	return 0;
}

