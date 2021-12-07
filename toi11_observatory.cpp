#include<bits/stdc++.h>
using namespace std;
int il[2002][2002],ir[2002][2002],y[2002][2002],x[2002][2002];
int main(){
	int n,m,k,xx;
	int ans=-2e9,t1=0,t2=0,tt=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&xx);
			if(j<=i) t1+=xx;
			if(j>k-i and j<=k) t2+=xx;
			x[i][j]=xx+x[i][j-1];
			y[i][j]=xx+y[i-1][j];
			il[i][j]=xx+il[i-1][j+1];
			ir[i][j]=xx+ir[i-1][j-1];
		}
	}
	for(int i=k+1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&xx);
			x[i][j]=xx+x[i][j-1];
			y[i][j]=xx+y[i-1][j];
			il[i][j]=xx+il[i-1][j+1];
			ir[i][j]=xx+ir[i-1][j-1];
		}
	}
	tt=t1;
	for(int i=k;i<=n;++i){
		for(int j=k;j<=m;++j){
			if(i>k and j==k){
				t1-=(ir[i-1][k]-ir[i-k-1][0]);
				t1+=(x[i][k]-x[i][0]);
				tt=t1;
			}
			if(j>k){
				tt+=ir[i][j]-ir[i-k][j-k];
				tt-=y[i][j-k]-y[i-k][j-k];
			}
			ans=max(ans,tt);
		}
	}
	tt=t2;
	for(int i=k;i<=n;++i){
		for(int j=k;j<=m;++j){
			if(i>k and j==k){
				t2-=(il[i-1][1]-il[i-k-1][k+1]);
				t2+=(x[i][k]-x[i][0]);
				tt=t2;
			}
			if(j>k){
				tt-=il[i][j-k]-il[i-k][j];
				tt+=y[i][j]-y[i-k][j];
			}
			//printf("%d ",tt);
			ans=max(ans,tt);
		}
		//printf("\n");
	}
	cout << ans;
}
