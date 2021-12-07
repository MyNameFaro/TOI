#include <bits/stdc++.h>
using namespace std;
using lli=long long;

int main()
{
	vector <char> ANS;
	for(int r=1;r<=5;++r)
	{
		int n;
		scanf("%d",&n);
		vector <pair<int,int>> T1,T2;
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d%d",&u ,&v);
			T1.push_back({min(u,v),max(u,v)});
		}
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d%d",&u ,&v);
			T2.push_back({min(u,v),max(u,v)});
		}
		sort(T1.begin(),T1.end());
		sort(T2.begin(),T2.end());
		bool ans=true;
		for(int i=0;i<T1.size();++i)
		{
			if(T1[i]!=T2[i]) 
			{
				ans=false;
				break;
			}
		}
		if(ans)
		{
			ANS.push_back('Y');
		}else{
			ANS.push_back('N');
		}
	}
	for(int i=0;i<ANS.size();++i)
	{
		cout << ANS[i];
	}
}
