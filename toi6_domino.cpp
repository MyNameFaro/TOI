#include <bits/stdc++.h>
using namespace std;

vector <int> v;
int solve(int n)
{
	if(n==0)
	{
		for(int i = 0; i < v.size() ;++i)
		{
			if(v[i]==1)
			{
				printf("--\n");
			}
			else
			{
				printf("||\n");
			}
			
		}
		printf("E\n");
		return 0;
	}
	if(n>=1)
	{
		v.push_back(1);
		solve(n-1);
		v.pop_back();
	}
	if(n>=2)
	{
		v.push_back(2);
		solve(n-2);
		v.pop_back();
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	solve(n);
}
