#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
int N,W;
vector<pair<int,int>> bag;
int Maximum=0;
int DP[100][100001];//n번째까지넣은 가방무게
int dfs(int start,int w)
{   if(w>=W||start==N) return 0;
    int &result=DP[start][w];
    if(result!=-1) return result;
    result=0;
    int compare2=0;
    if(w+bag[start].first<=W) compare2=dfs(start+1,w+bag[start].first)+bag[start].second;
    return result=max(dfs(start+1,w),compare2);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N>>W;
bag.resize(N);
memset(DP,-1,sizeof(DP));
for(int i=0;i<N;i++) cin>>bag[i].first>>bag[i].second;
cout<<dfs(0,0);
return 0;
}