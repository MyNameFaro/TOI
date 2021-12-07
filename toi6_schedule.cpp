#include <bits/stdc++.h>
using namespace std;
using tll=tuple<int ,int ,int>;
bool ans[500005];

int main()
{
	int n,k,m;
	scanf("%d%d%d",&n ,&k, &m);
	vector <tll> S;
	for(int i=1;i<=n;++i)
	{
		int s, t;
		scanf("%d%d",&s,&t);
		S.emplace_back(s,1,i);
		S.emplace_back(t+1,0,i);
	}
	sort(S.begin(),S.end());
	//LINE SWEEP
	int cnt=0;
	for(int i=0;i<S.size();++i)
	{
		int j=get<1>(S[i]);
		int l=get<2>(S[i]);
		if(j)
		{
			if(cnt < k)
			{
				++cnt;
				ans[l]=true;
			}
		}else{
			if(ans[l])
			{
				--cnt;
			}
		}
	}
	while(m--)
	{
		int q;
		scanf("%d",&q);
		if(ans[q])
		{
			printf("Y ");
		}else{
			printf("N ");
		}
	}	
}
