#include<bits/stdc++.h>
using namespace std;
int arr_n[1000010],N;
int upper_bound(int x){
	int l=0,r=N-1;
	int ans=2e9;
	while(l<=r){
		int mid=(l+r)/2;
		if(arr_n[mid]>=x){
			ans=min(ans,mid);
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
int lower_bound(int x){
	int l=0,r=N-1;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(arr_n[mid]<=x){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	int M,K,L;
	scanf("%d%d%d%d",&N,&M,&K,&L);
	for(int i=0;i<N;++i) scanf("%d",&arr_n[i]);
	sort(arr_n,arr_n+N);
	while(K--){
		int ans=0;
		vector<pair<int,int>> range,event;
		int m;
		for(int i=0;i<M;++i){
			scanf("%d",&m);
			event.push_back({m-L,m+L});
		}
		sort(event.begin(),event.end());
		for(auto e:event){
			if(range.empty() or range.back().second<e.first){
				range.push_back(e);
			}else{
				range.back().second=max(range.back().second , e.second);
			}
		}
		for(auto r:range){
			//printf("[%d,%d] ",r.first,r.second);
			int i=upper_bound(r.first);
			int j=lower_bound(r.second);
			//printf("(%d,%d) ",i,j);
			if(j>=i and arr_n[i]>=r.first and arr_n[j]<=r.second) ans+=max(0,j-i+1);
		}
		printf("%d\n",ans);
	}
	
}
