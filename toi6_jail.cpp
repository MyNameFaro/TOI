#include<bits/stdc++.h>
using namespace std;
int ans[1000005];

int main()
{
	int n,m;

	scanf("%d%d",&n,&m);
	deque <int> deq;
	for(int i=1;i<=n;++i)
	{
		deq.push_back(i);
	}
	int cnt=1 ,id=0;
	while(!deq.empty())
	{
		if(cnt==m)
		{
			ans[++id]=deq.front();
			cnt=0;
		}
		else{
			deq.push_back(deq.front());
			
		}
		deq.pop_front();
		++cnt;
	}
	for(int i=1;i<=n;++i)
	{
		printf("%d ",ans[i]);
	}
}
