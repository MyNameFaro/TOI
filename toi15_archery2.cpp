#include<bits/stdc++.h>
#define cc second
#define pp first
using namespace std;
using lli=long long;
using pii=pair<int,int>;
//const int N=500005;

int main(){
	cout << "HEY";
	int n;
	scanf("%d",&n);
	pii box[500005];
	box[0].pp=0;
	for(int i=1;i<=n;++i) scanf("%d",&box[i].cc);
	for(int i=1;i<=n;++i) scanf("%d",&box[i].pp); 
	sort(box+1,box+1+n);
	
	lli sumc[500005],sump=0;
	sumc[0]=0;
	for(int i=1;i<=n;++i){
		sumc[i]=sumc[i-1]+box[i].cc;
		sump+=box[i].pp;
	}
	lli P=2e18, M=2e18;
	for(int i=1;i<=n;++i){
		if(box[i].pp==box[i-1].pp) continue;
		
		lli a=max(1, 1 + box[i-1].pp);
		lli b=min((lli)((sumc[i-1]+sump)/(lli)n) , (lli)box[i].pp);
		if(a>b) continue;
		lli PP=b;
		lli MM=sumc[i-1]+sump-PP*((lli)n);
		if(MM<M){
			M=MM;
			P=PP;
		}
	} 
	printf("%lld %lld",P,M);
}
