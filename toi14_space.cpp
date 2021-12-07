#include<bits/stdc++.h>
using namespace std;
int arr[1002][1002];
int ans1,ans2,ans3;
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
int n,m;
bool check(int a){
	double b= sqrt(a)*1.0;
	if((double) sqrt(a) == b) return true;
	return false;
}
void solve(int i,int j){
	int minr=2e9,maxr=-2e9;
	int minc=2e9,maxc=-2e9;
	arr[i][j]=0;
	int cnt=0;
	queue <pair<int,int>> Q;
	Q.emplace(i,j);
	while(!Q.empty()){
		int r=Q.front().first;
		int c=Q.front().second;Q.pop();
		minr=min(minr,r);
		minc=min(minc,c);
		maxr=max(maxr,r);
		maxc=max(maxc,c);
		++cnt;
		for(int a=0;a<4;++a){
			int rr=r+di[a];
			int cc=c+dj[a];
			if(rr<0 or cc<0 or rr>=n or cc>=m) continue;
			if(arr[rr][cc]==1){
				arr[rr][cc]=0;
				Q.emplace(rr,cc);
			}
		}
	}
	if(maxr-minr != maxc-minc and check(cnt)){
		++ans3;
	}else if(maxr-minr== maxc-minc){
		if(check(cnt)){
			++ans1;
		}else{
			++ans2;
		}
	}
}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;++i){
		string s;
		cin>>s;
		for(int j=0;j<m;++j){
			if(s[j]=='1') arr[i][j]=1;
		}
	}
	int cnt=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(arr[i][j]==1){
				solve(i,j);
				++cnt;
			} 
		}
	}
	//cout << cnt << " ";
	printf("%d %d %d",ans1,ans2,ans3);
}
