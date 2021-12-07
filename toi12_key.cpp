#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
	char s[1002],t[1002];
	scanf("%s",s);
	scanf("%s",t);
	int k;
	scanf("%d",&k);
	int m=strlen(s);
	int n=strlen(t);
	while(k--){
		char arr[2004];
		scanf("%s",arr);
		bool visited[m+1][n+1];
		for(int i=0;i<=m;++i){
			for(int j=0;j<=n;++j) visited[i][j]=false;
		}
		priority_queue<pii,vector<pii>,greater<pii>>PQ;
		PQ.emplace(0,0);
		while(!PQ.empty()){
			int i=PQ.top().first;
			int j=PQ.top().second;PQ.pop();
			if(visited[i][j]) continue;
			visited[i][j]=true;
			if(i==m and j==n) break;
			if(arr[i+j]==t[j] and !visited[i][j+1]){
				PQ.emplace(i,j+1);
			}
			if(arr[i+j]==s[i] and !visited[i+1][j]){
				PQ.emplace(i+1,j);
			}
		}
		if(visited[m][n]){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	
}
