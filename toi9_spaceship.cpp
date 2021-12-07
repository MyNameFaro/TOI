#include<bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int>;
bool visited[100];
int n, m, p[100][2][4], ans=2e9;
int dis(int x1,int y1,int z1,int x2,int y2,int z2){
	return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1);
}
vector <tll> t;
int solve(int a,int b,int c,int d){
	int x=get<0>(t.back());
	int y=get<1>(t.back());
	int z=get<2>(t.back());
	if(a==n and b==n and c==n){
		ans=min(ans,d);
	}else{
		for(int i=1;i<=m;++i){
			if(visited[i]) continue;
			int xx=p[i][0][0];
			int yy=p[i][0][1];
			int zz=p[i][0][2];
			int aa=p[i][1][0];
			int bb=p[i][1][1];
			int cc=p[i][1][2];
			t.emplace_back(xx,yy,zz);
			visited[i]=true;
			solve(min(n,a+aa),min(n,b+bb),min(n,c+cc),d+dis(x,y,z,xx,yy,zz));
			visited[i]=false;
			t.pop_back();
		}
	}
}
int main(){
	scanf("%d",&n);
	scanf("%d%d%d",&p[0][0][0],&p[0][0][1],&p[0][0][2]);
	t.emplace_back(p[0][0][0],p[0][0][1],p[0][0][2]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&p[i][0][0],&p[i][0][1],&p[i][0][2]);
		scanf("%d%d%d",&p[i][1][0],&p[i][1][1],&p[i][1][2]);
	}
	solve(0,0,0,0);
	printf("%d",ans);
}
