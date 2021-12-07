#include<bits/stdc++.h>
using namespace std;

int w(char c) //weight of operation
{
	if(c=='[' or c==']') return 0;
	return c-'0';
}
int opr(int a,char c,int b)
{
	double sum=(double) (a+b);
	if(c=='1') return sum + (int) (0.04*sum);
	if(c=='2') return sum + (int) (0.08*sum);
	if(c=='3') return sum + (int) (0.16*sum);   
}
int main()
{
	string sfe;//suffix expression
	string cmd; //command input;
	stack <char> S;
	stack <int> SS;
	int ans=0;
	cin >> cmd;
	for(auto t:cmd) //token in cmd
	{
		if(t >= 'A' and t <= 'Z')
		{
			sfe.push_back(t);
		}
		else if(t == '[')
		{
			S.push(t);
		}
		else if(t == ']')
		{
			while(!S.empty() and S.top()!='[')
			{
				sfe.push_back(S.top());
				S.pop();
			}
			if(!S.empty()) S.pop();
		}
		else if(t >='1' and t<='9')
		{
			while(!S.empty() and w(S.top())>=w(t))
			{
				sfe.push_back(S.top());
				S.pop();
			}
			S.push(t);
		}
	}
	while(!S.empty())
	{
		if(S.top() != '[' and S.top() != ']')sfe.push_back(S.top());
		S.pop();
	}
	//cout << sfe << endl;
	//COmpute from postfix expression
	for(auto c : sfe)
	{
		//cout << c ;
		if(c >= 'A' and c <= 'Z')
		{
			SS.push(20);
		}
		else{
			int a=SS.top();SS.pop();
			int b=SS.top();SS.pop();
			int d=opr(a , c , b);
			//cout << d << endl;
			SS.push(d);
		}
	}
	ans = SS.top();
	printf("%d",ans);
}

