#include<bits/stdc++.h>
using namespace std;
using lli=long long;
using pii=pair<int,long long>;
int main(){
	int n,w;
	scanf("%d%d",&n,&w);
	lli qs[n+1];
	qs[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&qs[i]);
		qs[i]+=qs[i-1];
	}
	deque <pii> deq;
	lli ans1=0;
	int ans2=0;
	deq.push_back({0,0});
	for(int i=1;i<=w;++i){
		if(qs[i]-deq.front().second>ans1){
			ans1=qs[i]-deq.front().second;
			ans2=i-deq.front().first;
		}else if(qs[i]-deq.front().second==ans1){
			ans2=min(ans2,i-deq.front().first);
		}
		while(!deq.empty() and deq.back().second>qs[i]){
			deq.pop_back();
		}
		deq.push_back({i,qs[i]});
	}
	for(int i=w+1;i<=n;++i){
		while(!deq.empty() and deq.front().first<i-w){
			deq.pop_front();
		}
		if(qs[i]-deq.front().second>ans1){
			ans1=qs[i]-deq.front().second;
			ans2=i-deq.front().first;
		}else if(qs[i]-deq.front().second==ans1){
			ans2=min(ans2,i-deq.front().first);
		}
		while(!deq.empty() and deq.back().second>qs[i]){
			deq.pop_back();
		}
		deq.push_back({i,qs[i]});
	}
	printf("%lld\n%d",ans1,ans2);
}
