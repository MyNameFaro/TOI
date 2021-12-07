#include<bits/stdc++.h>
using namespace std;
int K,O;
int w[102],sum;
int pack(int cap){
	int adsl=1;
	int sum_adsl=0;
	for(int i=1;i<=O;++i){
		if(w[i]>cap) return 2e9;
		if(sum_adsl+w[i]>cap){
			sum_adsl=0;
			++adsl;
		}
		sum_adsl+=w[i];
	}
	return adsl;
}
int main(){
	int max_w=0;
	scanf("%d%d",&K,&O);
	for(int i=1;i<=O;++i){
		scanf("%d",&w[i]);
		max_w=max(max_w,w[i]);
		sum+=w[i];
	} 
	int l=max_w;int r=sum;
	int ans=2e9;
	while(l<=r){
		int mid=(l+r)/2;
		if(pack(mid)>K){
			l=mid+1;
		}else{
			ans=min(ans,mid);
			r=mid-1;
		}
	}
	cout << ans;
}
