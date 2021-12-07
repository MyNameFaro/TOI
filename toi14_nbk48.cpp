#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
using pii=pair<int,int>;
int st[200010];
int main(){
	int N,Q;
	scanf("%d%d",&N,&Q);
	pii arr[N+1];arr[0].F=0;
	for(int i=1;i<=N;++i){
		scanf("%d",&arr[i].F);
		arr[i].F+=arr[i-1].F;
		arr[i].S=i;
	}
	sort(arr+1,arr+N+1);
	//Construct Segment Tree
	for(int i=1;i<=N;++i){
		st[i+N-1]=arr[i].second;
	}
	for(int i=N-1;i>=1;--i){
		st[i]=max(st[2*i],st[2*i + 1]);
	}
	while(Q--){
		int find;
		scanf("%d",&find);
		if(find<arr[1].F){
			printf("0\n");
			continue;
		}
		int l=1,r=N;
		int point;
		while(l<=r){
			int mid=(l+r)/2;
			if(arr[mid].F<=find and (mid==N or arr[mid+1].F>find)){
				point=mid;
				break;
			}
			if(arr[mid].F<=find){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		int ans=-2e9;
		int a=N,b=point+N-1;
		while(a<=b){
			if(a%2==1) ans=max(ans,st[a++]);
			if(b%2==0) ans=max(ans,st[b--]);
			a/=2;b/=2;
		}
		printf("%d\n",ans);
	}
}
