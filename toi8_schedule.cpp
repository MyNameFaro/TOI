#include<bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int,int,int>;
using pii=pair<int,int>;
int main(){
	int N,M;
	scanf("%d%d",&M,&N);
	int J[N+1],K[N+1];
	pii DP[N+1][N+1];
	J[0]=K[0]=0;
	for(int j=1;j<=N;++j){
		scanf("%d",&J[j]);
		J[j]+=J[j-1];
	}
	for(int k=1;k<=N;++k){
		scanf("%d",&K[k]);
		K[k]+=K[k-1];
	}
	for(int j=0;j<=N;++j){
		for(int k=0;k<=N;++k){
			if(k==0 and j==0){
				DP[j][k]=make_pair(0,0);
				continue;
			}
			//int jj=j,kk=k,jmax=j;
			int dd=2e9,tt=2e9;
			bool breaker=false;
			for(int jj=j;jj>=0;--jj){
				for(int kk=k;kk>=0;--kk){
					if(J[j]-J[jj]+K[k]-K[kk]>M){
						if(kk==k) breaker=true;
						break;
					} 
					if(jj==j and kk==k) continue;
					if(DP[jj][kk].first+1<dd){
						dd=DP[jj][kk].first+1;
						tt=J[j]-J[jj]+K[k]-K[kk];
					}
					else if(DP[jj][kk].first+1==dd){
						tt=min(tt,J[j]-J[jj]+K[k]-K[kk]);
					}
				}
				if(breaker) break;
			}
			DP[j][k]=make_pair(dd,tt);
		}
	}
	
	printf("%d\n%d",DP[N][N].first,DP[N][N].second);
}
