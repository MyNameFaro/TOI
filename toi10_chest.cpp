#include<bits/stdc++.h>
using namespace std;
using tii=tuple<int,int,int>;
using pii=pair<int,int>;
using lli=long long;
lli cnt_2,cnt_3,cnt_5,cnt_7;
lli mx,ans1,ans2,l;
void compute(int x,int d){
	if(x==2){
		cnt_2+=d;
	}else if(x==3){
		cnt_3+=d;
	}else if(x==4){
		cnt_2+=d;
		cnt_2+=d;
	}else if(x==5){
		cnt_5+=d;
	}else if(x==6){
		cnt_2+=d;
		cnt_3+=d;
	}else if(x==7){
		cnt_7+=d;
	}else if(x==8){
		cnt_2+=d;
		cnt_2+=d;
		cnt_2+=d;
	}else if(x==9){
		cnt_3+=d;
		cnt_3+=d;
	}else if(x==10){
		cnt_5+=d;
		cnt_2+=d;
	}
	l=(cnt_2+1)*(cnt_5+1)*(cnt_3+1)*(cnt_7+1);
	mx=max(mx,l);
}
int main(){
	int m,n,x,s,t;
	int j,d;
	scanf("%d%d",&m,&n);
	vector <tii> event;
	vector <pii> eventII;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&s,&t);
		event.emplace_back(s,1,x);
		event.emplace_back(t+1,-1,x);
	}
	sort(event.begin(),event.end());
	for(auto e:event){
		int d=get<1>(e);
		x=get<2>(e);
		compute(x,d);
	}
	ans1=mx;
	l=0;
	//cout << ans1<<endl;
	for(auto e:event){
		t=get<0>(e);
		d=get<1>(e);
		if(d==-1 and ans1==l){
			ans2+=t-j;
		}
		x=get<2>(e);
		compute(x,d);
		if(d==1 and ans1==l){
			j=t;
		}
	}
	printf("%lld %lld",ans1,ans2);
}
