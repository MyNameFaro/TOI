#include <bits/stdc++.h>
using namespace std;

const int N=7400000;
bool tab[N];
int main(){
	int n;
	scanf("%d",&n);
	int ans=-1;
	for(int i=2;i<N;++i){
		if(tab[i]) continue;
		tab[i]=true;
		ans=i;
		n--;
		if(!n) break;
		for(int j=2*i;j<N;j+=i){
			tab[j]=true;
		}
	}
	printf("%d",ans);
}
