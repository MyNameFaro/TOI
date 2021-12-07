#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
	int N , M;
	char c;
	scanf("%d %d",&N ,&M);
	vector <pii> G [N+3][M+3];
	int visited [N+3][M+3];
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			cin >> c;
			visited[i][j] = 0;
			if((c=='R' or c=='B') and j<M){
				if(find(G[i][j].begin() , G[i][j].end() , make_pair(i,j+1)) == G[i][j].end()) G[i][j].push_back({i , j + 1});
				if(find(G[i][j+1].begin() , G[i][j+1].end() , make_pair(i,j)) == G[i][j+1].end()) G[i][j + 1].push_back({i,j});
			} 
			if((c=='D' or c=='B') and i<N){
				if(find(G[i][j].begin() , G[i][j].end() , make_pair(i+1,j)) == G[i][j].end()) G[i][j].push_back({i + 1 , j});
				if(find(G[i+1][j].begin() , G[i+1][j].end() , make_pair(i,j)) == G[i+1][j].end()) G[i + 1][j].push_back({i,j});
			} 	
		}
	}
	queue <pair<pii,pii>> S;
	S.push({{1,1} , {-1,-1}});
	visited[1][1]=1;
	while(!S.empty()){
		int ur=S.front().first.first;
		int uc=S.front().first.second;
		int pr=S.front().second.first;
		int pc=S.front().second.second;S.pop();
		//cout << ur << " " << uc <<" "<< pr << " " << pc << endl;
		for(auto v:G[ur][uc]){
			int vr=v.first;
			int vc=v.second;
			if((vr == pr and vc == pc)) continue;
			if(visited[vr][vc]==0){
				visited[vr][vc]=visited[ur][uc]+1;
				S.push({{vr,vc} , {ur,uc}});
			}else{
				printf("%d\n",visited[vr][vc]);
				printf("%d %d",vr,vc);
				return 0;
			}
		}
	}
	printf("-1");
}
