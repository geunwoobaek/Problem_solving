#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,j,e) for(int i=j;i<=e;i++)
int N,M;//500이하
int Map[501][501];
int dp[501][501];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dfs(int y,int x)
{   if(y==N&&x==M) return 1;
    int &result=dp[y][x];
    if(result!=-1) return result;
    else result=0;
    for(int i=0;i<4;i++)
    {
        int nextX=dx[i]+x;
        int nextY=dy[i]+y;
        if(nextX>0&&nextX<=M&&nextY<=N&&nextY>0&&Map[y][x]>Map[nextY][nextX])
        {
            result+=dfs(nextY,nextX);
        }
    }
    return result;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin>>N>>M;
f(i,1,N)
    f(j,1,M)
        cin>>Map[i][j],dp[i][j]=-1;
cout<<dfs(1,1);
return 0;
}