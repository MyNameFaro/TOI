#include <bits/stdc++.h>
using namespace std;

int main()
{
	int P;
	scanf("%d",&P);
	int x;
	int PE = P, PO = P; //power of even ,and power of odd;
	int CE = 0, CO = 0; //cnt_Even , cnt_Odd in one period;
	for(int i=1;i<=2*P;++i)
	{
		scanf("%d",&x);
		if(x%2){ //ODD
			CE = 0;
			++CO;
			if(CO >= 3)
			{
				PE-=3;
			}else{
				PE-=1;
			}
		}
		else{ //EVEN
			CO = 0;
			++CE;
			if(CE >= 3)
			{
				PO-=3;
			}else{
				PO-=1;
			}
		}
		if(PE <=0)
		{
			printf("1\n%d",x);
			return 0;
		}else if(PO <= 0)
		{
			printf("0\n%d",x);
			return 0;
		}
	}
}
