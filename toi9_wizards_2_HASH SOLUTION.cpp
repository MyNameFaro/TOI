#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using lli = long long;
using pii = pair<lli,lli>;
int main(){
	lli xt , yt;
	scanf("%lld %lld",&xt,&yt);
	int N;
	scanf("%d",&N);
	unordered_map <lli , pii> sum_AB;
	vector<pii> A (N + 2) , B (N + 2) , C (N + 2) , D (N + 2);
	for(int i=1;i<=N;++i) scanf("%lld %lld",&A[i].X , &A[i].Y);
	for(int i=1;i<=N;++i) scanf("%lld %lld",&B[i].X , &B[i].Y);
	for(int i=1;i<=N;++i) scanf("%lld %lld",&C[i].X , &C[i].Y);
	for(int i=1;i<=N;++i) scanf("%lld %lld",&D[i].X , &D[i].Y);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			lli sum_ABx = A[i].X + B[j].X;
			lli sum_ABy = A[i].Y + B[j].Y;
			lli key = (sum_ABx * N) + sum_ABy;
			sum_AB[key] = make_pair(i , j);
		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			lli find_ABx = xt - (C[i].X + D[j].X);
			lli find_ABy = yt - (C[i].Y + D[j].Y);
			lli key = (find_ABx * N) + find_ABy; 
			if(sum_AB.count(key) > 0){
				pii ansAB = sum_AB[key];
				printf("%lld %lld\n",A[ansAB.first].X , A[ansAB.first].Y);
				printf("%lld %lld\n",B[ansAB.second].X , B[ansAB.second].Y);
				printf("%lld %lld\n",C[i].X , C[i].Y);
				printf("%lld %lld\n",D[j].X , D[j].Y);
				return 0;
			}
		}
	}
}
