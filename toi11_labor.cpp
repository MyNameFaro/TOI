#include<bits/stdc++.h>
using namespace std;
using lli=long long;
lli N;
lli M;
lli arr[1000002];
bool check(lli time){
	lli sum_N=0;
	for(lli i=1;i<=M;++i){
		if(arr[i]>time) return false;
		sum_N+=(time/arr[i]);
		if(sum_N >= N) return true;	
	}	
	return false;
}
int main(){
	cin>>M>>N;
	for(lli i=1;i<=M;++i) scanf("%lld",&arr[i]);
	sort(arr,arr+M+1);
	
	lli ans=10000000000000000;
	lli l=1,r=10000000000000000;
	while(l<=r){
		lli mid=(l+r)/2;
		if(check(mid)){
			ans=min(ans,mid);
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout << ans;
}
