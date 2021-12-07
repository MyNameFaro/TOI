#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector <vector<int>> G , H;
vector <int> L , cnt_L;
vector <int> color;
int ans,T;
int update_ans=0;
int dfs(int u){
	int value=0;
	color[u]=1;
	for(auto v:G[u]){
		if(color[v]==1){
			return 0;
		}
		if(color[v]==0){
			int result = dfs(v);
			if(result==0){
				return 0;
			}
			value += result;	
		}
	}
	color[u]=2;
	--cnt_L[L[u]];
	if(cnt_L[ans+update_ans+1]==0) ++update_ans;
	return value+1;
}
int main(){
	int N,K;
	scanf("%d %d %d",&N,&K,&T);
	G.assign(N+1,vector<int>());
	L.assign(N+1,0);
	cnt_L.assign(K+1,0);
	color.assign(N+1,0);
	priority_queue <pii ,vector<pii>,greater<pii>>PQ;
	int u,v,n,l;
	for(v=1;v<=N;++v){
		scanf("%d",&L[v]);
		++cnt_L[L[v]];
		scanf("%d",&l);
		PQ.push({L[v],v});
		for(int i=1;i<=l;++i){
			scanf("%d",&u);
			G[v].push_back(u);
		}
	}
	while(T>0 and !PQ.empty()){
		while(!PQ.empty() and color[PQ.top().second]>0) PQ.pop();
		if(PQ.empty())break;
		update_ans=0;
		int result=dfs(PQ.top().second);
		if(result==0) break;
		if(T>=result){
			T=T-result;
			ans+=update_ans;
		}else{
			break;
		} 
		PQ.pop();
	}
	if(ans==0) --ans;
	printf("%d",ans);
}
