#include <bits/stdc++.h>
using namespace std;
using lli = long long;
lli table[52][52];
bool dog[52][52];
int main(){
	int N , M;
	scanf("%d %d",&N ,&M);
	int O , r , c;
	scanf("%d",&O);
	while(O--){
		scanf("%d %d",&r ,&c);
		dog[r][c] = true;
	}
	table[1][1] = 1;
	for(int i = 1;i <= N;++i){
		for(int j = 1;j <= M;++j){
			if(dog[i][j]) continue;
			if(i >= 2) table[i][j] += table[i - 1][j];
			if(j >= 2) table[i][j] += table[i][j - 1];
		}
	}
	printf("%lld",table[N][M]);
}
