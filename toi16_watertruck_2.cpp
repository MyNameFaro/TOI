#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

const int NN=5e4+10;

bool visited[NN];
vector <pii> G[NN];
int sum_w , ans;

int dfs(int u,int p)
{
    int r;
    for(auto vw:G[u])
    {
        int v=vw.first;
        int w=vw.second;
        if(v == p) continue;
        if(!visited[v]){
            visited[v]=true;
            r=dfs(v , u);
            if(r > -1)
            {
                sum_w -= w;
                ans += w;
                if(r == u) return -1;
                return r;
            }
        }else{
            sum_w -= w;
            ans += w;
            return v;
        }
    }
    return -1;
}
int main()
{

    int N,M;
    int t=0;
    scanf("%d%d",&M,&N);
    while(M--)
    {
        int u,v,w;
        scanf("%d%d%d",&u ,&v,&w);
        G[v].push_back({u , w});
        G[u].push_back({v , w});
        sum_w += w;
    }
    visited[0]=true;
    dfs(0 , -1);
    ans += (sum_w) * 2;
    printf("%d",ans);
}
/*
9 9
5 1 6
5 4 4
1 2 4
2 4 3
5 3 2
3 0 1
3 6 7
6 8 6
6 7 5
*/
