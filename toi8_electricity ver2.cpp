#include<bits/stdc++.h>
using namespace std;
int DP[500005] ,cost[500005];
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	deque <int> deq;
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&cost[i]);
	}
	DP[1]=cost[1];
	deq.push_back(1);
	for(int i=2;i<=N;++i)
	{
		while(!deq.empty() and deq.front() < i-K)
		{
			deq.pop_front();
		}
		DP[i] = cost[i] + DP[deq.front()];
		while(!deq.empty() and DP[deq.back()] > DP[i]){
			deq.pop_back();
		}
		//cout << DP[i] << endl;
		deq.push_back(i);
	}
	printf("%d",DP[N]);
}
