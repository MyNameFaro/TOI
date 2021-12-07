#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using tll=tuple<int,int,int>;
vector<pii> G[10002];
void djk(vector <int> &dis,int X){
	vector<bool> visited(10002,false);
	priority_queue <pii,vector<pii>,greater<pii>>PQ;
	dis[X]=0;
	PQ.emplace(dis[X],X);
	while(!PQ.empty()){
		int u=PQ.top().second;PQ.pop();
		if(visited[u]) continue;
		visited[u]=true;
		for(auto vw:G[u]){
			int v=vw.first;
			int w=vw.second;
			if(!visited[v] and dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				PQ.emplace(dis[v],v);
			}
		}
	}
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	int X,Y,Z;
	scanf("%d%d%d",&X,&Y,&Z);
	while(M--){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	vector <int> disX(N,2e9) ,disY(N,2e9);
	djk(disX,X);
	djk(disY,Y);
	priority_queue <tll,vector<tll>,greater<tll>> ans;
	for(int u=0;u<N;++u){
		if(disX[u]>Z) continue;
		ans.emplace(disY[u],u,disX[u]);
	}
	int ans1=get<0>(ans.top());
	int ans2=get<2>(ans.top());
	int ans3=get<1 >(ans.top());
	printf("%d %d %d",ans3,ans2,ans1);
}
