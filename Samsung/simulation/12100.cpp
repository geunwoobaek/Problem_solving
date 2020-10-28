#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
int N, _max = 0;
vector<vector<int>> board(21, vector<int>(21));
void input();
void simul(vector<vector<int>> &cur, int depth);
void solve();
void move(vector<vector<int>> &cur, int i);
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int main()
{
    solve();
    return 0;
}
void solve()
{
    input();
    simul(board, 5);
    cout << _max;
}
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
}
void simul(vector<vector<int>> &cur, int depth) //
{
    if (depth == 0)
    {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (cur[i][j] > _max)
                    _max = cur[i][j];
        return;
    }
    //위로올라갈때 dir=0 //y=1,x=1인지점부터 y=N까지 dy=-1
    //밑으로내려갈때 dir=1 //y=N인지점부터 1까지 dy=+1
    //왼쪽으로 dir=2 //x=1부터 X=N dx=-1
    //오른쪽으로 dir=3 //x=N부터 X=1까지 dx=+1
    for (int i = 0; i < 4; i++)
    {
        move(cur,i,depth);
    }
}
void move(vector<vector<int>> cur, int i,int depth)
{
    vector<vector<bool>> ismerge(N + 1, vector<bool>(N + 1));
    int x, y, add;
    if (i % 2 == 0) x = y = add = 1;
    else x = y = N,add = -1;
    for (; y <= N && y >= 1; y += add)
    {
        for (; x <= N && x >= 1; x += add)
        {   if (cur[y][x] == 0)
                continue;
            int curx = x, cury = y;
            while (curx + dx[i] >= 1 && cury + dy[i] >= 1 && curx + dx[i] <= N && cury + dy[i] <= N && !ismerge[cury + dy[i]][curx + dx[i]] && (cur[cury + dy[i]][curx + dx[i]] == 0 || (cur[cury + dy[i]][curx + dx[i]] == cur[y][x])))
            {
                curx += dx[i];
                cury += dy[i];
            }
            if (cury != y || x != curx)
            {
                ismerge[cury][curx] = cur[cury][curx] != 0;
                cur[cury][curx] += cur[y][x];
                cur[y][x] = 0;
            }
        }
    }
    simul(cur, depth - 1);
}
