#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,K;
    scanf("%d%d",&N,&K);
    char str[110][110];
    for(int i=1;i<=N;++i)
    {
        scanf("%s",str[i]);
    }
    int ans=0;
    while(true)
    {
        bool check=true;
        for(int i=1;i<=N;++i)
        {
            if(str[i][ans % strlen(str[i])] - '0' != K)
            {
                check=false;
                break;
            }
        }
        if(check and ans)
        {
            printf("%d",ans);
            return 0;
        }
        ++ans;
    }
}
