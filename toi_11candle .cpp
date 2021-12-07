#include <bits/stdc++.h>
#define M second
#define N first
using namespace std;
bool g[2002][2002];
long int ans;

void bfs(int n,int m){
	++ans;
	queue <pair <int , int>> q;
	pair <int , int> node;
	q.push({n , m});
	g[n][m] = false;
	while(!q.empty()){
		node = q.front();
		q.pop();
		if(g[node.N - 1][node.M - 1]){
			g[node.N - 1][node.M - 1] = false;
			q.push({node.N - 1,node.M - 1});
		}
		if(g[node.N][node.M - 1]){
			g[node.N][node.M - 1] = false;
			q.push({node.N,node.M - 1});
		}
		if(g[node.N + 1][node.M - 1]){
			g[node.N + 1][node.M - 1] = false;
			q.push({node.N + 1,node.M - 1});
		}
		
		if(g[node.N - 1][node.M]){
			g[node.N - 1][node.M] = false;
			q.push({node.N - 1,node.M });
		}
		if(g[node.N + 1][node.M]){
			g[node.N + 1][node.M] = false;
			q.push({node.N + 1,node.M});
		}
		
		if(g[node.N - 1][node.M + 1]){
			g[node.N - 1][node.M + 1] = false;
			q.push({node.N - 1,node.M + 1});
		}
		if(g[node.N][node.M + 1]){
			g[node.N][node.M + 1] = false;
			q.push({node.N,node.M + 1});
		}
		if(g[node.N + 1][node.M + 1]){
			g[node.N + 1][node.M + 1] = false;
			q.push({node.N + 1,node.M + 1});
		}
	}
}
int main(){
	int M , N , m , n , x;
	scanf("%d %d",&M , &N);
	string s;
	for(m = 1;m <= M;++m){
		cin >> s;
		for(n = 0;n < s.size();++n){
			if(s[n] == '1'){
				g[n + 1][m] = true;
			}
		}
	}
	for(m = 1;m <= M;++m){
		for(n = 1;n <= N;++n){
			if(g[n][m]){
				bfs(n , m);
			}
		}
	}
	printf("%ld",ans);
}
