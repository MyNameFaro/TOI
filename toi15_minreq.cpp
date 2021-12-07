#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using tll=tuple<int,int,int>;
bool visited[12][1<<11][1<<11];
int main(){
	int N,M,X;
	scanf("%d%d%d",&N,&M,&X);
	lli L[12],A[12],S[100000010];
	int T[12],Q[12];
	S[0]=0;
	for(int i=1;i<=N;++i){
		scanf("%lld",&L[i]);
	}
	for(int i=1;i<=N;++i){
		scanf("%lld",&A[i]);
	}
	for(int i=1;i<=M;++i){
		scanf("%lld",&S[i]);
		//S[i]+=S[i-1];
	}
	for(int i=1;i<=X;++i){
		scanf("%d",&T[i]);
	}

}
