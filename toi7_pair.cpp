#include<bits/stdc++.h>
using namespace std;

double arr[100005];
double seg[3][200006]; //sum of ... , count of

double query(int x,int a,int b,int n=100000)
{
	a+=n;
	b+=n;
	double ans=0;
	while(a<=b)
	{
		if(a%2==1) ans+=seg[x][a++];
		if(b%2==0) ans+=seg[x][b--];
		a/=2;
		b/=2;		
	}
	return ans;
}

int update(int x,int a,int b,int n=100000) //Update segment tree x th the element a th to b value
{
	a+=n;
	seg[x][a]+= (double) b;
	for(int i=a/2;i>=1;i=i/2){
		seg[x][i]=seg[x][2*i]+seg[x][2*i+1];
	}
}
void print()
{
	for(int i=1;i<=30;++i){
		printf("%.0lf ",seg[1][i]);
	}
	printf("\n");
	for(int i=1;i<=30;++i){
		printf("%.0lf ",seg[2][i]);
	}
	printf("\n");
}
int main()
{
	int n;
	double ans=0 ,sum=0;
	scanf("%d",&n);
	
	for(int i=1;i<=n;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		arr[b]=a;
	}
	arr[n+1]=2e9;
	stack <int> S;
	for(int i=n;i>=1;--i)
	{
		double a=query(1,1,(int) arr[i]-1); //sum of the element that lower than arr[i]
		double b=query(2,1,(int)arr[i]-1); //cnt of the element that lower than arr[i]
		//print();
		//cout << arr[i] << " " << a <<" " <<  b << endl;
		ans += (a + arr[i]*b);
		update(1,(int)arr[i],(int)arr[i]);
		update(2,(int)arr[i],1);
	}
	printf("%.0lf",ans);
}
