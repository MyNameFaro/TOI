#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
int arr[N],preans[N],ans[N];
int main()
{
	int n ,k ;
	scanf("%d%d",&n ,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&arr[i]);
	}
	int i=1,ans_size=0,new_ans_size=0;
	
	while(i<=n)
	{
		if(arr[i]>arr[i-1] and arr[i]>arr[i+1])
		{
			preans[++ans_size]=arr[i];
			++i;
			//cout << "HEY";
		}
		++i;
	}
	
	sort(preans+1,preans+1+ans_size);
	for(int i=1;i<=ans_size;++i)
	{
		if(preans[i]==preans[i-1]){
			preans[i]=-1;
			continue;
		} 
		++new_ans_size;
		
	}
	if(new_ans_size<k)
	{
		for(i=1;i<=ans_size;++i)
		{
			if(preans[i]==-1) continue;
			printf("%d\n",preans[i]);
		}
	}else
	{
		i=ans_size;
		int new_k=0;
		while(new_k<k)
		{
			if(preans[i]>-1){
				printf("%d\n",preans[i]);
				++new_k;
			}
			--i;
		}
	}
}
