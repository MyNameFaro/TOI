#include <bits/stdc++.h>
using namespace std;

int dis(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
int main()
{
	int N;
	int P[150][2];
	scanf("%d",&N);
	vector <pair<int,int>> ls; //Line Sweep
	int ans=-2e9;
	for(int i=1;i<=N;++i)
	{
		scanf("%d%d",&P[i][0],&P[i][1]);
	}
	int x;
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
		{
			int d=dis(P[i][0] ,P[i][1] , P[j][0],P[j][1]);
			scanf("%d",&x);	
			if(x)
			{
				ls.push_back({d , 1});
				ls.push_back({2e9 , 0});
			}
			else
			{
				ls.push_back({0,1});
				ls.push_back({d-1 , 0});
			}
		}
	}
	//LINE SWEEP
	int cnt=0;
	sort(ls.begin() , ls.end());
	
	for(int i=0;i<ls.size();++i)
	{
		if(ls[i].second)
		{
			++cnt;
		}else{
			--cnt;
		}
		ans=max(ans,cnt);
	}
	ans = N*N - ans;
	printf("%d",ans);
}
