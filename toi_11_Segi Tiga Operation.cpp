#include <bits/stdc++.h>
using namespace std;

int opr(int x,int y){
		if(x==0 && y==0){
			return 2;
		}else if(x==0 && y==1){
			return 1;
		}else if(x==0 && y==2){
			return 0;
		}else if(x==1 && y==0){
			return 2;
		}else if(x==1 && y==1){
			return 1;
		}else if(x==1 && y==2){
			return 1;
		}else if(x==2 && y==0){
			return 1;
		}else if(x==2 && y==1){
			return 2;
		}else if(x==2 && y==2){
			return 1;
		}
}

bool memo[255][255][3];
bool visited[255][255][3];
string S;

bool solve(int l , int r , int s){
	if(!visited[l][r][s]){
		visited[l][r][s] = true;
		if(l == r){
			if(S[r] - '0' == s) memo[l][r][s] = true;
			if(S[r] - '0' != s) memo[l][r][s] = false;
		}else if(r - l == 1){
			if(opr(S[l] - '0' , S[r] - '0') == s) memo[l][r][s] = true;
			if(opr(S[l] - '0' , S[r] - '0') != s) memo[l][r][s] = false;
		}else{
			if(s == 0){
				memo[l][r][s] = false;
				for(int x = l;x < r;++x) memo[l][r][s] = memo[l][r][s] || (solve(l , x , 0) && solve(x + 1 , r , 2));
			}else if(s == 1){
				memo[l][r][s] = false;
				for(int x = l;x < r;++x){
					memo[l][r][s] = memo[l][r][s] || (solve(l , x , 0) && solve(x + 1 , r , 1));
					memo[l][r][s] = memo[l][r][s] || (solve(l , x , 1) && solve(x + 1 , r , 1));
					memo[l][r][s] = memo[l][r][s] || (solve(l , x , 1) && solve(x + 1 , r , 2));
					memo[l][r][s] = memo[l][r][s] || (solve(l , x , 2) && solve(x + 1 , r , 0));
					memo[l][r][s] = memo[l][r][s] || (solve(l , x , 2) && solve(x + 1 , r , 2));
				}
			}else{
				memo[l][r][s] = false;
				for(int x = l;x < r;++x){
					memo[l][r][s] = memo[l][r][s] || (solve(l , x , 0) && solve(x + 1 , r , 0));
					memo[l][r][s] = memo[l][r][s] || (solve(l , x , 1) && solve(x + 1 , r , 0));
					memo[l][r][s] = memo[l][r][s] || (solve(l , x , 2) && solve(x + 1 , r , 1));
				}
			}
		}
	}
	return memo[l][r][s];
}

int main(){
	for(int T = 1;T <= 20;++T){
		int N;
		scanf("%d",&N);
		cin >> S;
		for(int r = 0;r < N;++r){
			for(int l = r;l >= 0;--l){
				visited[l][r][0] = false;
				visited[l][r][1] = false;
				visited[l][r][2] = false;
			}
		}
		if(solve(0 , N - 1,0)){
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
}
