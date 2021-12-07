#include<bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int>;

bool visited[2520][102][102];


int main(){
	int N,M;
	scanf("%d%d",&M,&N);
	int S[102][102];
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j) scanf("%d",&S[i][j]);
	}
	
	int ans=2e9,rr,cc,dis,r,c,j,i;
	queue <tll> PQ;
	
	PQ.emplace(0,(M-1)/2 ,-1);

	while(!PQ.empty()){
		dis=get<0>(PQ.front());
		r=get<1>(PQ.front());
		c=get<2>(PQ.front());PQ.pop();
		
		if(r==(M-1)/2 and c==N-1){
			ans=dis;
			break;
		}
		//r-1,c
		if(r>=1 and S[r-1][c]>0 and (dis+1)%S[r-1][c]==0 and !visited[(dis+1)%2520][r-1][c]){
			visited[(dis+1)%2520][r-1][c]=true;
			PQ.emplace(dis+1,r-1,c);
		}
		//r+1,c
		if(r+1<M and S[r+1][c]>0 and (dis+1)%S[r+1][c]==0 and !visited[(dis+1)%2520][r+1][c]){
			visited[(dis+1)%2520][r+1][c]=true;
			PQ.emplace(dis+1,r+1,c);
		}
		//r,c-1
		if(c-1>=0 and S[r][c-1]>0 and (dis+1)%S[r][c-1]==0 and !visited[(dis+1)%2520][r][c-1]){
			visited[(dis+1)%2520][r][c-1]=true;
			PQ.emplace(dis+1,r,c-1);
		}
		//r,c+1
		if(c+1<N and S[r][c+1]>0 and (dis+1)%S[r][c+1]==0 and !visited[(dis+1)%2520][r][c+1]){
			visited[(dis+1)%2520][r][c+1]=true;
			PQ.emplace(dis+1,r,c+1);
		}
		
		if(r%2==1){
			
		//r-1,c-1	
		if(r-1>=0 and c-1>=0 and S[r-1][c-1]>0 and (dis+1)%S[r-1][c-1]==0 and !visited[(dis+1)%2520][r-1][c-1]){
			visited[(dis+1)%2520][r-1][c-1]=true;
			PQ.emplace(dis+1,r-1,c-1);
		}	
		//r+1,c-1
		if(r+1<M and c-1>=0 and S[r+1][c-1]>0 and (dis+1)%S[r+1][c-1]==0 and !visited[(dis+1)%2520][r+1][c-1]){
			visited[(dis+1)%2520][r+1][c-1]=true;
			PQ.emplace(dis+1,r+1,c-1);
		}
			
		}else{
		
		//r-1,c+1	
		if(r-1>=0 and c+1<N and S[r-1][c+1]>0 and (dis+1)%S[r-1][c+1]==0 and !visited[(dis+1)%2520][r-1][c+1]){
			visited[(dis+1)%2520][r-1][c+1]=true;
			PQ.emplace(dis+1,r-1,c+1);
		}	
		//r+1,c+1
		if(r+1<M and c+1<N and S[r+1][c+1]>0 and (dis+1)%S[r+1][c+1]==0 and !visited[(dis+1)%2520][r+1][c+1]){
			visited[(dis+1)%2520][r+1][c+1]=true;
			PQ.emplace(dis+1,r+1,c+1);
		}
			
		}
	}
	
	printf("%d",ans);
	return 0;
}

