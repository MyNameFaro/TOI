#include<bits/stdc++.h>
using namespace std;

int qs[1002][1002];

int query(int r1,int c1,int r2,int c2)
{
	return qs[r2][c2]-qs[r1][c2]-qs[r2][c1]+qs[r1][c1];
}

int main()
{
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	int mx=-2e9;
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=M;++j)
		{
			scanf("%d",&qs[i][j]);
			qs[i][j]+=qs[i][j-1]+qs[i-1][j]-qs[i-1][j-1];
		}
	}
	for(int i=K;i<=N;++i)
	{
		for(int j=K;j<=M;++j)
		{
			mx=max(mx , query(i-K,j-K,i,j));
		}
	}
	printf("%d",mx);
}
