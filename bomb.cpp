#include <bits/stdc++.h>
using namespace std;

bool visited[(1<<14)+1][(1<<14)+1];

void print(int n,int d)
{
	for(int i=d-1;i>=0;--i)
	{
		if(n & (1 << i)){
			printf("1");
		}else{
			printf("0");
		}
	}
}

int main()
{
	int d;
	scanf("%d",&d);
	for(int n=0;n<(1<<d);++n)
	{
		for(int i=0;i<d;++i)
		{
			if(!(n & (1 << i)))
			{
				print(n , d); 
				printf(" ");
				print(n | (1 << i) , d);
				printf("\n");
			}
		}
	}
}
