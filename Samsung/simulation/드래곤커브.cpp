#include<iostream>
#include<vector>
#include <cstring>
#define FOR(i,end,start) for(int i=start;i<end;i++)
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int Count=0;
bool Map[101][101];
bool cache[101][101];
vector<vector<pair<int,int>>> state;
int N;
void rotate(int n,vector<pair<int,int>> &info ) //기준을 중심으로 -y,x로 변경
{   //첫번째에는 y 두번째값은 x
    memset(cache,false,sizeof(cache));
    FOR(j,n,0)
    {
    pair<int,int> standard=info.back();
    int size=info.size()-1;
    for(int i=size;i>=0;i--)
    {   pair<int,int> pos=info[i];
        cache[pos.first][pos.second]=true;
        Map[pos.first][pos.second]=true;
        pos.first-=standard.first;
        pos.second-=standard.second;
        int temp=pos.second;
        pos.second=-pos.first+standard.second;
        pos.first=temp+standard.first;
        if(!cache[pos.first][pos.second])
        {
        info.push_back(pos);
        Map[pos.first][pos.second]=true;
        cache[pos.first][pos.second]=true;
        }
    }
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

cin>>N;
state.resize(N);
FOR(i,N,0)
{
state[i].resize(2);
pair<int,int> command;
cin>>state[i][0].second>>state[i][0].first>>command.first>>command.second;
Map[state[i][0].first][state[i][0].second]=true;
state[i][1].second=state[i][0].second+dx[command.first];
state[i][1].first=state[i][0].first+dy[command.first];
Map[state[i][1].first][state[i][1].second]=true;
rotate(command.second,state[i]);
}
FOR(i,100,0)
{
    FOR(j,100,0)
    {
        if(Map[i][j]&&Map[i+1][j]&&Map[i][j+1]&&Map[i+1][j+1]) Count++;
    }
}
cout<<Count;
return 0;
}