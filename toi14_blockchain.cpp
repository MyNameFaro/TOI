#include<bits/stdc++.h>
using namespace std;
vector <int> memo;
vector <vector <int>> G;
int solve(int u){
	if(memo[u]==0){
		memo[u]=1;
		for(auto v:G[u]){
			if(memo[v]>0) continue;
			memo[u]+=solve(v);
		}
	}
	return memo[u];
	
}
int main(){
	multiset <vector<int>> D;
	int t,q;
	cin >> t >> q;
	int n,u,v;
	while(t--){
		cin >> n;
		memo.assign(n+1,0);
		G.assign(n+1,vector<int>());
		for(int i=1;i<n;++i){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int u=1;u<=n;++u){
			if(memo[u]==0) solve(u);
		}
		D.insert(memo);
		memo.clear();
		G.clear();
	}
	while(q--){
		cin >> n;
		memo.assign(n+1,0);
		G.assign(n+1,vector<int>());
		for(int i=1;i<n;++i){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int u=1;u<=n;++u){
			if(memo[u]==0) solve(u);
		}
		cout << D.count(memo) << endl;
		memo.clear();
		G.clear();
	}
	
}
