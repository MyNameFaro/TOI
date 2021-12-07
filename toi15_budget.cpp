#include<bits/stdc++.h>
using namespace std;
int p[3010];
int find(int u){
	if(p[u]==-1) return u;
	return p[u]=find(p[u]); 
}
int unionn(int u,int v){
	u=find(u);
	v=find(v);
	p[u]=v;
}
int main(){
	int B,E;
	long long int ans=0;
	scanf("%d%d",&B,&E);
	int u,v,w,s;
	priority_queue<tuple<int,int,int,int> , vector<tuple<int,int,int,int>> ,greater<tuple<int,int,int,int>>>PQ;
	for(int i=0;i<=B;++i){
		p[i]=-1;
	}
	while(E--){
		scanf("%d%d%d%d",&u,&v,&w,&s);
		if(s==1){
			unionn(u,v);
		}else{
			PQ.emplace(w,u,v,s);
		} 
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>L;
	int P,p;
	scanf("%d",&P);
	while(P--){
		scanf("%d%d",&w,&p);
		L.push({p,w});
	}
	while(!PQ.empty()){
		w=get<0>(PQ.top());
		u=get<1>(PQ.top());
		v=get<2>(PQ.top());
		s=get<3>(PQ.top());PQ.pop();
		if(find(u)==find(v)) continue;
		unionn(u,v);
		if(s==0){
			//printf("%d %d %d\n",u,v,w);
			while(L.top().second<w) L.pop();
			ans+=L.top().first;
		}
	}
	printf("%lld",ans);
	
}
