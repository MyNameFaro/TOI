#include<bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<lli,lli>;
using tll = tuple<lli , lli ,int ,int>;

int main(){
	lli xt , yt;
	scanf("%lld %lld",&xt,&yt);
	int N;
	scanf("%d",&N);
	vector <tll> sum_AB , sum_CD;
	vector <pii> A (N + 2) , B (N + 2) , C (N + 2) , D (N + 2);
	for(int i=1;i<=N;++i) scanf("%lld %lld",&A[i].first , &A[i].second);
	for(int i=1;i<=N;++i) scanf("%lld %lld",&B[i].first , &B[i].second);
	for(int i=1;i<=N;++i) scanf("%lld %lld",&C[i].first , &C[i].second);
	for(int i=1;i<=N;++i) scanf("%lld %lld",&D[i].first , &D[i].second);
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			sum_AB.emplace_back(A[i].first + B[j].first , A[i].second + B[j].second , i , j );
 		}
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			sum_CD.emplace_back(C[i].first + D[j].first , C[i].second + D[j].second , i , j );
 		}
	}
	sort(sum_AB.begin() , sum_AB.end());
	sort(sum_CD.begin() , sum_CD.end());
	for(int i=0;i<sum_CD.size();++i){
			lli find_ABx = xt - get<0>(sum_CD[i]);
			lli find_ABy = yt - get<1>(sum_CD[i]);
			int l = 0;int r = sum_AB.size() - 1;
			while(l <= r){
				int mid = (l + r)/2;
				if(get<0>(sum_AB[mid]) == find_ABx && get<1>(sum_AB[mid]) == find_ABy){
					printf("%lld %lld\n",A[get<2>(sum_AB[mid])].first , A[get<2>(sum_AB[mid])].second);
					printf("%lld %lld\n",B[get<3>(sum_AB[mid])].first , B[get<3>(sum_AB[mid])].second);
					printf("%lld %lld\n",C[get<2>(sum_CD[i])].first , C[get<2>(sum_CD[i])].second);
					printf("%lld %lld\n",D[get<3>(sum_CD[i])].first , D[get<3>(sum_CD[i])].second);
					return 0;
				}
				if(get<0>(sum_AB[mid]) == find_ABx){
					if(get<1>(sum_AB[mid]) > find_ABy){
						r = mid - 1;
					}else{
						l = mid + 1;
					} 
				}else{
					if(get<0>(sum_AB[mid]) > find_ABx){
						r = mid - 1;
					}else{
						l = mid + 1;
					}
				}
			}
	}
}

