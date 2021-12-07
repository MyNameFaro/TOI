#include<bits/stdc++.h>
using namespace std;

int DP[410][410] ,A[410];
int solve(int K){
	int N,NN=0;
	scanf("%d",&N);

	for(int i=0;i<=N;++i)
	{
		for(int j=0;j<=N;++j)
		{
			DP[i][j]=0;
		}
	}
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&A[i]);
	}
	for(int l=N;l>=1;--l)
	{
		DP[l][l]=1;
		for(int r=l+1;r<=N;++r)
		{
		    int mn=r-l+1;
		    DP[l][r]=mn;
            for(int k=l;k<r;++k)
            {
                if(A[k] == A[k+1])
                {
                    mn = min(mn , DP[l][k] + DP[k+1][r] - 1);
                }
                mn = min(mn , DP[l][k] + DP[k+1][r]);
            }

			if(A[l]==A[r] and K>1)
			{
				int i=l+1,j=r-1;
				int cnt=K-2;
				while(A[i] == A[i-1] and cnt>0 and i<r)
				{
					--cnt;
					++i;
				}
				while(A[j] == A[j+1] and cnt>0 and j>l)
				{
					-cnt;
					--j;
				}
				for(int ii=l;ii<=i;++ii)
                {
                    for(int jj=r;jj>=j;--jj)
                    {
                        mn = min(mn , 1 + DP[ii][jj]);
                    }
                }
			}
			DP[l][r]=mn;
		}
	}
	return DP[1][N];
}
int main(){
	int R,K;
	int ans=0;
	scanf("%d%d",&R,&K);
	while(R--){
		ans = max(ans , solve(K));
	}
	printf("%d",ans);
}
