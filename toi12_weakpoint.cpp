#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , int>;

const int N = 500002;
vector<int> G[N], cycle_list;
int color[N], DP[N];

int solve(int u, int p, int mode = 1)
{
	if (color[u] == 1 and mode == 2)
		return 1e9 + 7;
	if (DP[u] == 0)
	{
		DP[u] = 1;
		for (auto v : G[u])
		{
			if (v == p or color[v] == 1)
				continue;
			DP[u] += solve(v, u);
		}
	}
	return DP[u];
}

bool dfs(int u, int p)
{
	bool ans = false;
	color[u] = 1;
	for (auto v : G[u])
	{
		if (v == p)
			continue;
		if (color[v] == 1)
		{
			ans = true;
		}
		if (color[v] == 0 and dfs(v, u))
		{
			ans = true;
		}
	}
	if (!ans)
	{
		color[u] = 2;
	}
	else
	{
		cycle_list.push_back(u);
	}
	return ans;
}
int main()
{
	int n, m, cc = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
	{
		sort(G[i].begin(), G[i].end());
	}
	//FIND THE AGENT OF CYCLE NODE
	bool visited[n + 1];
	memset(visited, false, n + 1);
	
	stack<pair<int, int>> s;
	visited[m] = true;
	s.emplace(m, -1);
	while (!s.empty() and !cc)
	{
		int u = s.top().first;
		int p = s.top().second;
		s.pop();
		for (auto v : G[u])
		{
			if (v == p)
				continue;
			if (!visited[v])
			{
				visited[v] = true;
				s.emplace(v, u);
			}
			else
			{
				cc = v;
				break;
			}
		}
	}
	//CYCLE OR TREE AND FIND CYCLE LIST
	dfs(cc, -1);
	//SORTING
	sort(cycle_list.begin() , cycle_list.end());
	//CASE M IS IN CYCLE
	if (color[m] == 1)
	{
		int ans1 = 1, ans2 = 2e9;
		//CASE IN CYCLE_LIST
		for (auto u : cycle_list)
		{
			if (u == m)
				continue;
			if (solve(u, -1) > ans1)
			{
				ans1 = solve(u, -1);
				ans2 = u;
			}
			else if(solve(u , -1) == ans1)
			{
				ans2 = min(ans2 , u);
			}
		}
		//CASE IN neighbor NODE
		for (auto v : G[m]){
			if(color[v] == 1)
				continue;
			if(solve(v , m) > ans1)
			{
				ans1 = solve(v , m);
				ans2 = v;
			}
			else if(solve(v , m) == ans1)
			{
				ans2 = min(ans2 , v);
			}
		}
		printf("%d\n%d", ans2, ans1 - 1);
	}
	//CASE M IS IN TREE
	else
	{
		DP[m] = 1;
		int ans1 = 1, ans2 = 2e9;
		int c = 0;
		//CASE IN neighbor NODE THAT CAN'T GO TO THE CYCLE
		for (auto v : G[m])
		{
			int r = solve(v, m, 2);
			//IF NODE V CAN GO TO THE CYCLE
			if (r >= 1e9)
			{
				c = v;
			}
			else
			{
				DP[m] += r;
				if (r > ans1)
				{
					ans1 = r;
					ans2 = v;
				}
				else if(r == ans1){
					ans2 = min(ans2 , v);
				}
			}
		}
		//CASE THE OTHER NODE
		if (n - DP[m] > ans1)
		{
			ans1 = n - DP[m];
			ans2 = c;
		}
		else if(n - DP[m] == ans2)
		{
			ans2 = min(ans2 , c);
		}
		
		printf("%d\n%d", ans2, ans1 - 1);
	}
}
/*
5 1
1 3
1 2
2 4
2 5
4 5
*/
