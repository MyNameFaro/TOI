#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int N;
void dijkstra(vector <vector <pii>> &G , int x,vector<int> &dis){
	int setsize = 0;
	vector <bool> visited (N + 1,false);
	priority_queue <pii , vector <pii> , greater<pii>> PQ;
	dis[x] = 0;
	PQ.push({dis[x] , x});
	while(!PQ.empty()){
		int u = PQ.top().second;
		PQ.pop();
		if(visited[u]) continue;
		++setsize;
		if(setsize == N) break;
		visited[u] = true;
		for(auto vw:G[u]){
			int v = vw.first;
			int w = vw.second;
			if(dis[v] > dis[u] + w && !visited[v]){
				dis[v] = dis[u] + w;
				PQ.push({dis[v] , v});
			}
		}
	}
}
int main(){
	int M;
	scanf("%d %d",&N ,&M);
	int x , y , c;
	int z , u , v , w , p;
	scanf("%d %d %d",&x ,&y,&z);
	vector <vector <pii>> G (N + 1 , vector <pii>());
	while(M--){
		scanf("%d %d %d",&u ,&v ,&w);
		G[u].push_back({v , w});
		G[v].push_back({u , w});
	}
	vector <int> dis_x (N + 1,2e9) , dis_y (N + 1,2e9);
	dijkstra(G , x , dis_x);
	dijkstra(G , y , dis_y);
	int ans_u , ans_x = -2e9 , ans_y = 2e9;
	for(u = 0;u <= N;++u){
		if(dis_x[u] <= z){
			if(dis_x[u] >= ans_x && dis_y[u] < ans_y){
				ans_u = u;
				ans_x = dis_x[u];
				ans_y = dis_y[u];
			}
		}
	}
	printf("%d %d %d",ans_u ,ans_x ,ans_y);
}
