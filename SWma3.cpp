#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int N;
vector<pair<int,int>> vec;
vector<int> Count;
bool compare(pair<int,int> A,pair<int,int> B)
{
    return A.first>B.second&&A.first<B.second;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cin>>N;
vec.resize(N+1);
Count.resize(N+1);
for(int i=1;i<=N;i++)
{cin>>vec[i].first>>vec[i].second;}
for(int i=1;i<=N;i++)
{
    for(int j=1;j<=N;j++)
    {
        if(i!=j&&vec[j].first<vec[i].first&&vec[j].second>vec[i].first)
            Count[i]++;
    }
}
for(int i=1;i<=N;i++)
    cout<<Count[i]<<endl;
return 0;
}