#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int sum_w;
int ans;
vector<vector <pii>> G;
vector<int>color;
int dfs(int p,int u){
	int returning=-1;
	if(color[u]==1) return u;
	color[u]=1;
	for(auto vw:G[u]){
		int v=vw.first;
		int w=vw.second;
		if(v==p or color[v]>1) continue;
		int result=dfs(u,v);
		if(result>-1){
			//cout << w << endl;
			ans+=w;
			returning=result;
			if(u==result) returning=-1;
		}
	}
	color[u]=2;
	return returning;
}
int main(){
	int N,M;
	int u,v,w;
	scanf("%d %d",&M,&N);
	G.assign(N+1,vector<pii>());
	color.assign(N+1,0);
	while(M--){
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		sum_w+=w;
	}
	//cout << sum_w<<endl;
	dfs(-1,0);
	//cout << ans << endl;
	sum_w-=ans;
	printf("%d",ans+(sum_w*2));
}
