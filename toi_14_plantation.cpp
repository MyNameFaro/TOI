
#include <bits/stdc++.h>
using namespace std;


bool y_axis(pair<double,double> p1 , pair<double,double> p2){
	return p1.second > p2.second;	
}

vector <pair <double , double>> p , stp;

double dis(pair<double,double> p1 , pair<double,double> p2){
	double dx = p1.first - p2.first;    // diff x
  	double dy = p1.second - p2.second;    // diff y
  	return sqrt(dx*dx + dy*dy);
}

double clp(int L , int R){
	int mid = (L + R)/2;
	
	if(R - L < 1) return 2e9;
	if(R - L == 1) return dis(p[L] , p[R]);
	
	double dL = clp(L , mid);
	double dR = clp(mid + 1,R);
	
	double d = min(dL , dR);
	
	int i , j;
	for(i = L;i <= R;i++){
		if(abs(p[i].first - p[mid].first) < d){
			stp.push_back(p[i]);
		}
	}
	sort(stp.begin() , stp.end() ,y_axis);
	
	for(i = 0;i < stp.size();i++){
		for(j = i + 1;j < stp.size();j++){
			if(abs(stp[i].second - stp[j].second) >= d){
				break;
			}
			d = min(dis(stp[i] , stp[j]) , d);
		}
		
	}
	
	stp.clear();
	return d;
}
int main(){
	//cout << dis(5 , 2 , 4 , 3);
	int W;
	int n , R , D;
	double d;
	double x , y;
	int i , j , k;
	//bool check = true;
	scanf("%d",&W);
	for(k = 0;k < W;k++){
		//check = true;
		scanf("%d %d %d",&n ,&R ,&D);
		for(i = 0;i < n;i++){
			scanf("%lf %lf",&x , &y);
			p.push_back({x , y});
		}
		sort(p.begin() , p.end());
		d = clp(0 , n - 1);
		if(d < 1.0 * (2*R + D)){
			printf("N\n");
		}else{
			printf("Y\n");
		}
		p.clear();
	}
}
