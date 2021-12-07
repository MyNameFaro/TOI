#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int lis[n+2];
	for(int i=0;i<=n+1;++i) lis[i]=2e9;
	int size=0;
	for(int i=0;i<n;++i){
		int x;
		scanf("%d",&x);
		int j=upper_bound(lis,lis+n+1,x)-lis;
		lis[j]=x;
		size=max(size,j);
	}
	//for(int i=0;i<n;++i) printf("%d ",lis[i]);
	printf("%d",n-size-1);
	
}
