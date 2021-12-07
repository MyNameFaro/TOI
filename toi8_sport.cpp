#include<bits/stdc++.h>
using namespace std;

vector <char> v;
int solve(int k,int a,int b)
{
	if(a >= k or b >= k)
	{
		for(auto c:v)
		{
			cout << c << " " ;
		}
		cout << endl;
		return 0;
	}
	v.push_back('W');
	solve(k ,a+1,b);
	v.pop_back();
	v.push_back('L');
	solve(k ,a,b+1);
	v.pop_back();
}
int main(){
	int k,a,b;
	scanf("%d%d%d",&k,&a,&b);
	solve(k , a , b);
}
