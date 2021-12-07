#include<bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int>;
int p[300000];
int rankk[300000];
int find(int u){
	if(p[u]==-1) return u;
	return p[u]=find(p[u]);
}
void unionn(int u,int v){
	u=find(u);
	v=find(v);
	if(rankk[u]>rankk[v]) swap(u,v);
	p[u]=v;
	rankk[v]+=rankk[u];
}
int main(){
	int n,m;
	int k=0;
	long long int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;++i){
		p[i]=-1;
		rankk[i]=1;
	}
	priority_queue<tll> PQ;
	for(int i=1;i<=m;++i){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		PQ.emplace(w-1,u,v);
	}
	while(!PQ.empty() and k<m){
		int w=get<0>(PQ.top());
		int u=get<1>(PQ.top());
		int v=get<2>(PQ.top());PQ.pop();
		if(find(u)==find(v)) continue;
		ans+=w;
		unionn(u,v);
		++k;
	}
	printf("%lld",ans);
}
