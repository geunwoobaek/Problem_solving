#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int Map[12][12];
int Max;
int MaxCount = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int N, vector<pair<int, int>> &core, int now, int result, int cnt)
{
    if (Max <= result)
    {
        return;
    }
    if (now == core.size())
    {
        if (MaxCount <= cnt)
        {
            MaxCount = cnt;
            Max = result;
        }
        return;
    }
    int y = core[now].first;
    int x = core[now].second;
    bool on = false;
    for (int i = 0; i < 4; i++)
    {
        pair<int, int> next = {y, x};
        bool istrue = true;
        int sum = 0;
        while (next.first > 0 && next.second > 0 && next.first < N - 1 && next.second < N - 1)
        {
            sum++;
            next.first += dy[i];
            next.second += dx[i];
            if (Map[next.first][next.second] == 1)
            {
                istrue = false;
                break;
            }
            Map[next.first][next.second] = 1;
        }
        if (istrue)
        {
            on = true;
            dfs(N, core, now + 1, result + sum, cnt + 1);
            Map[next.first][next.second] = 0;
        }
        while (next != make_pair(y, x))
        {
            next.first -= dy[i];
            next.second -= dx[i];
            Map[next.first][next.second] = 0;
        }
        Map[y][x] = 1;
    }
    if (!on)
        dfs(N, core, now + 1, result, cnt);
}
void solution()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    int N;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        memset(Map, sizeof Map, 0);
        cin >> N;
        int MaxCount = 0;
        vector<pair<int, int>> Core;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> Map[i][j];
                if (Map[i][j] == 1 && i != 0 && i != N - 1 && j != 0 && j != N - 1)
                {
                    Core.push_back({i, j});
                }
            }
        }
        Max = 2e9;
        if (Core.size() != 0)
            dfs(N, Core, 0, 0, 0);
        cout << "#" << test_case << " " << Max << endl;
    }
}
int main()
{
    solution();
    return 0;
}
