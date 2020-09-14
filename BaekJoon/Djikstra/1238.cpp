#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
string str;
//N<1000;
// 4 8 2
// 1 2 4
// 1 3 2
// 1 4 7
// 2 1 1
// 2 3 5
// 3 1 2
// 3 4 4
// 4 2 3
vector<vector<int>> Map(1001, vector<int>(1001, 2e9));
bool visit[1001];
int N, M, Point; //학생수,길수,도착할마을지점
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0;i < 1001;i++)
    {
        for (int j = 0;j < 1001;j++) dp[i][j] = 2e9;
    }
    cin >> N >> M >> Point;
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Map[a][b] = c;
    }
    visit[1] = true;
    cout << djikstra(1, 4);
    return 0;
}