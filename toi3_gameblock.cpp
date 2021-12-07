#include<bits/stdc++.h>
using namespace std;
int N , M;
int arr[7][7];
int total;
bool gravity(){
	int rr,cc,nr,nc;
	bool ans=false;
	for(int i=N-2;i>=0;--i){
		for(int j=0;j<M;++j){
			if(arr[i][j]<=0) continue;
			rr=i;cc=j;
			nr = rr+1;nc=cc;
			while(arr[nr][nc]==0 && nr<N){
				ans=true;
				swap(arr[nr][nc] , arr[rr][cc]);
				rr=nr;
				nr = nr+1;
			}
		}
	}
	return ans;
}
int bfs(int r,int c,int val){
	queue <pair<int,int>>Q;
	Q.push({r,c});
	int ans=0;
	while(!Q.empty()){
		r=Q.front().first;
		c=Q.front().second;Q.pop();
		int nr,nc;
		nr=r;nc=c-1;
		if(nc>=0 and arr[nr][nc]==val){
			arr[nr][nc]=0;
			++ans;
			Q.push({nr,nc});
		}
		nr=r;nc=c+1;
		if(nc<M and arr[nr][nc]==val){
			arr[nr][nc]=0;
			++ans;
			Q.push({nr,nc});
		}
		nr=r-1;nc=c;
		if(nr>=0 and arr[nr][nc]==val){
			arr[nr][nc]=0;
			++ans;
			Q.push({nr,nc});
		}
		nr=r+1;nc=c;
		if(nr<N and arr[nr][nc]==val){
			arr[nr][nc]=0;
			++ans;
			Q.push({nr,nc});
		}
	}
	return ans;
}
bool dlt(){
		int nr,nc,r,c;
		bool ans=false;
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				if(arr[i][j]<=0)continue;
				int cnt = bfs(i,j,arr[i][j]);
				if(cnt>0){
					total=total+(5*(cnt));
				} 
			}
		}
		return ans;
}
void print(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(arr[i][j]==-1){
				printf("# ");
			}else if(arr[i][j]==0){
				printf("- ");
			}else{
				printf("%c ",arr[i][j] - 1 + 'A');
			}
		}
		printf("\n");
	}
}
int main(){
	scanf("%d %d",&N ,&M);
	char ch;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin >> ch;
			if(ch=='#'){
				arr[i][j] = -1;
			}else if(ch=='-'){
				arr[i][j]=0;
			}else{
				arr[i][j]=ch-'A'+1;
			}
 		}
	}
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int r , c;
		int rr,cc;
		scanf("%d %d",&r,&c);
		cin >> ch;
		int nr , nc;
		if(ch=='L'){
			nr=r;nc=c-1;
		}else if(ch=='R'){
			nr=r;nc=c+1;
		}
		if(nr < 0 or nr >= N or nc < 0 or nc >= M or arr[nr][nc]!=0 or arr[r][c]<=0){
			total-=5;
		}else{
			swap(arr[nr][nc] , arr[r][c]);	
		}
		dlt();
		while(gravity()){
			dlt();
		}
	}
	printf("%d\n",total);
	print();
}
