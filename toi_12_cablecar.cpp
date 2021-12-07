#include <bits/stdc++.h>
using namespace std;
using pii = pair<int , int>;

int main(){
	int N , M;
	scanf("%d %d",&N ,&M);
	vector <vector <pii>> G (N + 1,vector <pii>());
	priority_queue <pii> PQ;
	vector <int> dis (N + 1,0);
	vector <int> visited (N + 1,false);
	int s , d , p;
	int u ,v , w;
	for(int i = 1;i <= M;++i){
		scanf("%d %d %d",&u ,&v ,&w);
		G[u].push_back({v , w});
		G[v].push_back({u , w});
	}
	scanf("%d %d %d",&s ,&d , &p);
	dis[s] = 2e9;
	PQ.push({dis[s] , s});
	while(!PQ.empty()){
		u = PQ.top().second;
		PQ.pop();
		if(visited[u]) continue;
		visited[u] = true;
		for(auto vw:G[u]){
			v = vw.first;
			w = vw.second;
			if(dis[v] < min(dis[u] , w)){
				dis[v] = min(dis[u] , w);
				PQ.push({dis[v] , v});
			}
		}
	}
	int ans = p / (dis[d] - 1);
	if(p % (dis[d] - 1) != 0) ++ans;
	printf("%d",ans);
}
