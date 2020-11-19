#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define f(i, j, e) for (int i = j; i <= e; i++)
#define Pair pair<int, int>
#define y first
#define x second
int N; //100이하
int Map[101][101];
int visit2[101][101];
int total;
vector<Pair> bishop;
int Maximum = 0;
int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, -1, 1, -1};
void CheckVisit(Pair now,int on)
{   
    for (int i = 0; i < 4; i++)
    {
        int nowx = now.x;
        int nowy = now.y;
        while (nowx > 0 && nowy > 0 && nowx <= N && nowy <= N)
        {
            visit2[nowy][nowx]+=on;
            nowx += dx[i];
            nowy += dy[i];
        }
    }
}
//cur=5,number=1 bishop 12까지 Maxnumbe
void dfs(int cur, int number)
{
    Maximum = max(Maximum, number);
    if(Maximum>=(total-cur+number)) return;
    f(i, cur,total-1)
    {
        if (visit2[bishop[i].y][bishop[i].x]==0)
        {
            CheckVisit(bishop[i],1);
            dfs(i + 1, number + 1);
            CheckVisit(bishop[i],-1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    f(i, 1, N)
    {
        f(j, 1, N)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 1)
                bishop.push_back({i, j});
        }
    }
    total=bishop.size();
    dfs(0, 0);
    cout << Maximum;
    return 0;
}