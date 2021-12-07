#include<bits/stdc++.h>
using namespace std;

int DP[102][102];
int arr[102][102];
int P[102][102];
int main()
{
	int M,N,T;
	scanf("%d%d%d",&N,&M,&T);
	for(int t=1;t<=T;++t)
	{
		for(int i=1;i<=N;++i)
		{
			scanf("%d",&arr[i][t]);
		}
	}
	for(int i=1;i<=N;++i)
	{
		if(arr[i][T]) continue;
		DP[i][T]=1;
	}
	for(int t=T-1;t>=0;--t)
	{
		for(int i=1;i<=N;++i)
		{
			if(arr[i][t]) continue;
			if(i>1 and arr[i-1][t+1]==0 and DP[i-1][t+1]){
				DP[i][t]=1;
				P[i][t]=i-1;
				continue;
			}
			if(arr[i][t+1]==0 and DP[i][t+1]){
				DP[i][t]=1;
				P[i][t]=i;
				continue;
			}
			if(i<N and arr[i+1][t+1]==0 and DP[i+1][t+1]){
				DP[i][t]=1;
				P[i][t]=i+1;
				continue;
			}
		}
	}
	int u = M;
	int t=0;
	while(t<T){
		//cout << u << " " << t << endl;
		if(P[u][t] > u)
			printf("2\n");
		else if(P[u][t] < u)
			printf("1\n");
		else
			printf("3\n");
		u=P[u][t];
		++t;
	}
	
}
