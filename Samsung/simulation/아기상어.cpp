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

void ClearQueue(queue<joss> &someQueue)
{
queue<joss> empty;
swap(someQueue, empty);
}
joss now={21,21,10000000,0,2};
bool visit[21][21];
int last=0,number=0;
bool size_gauge[28*10+27];
bool check[10000000]={true,};//게이지
int Map[21][21];
int dy[4]={-1,0,0,1};
int Maximum=0;
int dx[4]={0,-1,1,0};
queue<joss> que;
int N;
void simulation()
{
    while(1)
    {
        while(!que.empty()) 
        {
            joss j=que.front();
            que.pop();
            if(!size_gauge[10*j.size+j.gauge]) 
            {
            size_gauge[10*j.size+j.gauge]=true;
            break;
            }
            FOR(i,3,0)
            { 
                int next_x=j.x+dx[i];
                int next_y=j.y+dy[i];
                if(next_x>0&&next_y>0&&next_x<=N&&next_y<=N&&!visit[next_y][next_x]&&Map[next_y][next_x]<=j.size)//들어갈수있을때
                {   visit[next_y][next_x]=true;
                    if(j.size>Map[next_y][next_x]&&Map[next_y][next_x]>0)
                    {   if(now.depth>=j.depth+1)
                        {
                        if(now.y>next_y||((now.y==next_y)&&(now.x>next_x))) //왼쪽위일때
                        {   
                            if(j.gauge==j.size-1) now={next_y,next_x,j.depth+1,0,j.size+1};
                            else now={next_y,next_x,j.depth+1,j.gauge+1,j.size};       
                             last=j.depth+1;
                             que.push(now);
                        }
                        }
                    }
                    else que.push({next_y,next_x,j.depth+1,j.gauge,j.size});
                }
            }
        }
        if(!check[last]) { //새로운깊이가 들어왔을때
            ClearQueue(que);
            check[last]=true;
            Map[now.y][now.x]=0;      
            memset(visit,false,sizeof(visit));
            visit[now.y][now.x]=true;
            que.push(now);
            Maximum=now.size;
            now={21,21,10000000,0,2};
        }
        else break;
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N;
size_gauge[20]=true;
FOR(i,N,1)
{
    FOR(j,N,1) {
        cin>>Map[i][j];
        if(Map[i][j]==9)
        {
            que.push({i,j,0,0,2});
            visit[i][j]=true;
            Map[i][j]=0;
        }
    }
}
simulation();
cout<<last<<endl;
return 0;
}