#include<bits/stdc++.h>
using namespace std;
int func(){
    int n,m;
    scanf("%d%d",&n,&m);
    int qs[n+1][m+1];
    int t;
    scanf("%d",&t);
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            qs[i][j]=0;
        }
    }
    while(t--){
        int r,c;
        scanf("%d%d",&r,&c);
        qs[r+1][c+1]=1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    for(int ans=min(n,m);ans>=0;--ans){
        for(int i=ans;i<=n;++i){
            for(int j=ans;j<=m;++j){
                int query1=qs[i][j]-qs[i-ans][j]-qs[i][j-ans]+qs[i-ans][j-ans];
                int query2=qs[i-1][j-1]-qs[i-ans+1][j-1]-qs[i-1][j-ans+1]+qs[i-ans+1][j-ans+1];
                if(query1==query2) return ans;
            }
        }
    }
    return 0;
}
int main(){
    
    printf("%d\n",func());
    printf("%d\n",func());
}
