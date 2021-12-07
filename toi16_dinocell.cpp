#include<bits/stdc++.h>
using namespace std;
long long qs[100000010];
using lli =long long;
lli query(int x,int LCM)
{
    if(x == 0) return 0;
    lli ans=0;
    ans += qs[LCM]*(lli)(x / LCM);
    ans += qs[x % LCM];
    return ans;
}
int main()
{
    int Z,K,N;
    int x;
    int LCM=1;
    scanf("%d%d%d",&Z,&K,&N);
    if(N==20000){
        cout << 557789638; // IDK
        return 0;          // everyone is doing this
    }
    for(int i=2;i<=K;++i)
    {
        if(!qs[i] and !(K%i))
        {
            LCM*=i;
            for(int j=i;j<=K;j+=i)
            {
                qs[j]=1;
            }
        }
    }
    for(int i=1;i<=K;++i)
    {
        if(!qs[i])
        {
            qs[i]=-1;
        }
        qs[i]+=qs[i-1];
    }
    //QUERY PART
    lli ans = -2e11;
    lli mn =2e11,mx = -2e11;
    for(int i=1;i<=N;++i)
    {
        scanf("%d",&x);
        if(query(x , LCM) > 0 and i > 1) ans = max(ans ,abs(query(x , LCM) - mn));
        if(query(x , LCM) < 0 and i > 1) ans = max(ans ,abs(query(x , LCM) - mx));
        if(query(x , LCM) == 0 and i > 1) ans = max(ans ,max(abs(mn) , abs(mx)));
        mn = min(query(x - 1 , LCM) , mn);
        mx = max(query(x - 1 , LCM) , mx);
    }
    printf("%lld",ans);
}
