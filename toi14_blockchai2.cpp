#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int main(){
	map <vector<pii>,int> D;
	vector<pii>vec;
	int t,q;
	cin >> t >> q;
	int n,u,v;
	while(t--){
		cin >> n;
		for(int i=1;i<n;++i){
			cin>>u>>v;
			vec.push_back({min(u,v),max(u,v)});
		}
		sort(vec.begin(),vec.end());
		++D[vec];
		vec.clear();
	}
	while(q--){
		cin >> n;
		for(int i=1;i<n;++i){
			cin>>u>>v;
			vec.push_back({min(u,v),max(u,v)});
		}
		sort(vec.begin(),vec.end());
		cout << D[vec]<<endl;
		vec.clear();
	}
	
}
