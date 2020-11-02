#include <iostream>
using namespace std;
int y, x, answer = 0;
int arr[501][501];
int dp[501][501];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};
void input();
int dfs(int ty, int tx);
int main()
{
    input();
    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            answer += dfs(i, j);
        }
    }
    cout << answer;
    return 0;
}
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> y >> x;
    for (int i = 1; i <= y; i++)
    {
        string now;
        cin >> now;
        for (int j = 1; j <= x; j++)
        {
            if (now[j-1] == 'R')
                arr[i][j] = 0;
            else if (now[j-1] == 'L')
                arr[i][j] = 1;
            else if (now[j-1] == 'U')
                arr[i][j] = 2;
            else
                arr[i][j] = 3;
            dp[i][j]=-1;
        }
    }
}
int dfs(int ty, int tx)
{
    if (ty > y || tx > x || tx == 0 || ty == 0) return 1;
    int &result = dp[ty][tx];
    if (result != -1)
        return result;
    result = 0;
    int now = arr[ty][tx];
    ty += dy[now];
    tx += dx[now];
    return result = dfs(ty, tx);
}
