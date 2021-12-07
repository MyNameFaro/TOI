#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int di1[] = {0, 0, 1, -1, 1, -1};
int dj1[] = {1, -1, 0, 0, -1, -1};
int di2[] = {0, 0, 1, -1, 1, -1};
int dj2[] = {1, -1, 0, 0, 1, 1};
bool visited[102][102][2520];
int main(){
	int N,M;
	scanf("%d%d",&M,&N);
	int S[M][N];
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j) scanf("%d",&S[i][j]);
	}
	int ans=0;
	queue<pair<int,pii>>PQ;
	if(S[(M-1)/2][0]>0) PQ.push({1,{(M-1)/2,0}});
	if(S[(M-1)/2+1][0]>0) PQ.push({1,{(M-1)/2+1,0}});
	if(S[(M-1)/2-1][0]>0) PQ.push({1,{(M-1)/2-1,0}});
	
	while(!PQ.empty()){
		int n=PQ.front().first;
		int r=PQ.front().second.first;
		int c=PQ.front().second.second;PQ.pop();
		if(S[r][c]==0 or n%S[r][c]>0) continue;
		if(r==(M-1)/2 and c==N-1){
			ans=n;
			break;
		}
			int rr,cc;
			if(r%2 == 1){
				for(int i=0;i<6;++i){
					rr=r+di1[i];
					cc=c+dj1[i];
					if(rr<0 or rr>=M or cc<0 or cc>=N) continue;
					if(S[rr][cc]>0 and !visited[rr][cc][(n+1)%2520] and (n+1)%S[rr][cc]==0){
						visited[rr][cc][(n+1)%2520]=true;
						PQ.push({n+1,{rr,cc}});
					}
				}
				
			}else{
				for(int i=0;i<6;++i){
					rr=r+di2[i];
					cc=c+dj2[i];
					if(rr<0 or rr>=M or cc<0 or cc>=N) continue;
					if(S[rr][cc]>0 and !visited[rr][cc][(n+1)%2520] and (n+1)%S[rr][cc]==0){
						visited[rr][cc][(n+1)%2520]=true;
						PQ.push({n+1,{rr,cc}});
					}
				}
			}
	}
	printf("%d",ans);
}
