#include <bits/stdc++.h>
using namespace std;

bool visited[10] ,m_list[10];
vector <int> v;
int n;
void solve(int x)
{
	if(x == n){
		for(auto c:v)
		{
			printf("%d ",c);
		}
		printf("\n");
		return;	
	}
	for(int i=1;i<=n;++i)
	{
		if(visited[i] or (x==0 and m_list[i])) continue;
		visited[i]=true;
		v.push_back(i);
		solve(x+1);
		v.pop_back();
		visited[i]=false;
		
	}
}

int main()
{
	int m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&x);
		m_list[x]=true;
	}
	solve(0);
}
