#include <bits/stdc++.h>
using namespace std;
#define f(i, j, E) for (int i = j; i <= E; i++)
int N;
bool Map_[1001][1001];
bool visit[1001][1001];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int cnt = 0;
void dfs(int y, int x)
{
    f(i, 0, 3)
    {
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if (next_y < 0 || next_y > 1000 || next_x < 0 || next_x > 1000 || visit[next_y][next_x] ||!Map_[next_y][next_x]) continue;
        cout<<"("<<next_x-500<<","<<next_y-500<<")"<<"\n";
        visit[next_y][next_x] = true;
        dfs(next_y, next_x);
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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 500;
        x2 += 500;
        y2 += 500;
        y1 += 500;
        f(i, x1, x2)
        {
            Map_[y1][i] = true;
            Map_[y2][i] = true;
        }
        f(i, y1, y2)
        {
            Map_[i][x1] = true;
            Map_[i][x2] = true;
        }
    }
    if(Map_[500][500]) 
        cnt--;
    
    f(i, 0, 1000)
    {
        f(j, 0, 1000)
        {
            if (!visit[i][j]&&Map_[i][j])
            {   cout<<"("<<j-500<<","<<i-500<<")"<<"\n";
                visit[i][j] = true;
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}