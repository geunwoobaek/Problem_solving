#include <iostream>
#include <algorithm>
#include<vector>
#include<math.h>
using namespace std;
int DP[1000001];
int N;
int Map[1000001];

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cin>>N;
for(int i=1;i<=N;i++)
{cin>>Map[i]; DP[i]=-1;}
for(int i=1;i<=N;i++)
{
    for(int j=i;j<=N;j++)
    {
        DP[j]=max(DP[j],max(DP[j]+Map[i],Map[i]));
    }
}
cout<<DP[N];
}