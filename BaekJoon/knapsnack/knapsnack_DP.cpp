#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int N,W;
int DP[100][100001];//n번째까지넣은 가방무게
int Maximum=0;
vector<pair<int,int>> Bag;
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);
cin>>N>>W;
Bag.resize(N+1);
for(int i=1;i<=N;i++)
{
cin>>Bag[i].first>>Bag[i].second;
}
for(int i=1;i<=N;i++)
{
    for(int j=1;j<=W;j++)
    {
        DP[i][j]=DP[i-1][j];
        if(j>=Bag[i].first)
        {
            DP[i][j]=max(DP[i][j],Bag[i].second+DP[i-1][j-Bag[i].first]);
        }
    }
}
cout<<DP[N][W];
return 0;
}