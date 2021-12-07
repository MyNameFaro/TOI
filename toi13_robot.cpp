#include<bits/stdc++.h>
using namespace std;
using tll=tuple<int,int,int>;
int di[]={1,0,-1,0};
int dj[]={0,1,0,-1};
int arr[2002][2002];
bool visited[2002][2002];
int main(){
	int ans1=0,ans2=0;
	int R,C;
	scanf("%d%d",&R,&C);
	queue <tll> Q;
	int cntA=0;
	for(int i=1;i<=R;++i){
		for(int j=1;j<=C;++j){
			char c;
			cin >> c;
			if(c=='X'){
				Q.emplace(0,i,j);
				visited[i][j]=true;
			}else if(c=='A'){
				arr[i][j]=1;
				++cntA;
			}else if(c=='W'){
				arr[i][j]=-1;
			}
		}
	}
	while(!Q.empty() and (ans1<cntA)){
		int dis=get<0>(Q.front());
		int r=get<1>(Q.front());
		int c=get<2>(Q.front());Q.pop();
		if(arr[r][c]==1){
			++ans1;
			ans2+=dis;
		}
		for(int i=0;i<4;++i){
			int rr=r+di[i];
			int cc=c+dj[i];
			if(rr<=0 or cc<=0 or rr>R or cc>C or arr[rr][cc]==-1) continue;
			if(!visited[rr][cc]){
				visited[rr][cc]=true;
				Q.emplace(dis+1,rr,cc);
			}
		}
	}
	printf("%d %d",ans1,ans2*2);
}
