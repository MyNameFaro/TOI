#include<bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int,int>;
int arr[102][4000005];
int main(){
	int n,t;
	vector<tll> v;
	int maxr=0,maxc=0;
	long long int ans=0;
	scanf("%d%d",&n,&t);
	for(int r=1;r<=n;++r){
		int s,h,w,o;
		scanf("%d%d%d%d",&s,&h,&w,&o);
		maxc=max(maxc,s+w);
		maxr=max(maxr,h);
		for(int i=1;i<=h;++i){
			for(int j=s;j<s+w;++j) arr[i][j]+=o;
		}
	}
	for(int i=1;i<=maxr;++i){
		for(int j=1;j<=maxc;++j){
			if(arr[i][j]==t)++ans;
		}
	}
	printf("%lld",ans);
}
