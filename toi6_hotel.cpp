#include <bits/stdc++.h>
using namespace std;

long long table[1000002];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		table[i]=min(table[i-1]+500 , table[max(i-2,0)]+800);
		for(int j=3;j<=5;++j)
		{
			table[i]=min(table[i] , table[max(i-j,0)]+1500);
		}
		for(int j=6;j<=15;++j)
		{
			table[i]=min(table[i] , table[max(i-j,0)]+3000);
		}
	}
	printf("%lld",table[n]);
}
