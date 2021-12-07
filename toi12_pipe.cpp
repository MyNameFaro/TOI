#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	int dis[N+1];
	bool visited[N+1];
	int p[N+1][2];
	int ans=0;
	set <int> unvisited;
	for(int i=1;i<=N;++i)
	{
		dis[i]=2e9;
		visited[i]=false;
		scanf("%d%d",&p[i][0],&p[i][1]);
	}
	
	int u=1;
	dis[1]=0;
	visited[1]=true;
	for(int r=1;r<N;++r)
	{
		int vv=-1;
		int mn=2e9;
		for(int v=1;v<=N;++v){
			if(visited[v]) continue;
			//cout << w << endl;
			dis[v]=min(dis[v] ,abs(p[u][0]-p[v][0])+abs(p[u][1]-p[v][1]));
			if(dis[v]<mn){
				mn=dis[v];
				vv=v;
			}
		}
		visited[vv]=true;
		u=vv;
		//cout << vv << " " << dis[vv] << endl;
		ans+=dis[vv];
	}
	sort(dis+1 ,dis+N+1);
	for(int i=N;i>N-K+1;--i){
		ans-=dis[i];
	}
	printf("%d",ans);
}
