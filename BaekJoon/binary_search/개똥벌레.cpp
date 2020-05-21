#include<iostream>
#include<vector>
using namespace std;
int N,H;
vector<int> A(500001),B(500001);
int res=2e9,cnt=0;
int min(int a,int b){if(a==b) cnt++; else if(a>b) cnt=1; return a>=b?b:a;}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N>>H;
int temp;
for(int i=1;i<=N;i++)
{
    cin>>temp;
    if(i%2==1) A[temp]++;
    else B[temp]++;
}
for(int i=H-1;i>0;i--)
{
    A[i]=A[i]+A[i+1];
    B[i]=B[i]+B[i+1];
}
for(int i=1;i<=H;i++)
{  
    res=min(res,A[i]+B[H+1-i]);
}
printf("%d %d\n", res, cnt);
return 0;
}