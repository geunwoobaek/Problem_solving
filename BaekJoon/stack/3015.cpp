#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define Pair pair<int, int>
#define x first
#define y second
bool visit[4][30];
vector<Pair> horse(4, {0, 0});
vector<int> dice(10);
int map[4][30];
int _Max = 0;
void setting();
void input();
void solve();
void dfs(int res, int cur);
int main()
{
    solve();
    return 0;
}
void solve()
{
    input();
    setting();
    dfs(0, 0);
    cout << _Max;
}
void dfs(int res, int cur)
{
    if (cur == 10)
    {
        _Max = max(res, _Max);
         return;
    }
    for (auto &now : horse)
    {
        Pair prev = now;
        now.x += dice[cur];
        if (now.y == 0)
        {
            if (now.x == 5) now.y = 1;
            else if (now.x == 10) now.y = 2;
            else if (now.x == 15) now.y = 3;
        }
        // 9 13 19
        if(now.y==2&&now.x>=13) now.y=1,now.x-=4; 
        else if(now.y==3&&now.x>=19) now.y=1,now.x-=10; 
        if (map[now.y][now.x] == 0) now.x = now.y = 0;
        bool isforty=map[now.y][now.x]==40;
        bool isOk=true;
        if(isforty){
            isOk=(!visit[0][20]&&!visit[1][12]);
        }
        if (now.x == 0 ||!visit[now.y][now.x]&&isOk)
        {
            visit[prev.y][prev.x] = false;
            visit[now.y][now.x] = true;
            dfs(res+map[now.y][now.x], cur + 1);
            visit[prev.y][prev.x] = true;
            visit[now.y][now.x] = false;
        }
        now = prev;
    }
}

void input()
{
    for (int i = 0; i < 10; i++)
        cin >> dice[i];
}

void setting()
{
    for (int i = 1; i <= 20; i++) map[0][i] = 2 * i;
    map[1][5]= 10;
    map[1][6] = 13;
    map[1][7] = 16;
    map[1][8] = 19;
    map[1][9] = 25;
    map[1][10] = 30;
    map[1][11] = 35;
    map[1][12] = 40;
    map[2][10] = 20;
    map[2][11] = 22;
    map[2][12] = 24;
    map[3][15] = 30;
    map[3][16] = 28;
    map[3][17] = 27;
    map[3][18] = 26;
}