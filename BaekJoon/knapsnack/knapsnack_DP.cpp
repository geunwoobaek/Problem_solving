#include<iostream>
#include<vector>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int N,W;
int DP[100001];
int Maximum=0;
vector<pair<int,int>> Bag;
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);
cin>>N>>W;
Bag.resize(N);
for(int i=0;i<N;i++)
{
    cin>>Bag[i].first>>Bag[i].second;
}
for(int i=0;i<N;i++)
{
    for(int j=0;Bag[i].first+j<=W;j++)
    {
        int &result=DP[Bag[i].first+j];
        result=max(result,Bag[i].second,DP[j]);
        if(result>Maximum) Maximum=result;
    }
}
cout<<Maximum;
}