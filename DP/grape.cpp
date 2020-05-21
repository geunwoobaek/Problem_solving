#include<iostream>
#include<cstring>
using namespace std;

int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int DP[10001];
int N;
int Map[10001];
int solution(int count,int index) //카운트가 0부터 돈다. //count=2까지
{
if(index==N+1) return -1e9; 
int &result=DP[index];

if(count==2) //count가2일떄 
{
//result=(solution(2,solution(0,index+1));
}
else if(count<=1)
{
//result=max(solution(solution(0,index+1),Map[index]+solution(count+1,index+1));
}
return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
    memset(DP,-1,sizeof(DP));
    for(int i=1;i<=N;i++) cin>>Map[i];
    cout<<solution(0,1);
    return 0;
}