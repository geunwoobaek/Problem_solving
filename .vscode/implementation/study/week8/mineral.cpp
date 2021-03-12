#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int, int>
#define y first
#define x second
int R, C, N;
char Map[101][101];
int order = 0;
int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
queue<int> command;
int destroy(int cur_height, int start)
{
    int adder = start > 1 ? -1 : 1;
    for (; start <= C && start > 0; start += adder)
    {
        if (Map[cur_height][start] == 'x')
        {
            Map[cur_height][start] = '.';
            return start;
        }
    }
    return 2e9;
}
bool isRange(Pair &next)
{
    return (next.y > 0 && next.x > 0 && next.y <= R && next.x <= C);
}
void goBottom(Pair &next)
{
    Map[next.y][next.x] = '.';
    while (next.y + 1 < R && Map[next.y + 1][next.x] == '.')
    {
        next.y++;
    }
    Map[next.y][next.x] = 'x';
}
void simulation(int r, int c)
{
    vector<vector<bool>> visit(R + 1, vector<bool>(C + 1, false));
    queue<Pair> que;
    que.push({r, c});
    visit[r][c] = true;
    while (!que.empty())
    {
        Pair cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            Pair next = {cur.y + dy[i], cur.x + dx[i]};
            if (isRange(next) && !visit[next.y][next.x] && Map[next.y][next.x] == 'x')
            {
                que.push(next);
                visit[cur.y][cur.x] = true;
                goBottom(next);
            }
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
            cout << Map[i][j];
        cout << "\n";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
            cin >> Map[i][j];
    }
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int now;
        cin >> now;
        command.push(R + 1 - now);
    }
    while (!command.empty())
    {
        order++;
        int who = order % 2 == 0 ? C : 1;
        int cur_height = command.front();
        command.pop();
        int cur_row = destroy(cur_height, who);
        if (cur_row < 2e9)
            simulation(cur_height, cur_row);
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
            cout << Map[i][j];
        cout << "\n";
    }
    return 0;
}