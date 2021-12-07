#include<bits/stdc++.h>
using namespace std;
int opr(char m,int a,int b){
	if(m=='1') return (int)(0.04 * (double)(a+b))+a+b;
	if(m=='2') return (int)(0.08 * (double)(a+b))+a+b;
	return (int)(0.16 * (double)(a+b))+a+b;
}
int level(char t){
	if('0'<=t and t<='9') return t-'0';
	return 0;
}
int main(){
	//cout << opr('3',20,20);
	string T,post;
	cin>>T;
	stack <char> s;
	for(auto t:T){
		if(('0'<=t and t<='9') or(t=='[')or t==']'){
			if(t=='['){
				s.push(t);
				continue;
			}else if(t==']'){
				while(!s.empty() and s.top()!='['){
					post.push_back(s.top());
					s.pop();
				}
				s.pop();
				continue;
			}
			while(!s.empty() and level(s.top())>=level(t)){
				if('0'<=t and t<='9') post.push_back(s.top());
				s.pop();
			}
			s.push(t);
			
		}else{
			post.push_back(t);
		}
	}
	while(!s.empty()){
		if('0'<=s.top() and s.top()<='9') post.push_back(s.top());
		s.pop();
	}
	stack <int> com;
	//cout << post << endl;
	for(auto t:post){
		if('A'<=t and t<='Z'){
			com.push(20);
		}else{
			int b=com.top();com.pop();
			int a=com.top();com.pop();
			int result=opr(t,a,b);
			com.push(result);
		}
	}
	printf("%d",com.top());
}
