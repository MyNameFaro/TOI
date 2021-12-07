#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , int>;

const int NN = 500002;
vector<int> G[NN];
int disc[NN], low[NN] ,DP[NN], t=0;
int N,M;
int ans2 = 0,ans1 = 0;
void tarjan(int u,int p)
{
    disc[u] = ++t;
    low[u] = disc[u];
    DP[u] = 1;
    bool ap = false;
    for(auto v:G[u])
    {
        if(!disc[v])
        {
            tarjan(v , u);
            low[u] = min(low[v] , low[u]);
            if(low[v] >= disc[u])
            {
                ap = true;
            }
            if(low[v] != low[M])
            {
                DP[u] += DP[v];
            }

        }else if(v != p)
        {
            low[u] = min(low[u] , disc[v]);
        }
    }
    if(ap and u != M)
    {
        if(ans1 < DP[u])
        {
            ans1 = DP[u];
            ans2 = u;
        }else if(ans1 == DP[u])
        {
            ans2 = min(ans2 , u);
        }
    }
}
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	tarjan(M , -1);
    printf("%d\n%d", ans2, ans1 - 1);
}
/*
5 1
1 3
1 2
2 4
2 5
4 5
*/
