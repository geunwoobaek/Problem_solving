#include<iostream>
#include<map>
#include<vector>
using namespace std;
int N,command;
int Max=0;
vector<pair<int,int>> parent[101];
pair<int,int> target={1,1};
pair<int,int> FindParent(pair<int,int> A)
{
    if(parent[A.first][A.second]!=make_pair(A.first,A.second))
    {
        FindParent(parent[A.first][A.second]);
    }
    else return A;
}
void Union(pair<int,int> A,pair<int,int> B)
{
    pair<int,int> temp1=FindParent(A);
    pair<int,int> temp2=FindParent(B);
    if(temp1.first*N+temp1.second<temp2.first*N+temp2.second)
    {
        parent[temp2.first][temp2.second]=temp1;
    }
    else {
        parent[temp1.first][temp1.second]=temp2;
        }
}
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>command;
    parent[0].resize(N+1);
    for(int i=1;i<=N;i++)
    {   parent[i].resize(N+1);
        for(int j=1;j<=N;j++)
        {
            parent[i][j]={i,j};
        }
    }
     for(int i=0;i<command;i++)
     {      int a,b,c,d;
            cin>>a>>b>>c>>d;
            Union({a,b},{c,d});
     }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(FindParent({i,j})==target)
            {
                Max++;
            }
        }
    } 
    cout<<Max;
    return 0;
}