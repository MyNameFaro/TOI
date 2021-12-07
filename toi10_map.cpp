#include <bits/stdc++.h>
using namespace std;
int arr[410][410];
vector <vector <int>> G;
int n_begin = 2e9 , n_end = -2e9 , m_begin = 2e9 , m_end = -2e9;
int draw(int p , int u , int n , int m){
	n_begin = min(n_begin , n);
	m_begin = min(m_begin , m);
	n_end = max(n_end , n);
	m_end = max(m_end , m);
	arr[n][m] = u;
	for(int i = 0;i < 4;++i){
		int v = G[u][i];
		if(v == 2e9 || v == p) continue;
		if(i == 1){
			draw(u , v , n , m - 1);
		}else if(i == 2){
			draw(u , v , n + 1 , m);
		}else if(i == 3){
			draw(u , v , n , m + 1);
		}else{
			draw(u , v , n - 1 , m);
		}
	}
}
int main(){
	int m , n;
	scanf("%d %d",&m ,&n);
	int u , v;
	char c;
	vector <int> vec (4 , 2e9);
	G.assign(n * m , vec);
	for(int i = 1;i < n * m;++i){
		cin >> u >> c >> v;
		if(c == 'U'){
			G[u][2] = v;
			G[v][0] = u;
		}else{
			G[u][3] = v;
			G[v][1] = u;
		} 
	}
	draw(-1 , 0 , 205,205);
	for(int i = n_begin;i <= n_end;++i){
		for(int j = m_begin;j <= m_end;++j) printf("%d ",arr[i][j]);
		printf("\n");
	}
}
