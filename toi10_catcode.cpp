#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int P=1e9+7;
int main(){
	unordered_map<lli,int> cat; //MEMS CAT HASH
	int k,m;
	scanf("%d%d",&k,&m);
	char c[m+1];
	lli hash=0;
	for(int i=1;i<=k;++i){
		hash=0;
		scanf("%s",c);
		for(int i=0;i<m;++i){
			hash*=P;
			hash+=c[i];
		}
		cat[hash]=i;
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		hash=0;
		scanf("%d",&n);
		char s[n+1];
		scanf("%s",s);
		lli SP=1;
		if(n<m){
			printf("OK");
			continue;
		}
		for(int i=0;i<m;++i){
			hash*=P;
			hash+=s[i];
			if(i>0) SP*=P;
		}
		bool found=false;
		set<int>ans;
		for(int i=m-1;i<n;++i){
			if(i>m-1){
				hash-=(s[i-m]*SP);
				hash*=P;
				hash+=s[i];
			}
			if(cat.count(hash)>0){
				found=true;
				ans.insert(cat[hash]);
			}
		}
		if(!found){
			printf("OK");
		}else{
			for(auto a:ans) cout << a << " ";
		} 
		printf("\n");
	}
}
