#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int N,W;
int visit[1<<100+1]; //방문노드명단 // 무게
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
        result=max(result,Bag[i].second+DP[j]);//중복들어가면 안됨
        if(result>Maximum) Maximum=result;
    }
}

return 0;
}