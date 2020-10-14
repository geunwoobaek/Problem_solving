#include<iostream>
#include<algorithm>
using namespace std;
int DP[100001];
int N;
int Max=-1000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>DP[i];
        DP[i]=max(DP[i],DP[i-1]+DP[i]);
        Max=Max>DP[i]?Max:DP[i];
    }
    cout<<Max;
    return 0;
}