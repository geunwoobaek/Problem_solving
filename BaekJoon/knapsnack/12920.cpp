#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
struct info{
    int weight,value,num;
};
int N,W,t=1,Maximum=0;
int DP[10001][10001];//n번째까지넣은 가방무게
int total=0;
vector<info> Bag;
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);
cin>>N>>W;
Bag.resize(N+1);
for(int i=1;i<=N;i++)
{
cin>>Bag[i].weight>>Bag[i].value>>Bag[i].num;
}
for(int i=1;i<=N;i++)
{
for(int k=1;k<=Bag[i].num;k++)
{
int h=t++;
for(int j=1;j<=W;j++)
{
if(h>k) DP[h][j]=DP[h-k][j];
else DP[h][j]=0;
if(j>=k*Bag[i].weight)
{   
    DP[h][j]=max(DP[h][j],DP[h-k][j-k*Bag[i].weight]+k*Bag[i].value);
    if(Maximum<DP[h][j]) Maximum=DP[h][j];
}
}
}
}
cout<<Maximum;
return 0;
}