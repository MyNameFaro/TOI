#include <bits/stdc++.h>
using namespace std;
using lli =long long;

int P=1e9+7;
lli arr[5][3005];
map <lli , pair<int,int>> check; //check hash

int main()
{
	int X,Y,N;
	lli hash;
	
	scanf("%d%d%d",&X ,&Y ,&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld%lld",&arr[1][2*i-1],&arr[1][2*i]);
	}
	for(int i=1;i<=N;i++)
	{
		scanf("%lld%lld",&arr[2][2*i-1],&arr[2][2*i]);
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			hash = (arr[1][2*i-1]+arr[2][2*j-1])*P + arr[1][2*i] + arr[2][2*j];
			check[hash]=make_pair(i , j);
		}
	}
	for(int i=1;i<=N;i++)
	{
		scanf("%lld%lld",&arr[3][2*i-1],&arr[3][2*i]);
	}
	for(int i=1;i<=N;i++)
	{
		scanf("%lld%lld",&arr[4][2*i-1],&arr[4][2*i]);
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			hash = (X - (arr[3][2*i-1]+arr[4][2*j-1]))*P + (Y - (arr[3][2*i] + arr[4][2*j]));
			if(check.count(hash) > 0)
			{
				int ii=check[hash].first;
				int jj=check[hash].second;
				printf("%lld %lld\n",arr[1][2*ii-1],arr[1][ii*2]);
				printf("%lld %lld\n",arr[2][2*jj-1],arr[2][jj*2]);
				printf("%lld %lld\n",arr[3][2*i-1],arr[3][2*i]);
				printf("%lld %lld\n",arr[4][2*j-1],arr[4][2*j]);
				return 0;
			}
		}
	}
}
