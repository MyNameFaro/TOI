#include<bits/stdc++.h>
using namespace std;
bool check(int n){
	int a = n%10;
	int b=(n/10)%10;
	int c=(n/100)%10;
	int d=(n/1000)%10;
	if(a==b or a==c or a==d or b==c or b==d or c==d) return false;
	if(a>6 or b>6 or c>6 or d>6) return false;
	return true;
}
int main(){
	int ans=0;
	for(int i=3000;i<=5000;++i){
		if(i%2==1 and check(i)){
			++ans;
			cout << i << endl;
		}
	}
	cout << ans;
}
