#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int G[200][200];
int dis[2][200][200];

const int di[]={-1,0,1,0};
const int dj[]={0,-1,0,1};

int N,M;

void stp(int rs,int cs,int x)
{
	queue <pii> Q;
	Q.emplace(rs,cs);
	dis[x][rs][cs]=0;
	while(!Q.empty())
	{
		int r=Q.front().first;
		int c=Q.front().second;Q.pop();
		for(int i=0;i<4;++i)
		{
			int rr=r+di[i];
			int cc=c+dj[i];
			if(rr<=0 or rr>N or cc<=0 or cc>M) continue;
			if(dis[x][rr][cc] > dis[x][r][c]+1){
				dis[x][rr][cc]=dis[x][r][c]+1;
				if(G[rr][cc]) Q.emplace(rr,cc);
			}
		}
	}
}
int main(){
	
	int rs,cs,re,ce;
	int ans1 =0,ans2=2e9;
	scanf("%d%d",&N,&M);
	scanf("%d%d%d%d",&rs,&cs,&re,&ce);
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=M;++j)
		{
			scanf("%d",&G[i][j]);
			dis[0][i][j]=2e9;
			dis[1][i][j]=2e9;
		}
	}
	stp(rs ,cs ,0);
	stp(re ,ce ,1);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j)
		{
			if(G[i][j]) continue;
			if(dis[0][i][j] < 2e9 and dis[1][i][j] < 2e9){
				ans2 = min(ans2 , dis[1][i][j] + dis[0][i][j] + 1);
				++ans1;
			}
		}
	}

	printf("%d\n%d",ans1,ans2);
}
