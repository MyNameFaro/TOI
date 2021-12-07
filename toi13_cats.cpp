#include<bits/stdc++.h>
using namespace std;
using lli=long long;
int main(){
	int N;
	scanf("%d",&N);
	lli arr[2000010];
	for(int i=0;i<N;++i) scanf("%lld",&arr[i]);
	priority_queue <lli> PQ;
	for(int i=0;i<N;++i){
		if((i<0 or arr[i]!=arr[i-1]) and (i>=N or arr[i]!=arr[i+1])) PQ.push(arr[i]);
	}
	if(PQ.empty()){
		printf("0");
		return 0;
	}
	if(PQ.size()>2) PQ.pop();PQ.pop();
	if(PQ.empty()){
		printf("0");
		return 0;
	}
	printf("%lld",PQ.top());
}
