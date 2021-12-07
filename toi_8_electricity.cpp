#include<bits/stdc++.h>
using namespace std;
int seg[1000000],table[1000000];
int query(int a,int b,int n){
    a+=n-1;
    b+=n-1;
    int mn=2e9;
    while(a<=b){
        if(a%2==1) mn=min(mn,seg[a++]); 
        if(b%2==0) mn=min(mn,seg[b--]);
        a/=2;
        b/=2;
    }
    return mn;
}
int add(int a,int b,int n){
    a+=n-1;
    seg[a]=b;
    a=a/2;
    while(a>0){
        if(seg[a]<=b){
            break;
        }else{
            seg[a]=b;
        }
        a=a/2;
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int p[n+1];
    for(int i=1;i<2*n;++i){
        seg[i]=2e9;
        table[i]=2e9;
    }
    for(int i=1;i<=n;++i) scanf("%d",&p[i]);
    table[1]=p[1];
    add(1,table[1],n);
    for(int i=2;i<=n;++i){
        table[i]=p[i]+query(max(1,i-k),i-1,n);
        add(i,table[i],n);
    }
    printf("%d",table[n]);
}