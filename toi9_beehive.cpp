#include<bits/stdc++.h>
using namespace std;

int DP[1002][1002] ,arr[1002][1002] , DP2[1002][1002];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=M;++j)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int j=1;j<=M;++j)
	{
		DP[N][j]=arr[N][j];
		DP2[N][j]=1;
	}
	int ans1=-2e9,ans2=0;
	for(int i=N-1;i>=1;--i)
	{
		for(int j=1;j<=M;++j)
		{
			DP[i][j]=arr[i][j];
			if(i%2)
			{
				if(DP[i+1][j] > DP[i+1][j-1])
				{
					DP[i][j] += DP[i+1][j];
					DP2[i][j] = DP2[i+1][j];
				}
				else if(DP[i+1][j] < DP[i+1][j-1])
				{
					DP[i][j] += DP[i+1][j-1];
					DP2[i][j] = DP2[i+1][j-1];
				}else{
					DP[i][j] += DP[i+1][j];
					DP2[i][j] = DP2[i+1][j] + DP2[i+1][j-1];
				}
			}
			else{
				if(DP[i+1][j] > DP[i+1][j+1])
				{
					DP[i][j] += DP[i+1][j];
					DP2[i][j] = DP2[i+1][j];
				}
				else if(DP[i+1][j] < DP[i+1][j+1])
				{
					DP[i][j] += DP[i+1][j+1];
					DP2[i][j] = DP2[i+1][j+1];
				}else{
					DP[i][j] += DP[i+1][j];
					DP2[i][j] = DP2[i+1][j] + DP2[i+1][j+1];
				}
				
			}
			if(i==1) ans1=max(ans1 , DP[1][j]);
		}
	}
	for(int j=1;j<=M;++j)
	{
		if(DP[1][j] == ans1)
		{
			ans2 += DP2[1][j];
		}
		
	}
	printf("%d %d",ans1,ans2);
}
