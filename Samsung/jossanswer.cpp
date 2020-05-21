//아기상어
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define FOR(i,end,start) for(int i=start;i<=end;i++)
struct joss{
    int y,x,depth,gauge,size;
};
struct comp{
    bool operator()(joss A, joss B)
	{ if(A.depth>B.depth) return false;
      if(A.depth<B.depth) return true;
      if(A.size > B.size) return false; //size가 큰순으로 위에올리기
      if(A.size<B.size) return true;
      else if(A.size==B.size) return A.gauge<B.gauge;//size가 같다면 게이지가 큰순으로 우선순위두기
    }
};
void ClearQueue(priority_queue<joss,vector<joss>,comp> &someQueue)
{
priority_queue<joss,vector<joss>,comp> empty;
swap(someQueue, empty);
}
bool visit[21][21];
int last=0;
bool check=false;
int Map[21][21];
int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};
priority_queue<joss,vector<joss>,comp> que;
int N;
int main()
{
cin>>N;
FOR(i,N,1)
{
    FOR(j,N,1) {
        cin>>Map[i][j];
        if(Map[i][j]==9)
        {
            que.push({i,j,0,0,2});
            visit[i][j]=true;
        }
    }
}
while(!que.empty()) //que돌리기
{
joss j=que.top();
que.pop();
FOR(i,3,0)
{ 
    int next_x=j.x+dx[i];
    int next_y=j.y+dy[i];
    if(next_x>0&&next_y>0&&next_x<=N&&next_y<=N&&!visit[next_y][next_x]&&Map[next_y][next_x]<=j.size)//
    {   check=true;
        visit[next_y][next_x]=true;
        if(j.size>Map[next_y][next_x]&&Map[next_y][next_x]>0)
        {
            if(j.gauge==j.size-1) {
            que.push({next_y,next_x,j.depth+1,0,j.size+1});
            }
            else {
            que.push({next_y,next_x,j.depth+1,j.gauge+1,j.size});
            }
            Map[next_y][next_x]=0;       
            memset(visit,false,sizeof(visit));
            visit[next_y][next_x]=true;
            last=j.depth+1;
            break;
        }
        else if(!check) que.push({next_y,next_x,j.depth+1,j.gauge,j.size});
    }
}
}
cout<<last;
return 0;
}