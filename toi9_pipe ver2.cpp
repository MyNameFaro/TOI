#include <bits/stdc++.h>
using namespace std;

const int di[] = {0 , 1 , 0 , -1};
const int dj[] = {1 , 0 , -1 , 0};

int G[305][305];
int visited[305][305];

vector <int> ans;

int solve(int rs,int cs,int d)
{
	int mx=0;
	if(!visited[rs][cs]) return 0;
	int r=rs , c=cs;
	--visited[rs][cs];
	while(G[r][c])
	{
		int rr,cc,dd=d;
		if(d == 0)
		{
			if(G[r][c]==11)
			{
				dd=3;
			}else if(G[r][c]==13)
			{
				dd=1;
			}else if(G[r][c]==22 or G[r][c]==31)
			{
				dd=d;
			}
		}else if(d == 1)
		{
			if(G[r][c]==11)
			{
				dd=2;
			}else if(G[r][c]==12)
			{
				dd=0;
			}else if(G[r][c]==21 or G[r][c]==31)
			{
				dd=d;
			}
		}else if(d == 2)
		{
			if(G[r][c]==12)
			{
				dd=3;
			}else if(G[r][c]==14)
			{
				dd=1;
			}else if(G[r][c]==22 or G[r][c]==31)
			{
				dd=d;
			}
		}else if(d == 3)
		{
			if(G[r][c]==13)
			{
				dd=2;
			}else if(G[r][c]==14)
			{
				dd=0;
			}else if(G[r][c]==21 or G[r][c]==31)
			{
				dd=d;
			}
		}
		rr=r + di[dd];
		cc=c + dj[dd];
		visited[rr][cc]--;
		d=dd;
		r=rr;
		c=cc;
		++mx;
	}
	ans.push_back(mx);
}
int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=M;++j)
		{
			scanf("%d",&G[i][j]);
			if(G[i][j] == 31)
			{
				visited[i][j]=2;
			}else if(G[i][j] == 0)
			{
				visited[i][j]=0;
			}else{
				visited[i][j]=1;
			}
		}
	}
	for(int i=1;i<=N;++i)
	{
		if((G[i][1] == 11) or (G[i][1] == 13) or (G[i][1] == 22) or (G[i][1] == 31)) solve(i , 1 , 0);
		if((G[i][M] == 12) or (G[i][M] == 14) or (G[i][M] == 22) or (G[i][M] == 31)) solve(i , M , 2);
	}
	for(int j=1;j<=M;++j)
	{
		if((G[1][j] == 11) or (G[1][j] == 12) or (G[1][j] == 21) or (G[1][j] == 31)) solve(1 , j , 1);
		if((G[N][j] == 13) or (G[N][j] == 14) or (G[N][j] == 21) or (G[N][j] == 31)) solve(N , j , 3);
	}
	printf("%d\n",ans.size());
	for(auto a:ans)
	{
		printf("%d ",a);
	}
}
