#include<bits/stdc++.h>
using namespace std;

bool visited[30][30] ,found=false;
vector <int> G[30];
vector <int> slug;
set<vector <int>> ans;
int N;

void solve(int u,int n){
	if(n==N){
		ans.insert(slug);
	}
	for(auto v:G[u]){
		if(!visited[u][v]){
			visited[u][v]=true;
			visited[v][u]=true;
			
			slug.push_back(v);
			solve(v, n+1);
			slug.pop_back();
			
			visited[u][v]=false;
			visited[v][u]=false;
		}
	}
	
}
int main(){
	scanf("%d",&N);
	char u,v;
	for(int i=1;i<=N;++i){
		cin >> u >> v;
		G[u-'A'].push_back(v-'A');
		G[v-'A'].push_back(u-'A');
	}
	for(int i=0;i<26;++i){
		for(int j=0;j<30;++j){
			for(int k=0;k<30;++k) visited[j][k]=false;
		}
		slug.push_back(i);
		solve(i,0);
		slug.pop_back();
	}
	for(auto s:ans){
		for(auto a:s){
			printf("%c ",a+'A');
		}
		break;
	}
	
}
