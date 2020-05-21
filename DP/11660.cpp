#include<iostream>
using namespace std;
#define FOR(i,end,start) for(int i=start;i<=end;i++)
int DP[1024];
int N,M;
int main()
{ ios_base::sync_with_stdio(false); cin.tie(NULL);
cin>>N>>M;
FOR(i,N*N,1) cin>>DP[i];
FOR(i,N*N,1)
{
 int temp=i%N!=0?i%N:N;
 int X=(i/N-1)*N+temp>0?(i/N-1)*N+temp:0;
 int Y=(i/N-1)*N+temp-1>0?(i/N-1)*N+temp-1:0;
 DP[i]=DP[X]+DP[(i/N)*N+temp-1]-DP[Y];
}
FOR(i,M,1)
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
 //   cout<<DP[(a-1)*N+b][(c-1)*N+d]<<endl;
}
return 0;
}