#include<iostream>
#include<map>
#include<vector>
using namespace std;
int N,command;
int Max=0;
bool visit[101][101];
int Count=1;
vector<vector<pair<int,int>>> Check[101];
void dfs(int x,int y)
{
    for(int i=0;i<Check[x][y].size();i++)
    {
        pair<int,int> now=Check[x][y][i];
        if(!visit[now.first][now.second])
        {       Count++;
            visit[now.first][now.second]=true;
            dfs(now.first,now.second);
        }
    }
}
int main()
{
visit[1][1]=true;
ios_base::sync_with_stdio(false);
cin>>N>>command;
for(int i=1;i<=N;i++) Check[i].resize(N+1);
for(int i=0;i<command;i++)
{ int a,b,c,d;
cin>>a>>b>>c>>d;
Check[a][b].push_back({c,d});
}
dfs(1,1);
cout<<Count;
return 0;
}