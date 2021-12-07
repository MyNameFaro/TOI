#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector <pair<int,int>> P;
	for(int i=1;i<=n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		P.push_back({x,y});
	}
	sort(P.begin(),P.end());
	
}
