#include<bits/stdc++.h>
using namespace std;
int memo[1002][1002];
bool visited[1002][1002];
int main(){
	int n;
	scanf("%d",&n);
	char arr[n];
	for(int i=0;i<n;++i) cin >> arr[i];
	for(int r=0;r<n;++r){
		for(int l=r-1;l>=0;--l){
			if(r-l==1){
				if(arr[r]==arr[l]) memo[l][r]=1;
			}else{
				for(int k=r-1;k>=l;--k){
					if(arr[k]==arr[r]){
						memo[l][r]=max(memo[l][r],1+memo[k+1][r-1]+memo[l][k-1]);
					}
				}
				memo[l][r]=max(memo[l][r],memo[l+1][r]);
				memo[l][r]=max(memo[l][r],memo[l][r-1]);
			}
		}
	}
	printf("%d",memo[0][n-1]);
}
