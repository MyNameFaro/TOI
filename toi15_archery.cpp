#include<bits/stdc++.h>
using lli=long long;
using namespace std;
//const int N=500005;
int main(){
	//cout << "HEY";
	int n;
	scanf("%d",&n);
	pair<int,int> box[500005];
	box[0].first=0;
	lli limC=2e18;
	for(int i=1;i<=n;++i){
		scanf("%d",&box[i].second);
		limC=min(limC,(lli) box[i].second);
	} 
	for(int i=1;i<=n;++i) scanf("%d",&box[i].first); 
	sort(box+1,box+1+n);
	
	lli sumc[500005],sump=0;
	sumc[0]=0;
	for(int i=1;i<=n;++i){
		sumc[i]=sumc[i-1]+box[i].second;
		sump+=box[i].first;
	}
	lli P=2e18, M=2e18;
	for(int i=1;i<=n;++i){
		if(box[i].first==box[i-1].first) continue;
		
		lli a=max(1, 1 + box[i-1].first);
		lli b=min((lli)((sumc[i-1]+sump)/(lli)n) , (lli)box[i].first);
		if(a>b) continue;
		lli PP=b;
		if(PP>limC) break;
		lli MM=sumc[i-1]+sump-PP*((lli)n);
		if(MM<M){
			M=MM;
			P=PP;
		}
	} 
	printf("%lld %lld",P,M);
}

