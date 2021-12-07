#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	for(int t=1;t<=20;++t){
		scanf("%d%d",&m,&n);
		int y=(m/2)-n;
		if(m%2==1 or y<0 or n-y+1<=0){
			printf("0\n");
		}else{
			printf("%d\n",n-y+1);
		}
	}
}
