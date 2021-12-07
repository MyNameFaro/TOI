#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int main(){
	int n;
	lli hashans=0,hash;
	lli PP=1;
	int P=1e9+7;
	scanf("%d",&n);
	string arr;
	cin >> arr;
	for(int i=0;i<n;++i){
		hashans*=P;
		hashans+=arr[i];
		if(i>0) PP*=P;
	}
	hash=hashans;
	for(int i=0;i<n;++i){
		hash-=(arr[i]*PP);
		hash*=P;
		hash+=arr[i];
		if(hash==hashans){
			printf("%d",i+1);
			return 0;
		}
	} 
	
}
