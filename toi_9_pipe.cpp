#include<bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int,int>;
int arr[302][302];
int solve(int n,int m,int i,int j,int k){
	queue <tll> Q;
	Q.emplace(0,i,j,k);
	int ans=0;
	while(!Q.empty()){
		int d=get<0>(Q.front());
		int r=get<1>(Q.front());
		int c=get<2>(Q.front());
		int t=get<3>(Q.front());Q.pop();
		if(r<0 or r>=n or c<0 or c>=m){
			ans=max(ans,d);
			continue;
		} 
		if(t==0){
			if(arr[r][c]==11){
				arr[r][c]=0;
				Q.emplace(d+1, r-1,c,3);
			}else if(arr[r][c]==13){
				arr[r][c]=0;
				Q.emplace(d+1, r+1,c,1);
			}else if(arr[r][c]==22){
				arr[r][c]=0;
				Q.emplace(d+1, r,c+1,0);
			}else if(arr[r][c]==31){
				arr[r][c]=21;
				Q.emplace(d+1, r,c+1,0);
			}
		}else if(t==1){
			if(arr[r][c]==11){
				arr[r][c]=0;
				Q.emplace(d+1, r,c-1,2);
			}else if(arr[r][c]==12){
				arr[r][c]=0;
				Q.emplace(d+1, r,c+1,0);
			}else if(arr[r][c]==21){
				arr[r][c]=0;
				Q.emplace(d+1, r+1,c,1);
			}else if(arr[r][c]==31){
				arr[r][c]=22;
				Q.emplace(d+1, r+1,c,1);
			}
		}if(t==2){
			if(arr[r][c]==12){
				arr[r][c]=0;
				Q.emplace(d+1, r-1,c,3);
			}else if(arr[r][c]==14){
				arr[r][c]=0;
				Q.emplace(d+1, r+1,c,1);
			}else if(arr[r][c]==22){
				arr[r][c]=0;
				Q.emplace(d+1, r,c-1,2);
			}else if(arr[r][c]==31){
				arr[r][c]=21;
				Q.emplace(d+1, r,c-1,2);
			}
		}else if(t==3){
			if(arr[r][c]==13){
				arr[r][c]=0;
				Q.emplace(d+1, r,c-1,2);
			}else if(arr[r][c]==14){
				arr[r][c]=0;
				Q.emplace(d+1, r,c+1,0);
			}else if(arr[r][c]==21){
				arr[r][c]=0;
				Q.emplace(d+1, r-1,c,3);
			}else if(arr[r][c]==31){
				arr[r][c]=22;
				Q.emplace(d+1, r-1,c,3);
			}
		}
	}
	return ans;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector <int> ans;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) scanf("%d",&arr[i][j]);
	}
	for(int i=0;i<n;++i){
		if(arr[i][0]==11 or arr[i][0]==13 or arr[i][0]==22 or arr[i][0]==31){
			ans.push_back(solve(n,m,i ,0,0));
		}
	}
	for(int i=0;i<n;++i){
		if(arr[i][m-1]==12 or arr[i][m-1]==14 or arr[i][m-1]==22 or arr[i][m-1]==31){
			ans.push_back(solve(n,m,i ,m-1,2));
		}
	}
	for(int j=0;j<m;++j){
		if(arr[0][j]==11 or arr[0][j]==12 or arr[0][j]==21 or arr[0][j]==31){
			ans.push_back(solve(n,m,0 ,j,1));
		}
	}
	for(int j=0;j<m;++j){
		if(arr[n-1][j]==13 or arr[n-1][j]==14 or arr[n-1][j]==21 or arr[n-1][j]==31){
			ans.push_back(solve(n,m,n-1 ,j,3));
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();++i) printf("%d ",ans[i]);
}
