#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
pii rule[2010][2010]; //row,time
bool visited[2010][4010];
int dis[2010][4010];
int main(){
	int R,C;
	scanf("%d%d",&R,&C);
	//
	int T[2003]; //period
	T[0]=T[R+1]=1;
	rule[0][0]=make_pair(0,C);
	rule[R+1][0]=make_pair(0,C);
	for(int i=1;i<=R;++i){
		int l,r,dl,dr;
		char c;
		cin >> l;
		cin >> c;
		if(c=='L'){
			dl=-1;
		}else{
			dl=1;
		}
		cin >> r;
		cin >> c;
		if(c=='L'){
			dr=-1;
		}else{
			dr=1;
		}
		
		int t=0;
		for(int round=0;round<2*C;++round){
			rule[i][t]=make_pair(l,r);
			if(r-l==1 and dl==1 and dr==-1){
				dl=-1;
				dr=1;
			}else{
				if(l==r and dl==1 and dr==-1){
					dl*=-1;
					dr*=-1;
				}else{
					if(l==0){
						dl=1;
					}else if(l==C){
						dl=-1;
					}
					if(r==0){
						dr=1;
					}else if(r==C){
						dr=-1;
					}
				}
				
				
				r+=dr;
				l+=dl;
			}
			++t;
		}
		T[i]=t;
	}
	/*for(int r=0;r<=R+1;++r){
		for(int j=0;j<T[r];++j){
			printf("(%d , %d) ",rule[r][j].first,rule[r][j].second);
		}
		printf("\n");
	}*/
	int ans=2e9;
	for(int c=1;c<C;++c){
		
		for(int i=0;i<=R+1;++i){
			for(int j=0;j<=2*C+1;++j){
				visited[i][j]=false;
				dis[i][j]=2e9;
			}
		}
		priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> PQ;
		dis[0][0]=0;
		PQ.push({dis[0][0] ,{0,0}});
		
		while(!PQ.empty()){
			int r=PQ.top().second.first;
			int s=PQ.top().second.second;PQ.pop();
			int t=dis[r][s];
			if(visited[r][s]) continue;
			visited[r][s]=true;
			//cout << dis[r][s] << " R : " << r  << " S : "<< s << endl;
			if(r>R){
				ans=min(ans,t);
				//cout << t << endl;
				break;
			}
			
			pii now=rule[r][(t+1)%T[r]];
			pii next=rule[r+1][(t+1)%T[r+1]];
			//if(r==5) cout << next.first << " " <<next.second << endl;
			//cout << now.first << " " << now.second << endl;
			if(!visited[r+1][0] and next.first < c and c < next.second and dis[r+1][0]>dis[r][s]+1){
				dis[r+1][0]=dis[r][s]+1;
				PQ.push({dis[r+1][0],{r+1,0}});
			}
			//cout << (s+1<(2*C)) << (!visited[r][s+1]) << (now.first <= c << c <= now.second) << (dis[r][s+1]>dis[r][s]+1) << endl;
			else if(s<(2*C) and !visited[r][s+1] and now.first < c and c < now.second and dis[r][s+1]>dis[r][s]+1){
				dis[r][s+1]=dis[r][s]+1;
				PQ.push({dis[r][s+1],{r,s+1}});
			}
		}
	}
	printf("%d",ans);
}

