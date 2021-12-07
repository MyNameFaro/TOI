#include<bits/stdc++.h>
using namespace std;

int p[200005][2];
int s[200005];
bool visited[200005];

bool solve(int n,int aim)
{
	if(n > aim)
	{
		return true;
	}
	bool ans=false;
	if(!visited[s[p[n][0]]])
	{
		visited[s[p[n][0]]]=true;
		ans=solve(n+1,aim);
		visited[s[p[n][0]]]=false;
	}
	if(!ans and !visited[s[p[n][1]]])
	{
		visited[s[p[n][1]]]=true;
		ans=solve(n+1,aim);
		visited[s[p[n][1]]]=false;
	}
	return ans;
}
int main()
{
	vector <char> ANS;
	for(int r=1;r<=5;++r)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%d%d",&p[i][0],&p[i][1]);
		}
		for(int i=1;i<=m/2;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			s[u]=v;
			s[v]=u;
		}
		if(solve(1,n))
		{
			ANS.push_back('Y');
		}else{
			ANS.push_back('N');
		}
	}
	for(auto a:ANS)
	{
		cout << a;
	}
}
