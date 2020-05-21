#include<iostream>
#include<math.h>
using namespace std;
int visit[261445];
int change (int k)
{
	int answer=0;
	int N=9;
	while(N>0)
	{
		k/pow(10,N);
        k/=10; N--;
		if(k>0)
			answer+=pow(4,N);
        cout<<"";
	}
	return answer;
}
int main()
{
int k=412342313;
cout<<change(k);

return 0;
}