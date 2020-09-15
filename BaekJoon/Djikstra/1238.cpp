#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;
bool visit[1001];
int N, M, Point; //학생수,길수,도착할마을지점
int Maximum = 0;
vector<vector<pair<int, int>>> d(1001);
vector<vector<pair<int, int>>> d2(1001);
struct info
{
    int start, current, cost;
};
struct compare
{
    bool operator()(info a, info b)
    {
        return a.cost > b.cost;
    }
};

void djikstra(int start, vector<vector<pair<int, int>>> &Map)
{
    priority_queue<info, vector<info>, compare> queue;
    for (int i = 0; i < d[start].size(); i++)
    {
        queue.push(info{start, Map[start][i].first, Map[start][i].second});
    }
    while (!queue.empty())
    {
        info cur = queue.top();
        queue.pop();
        for (auto curinfo : d[cur.current]) //curinfo first=도착장소 second비용
        {
            int &pre_cost = _Map[cur.start][curinfo.first];
            int cur_cost = cur.cost + curinfo.second;
            if (pre_cost > cur_cost)
            {
                pre_cost = cur_cost;
                queue.push({cur.start,
                            curinfo.first,
                            cur_cost});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> Point;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            _Map[i][j] = 2e9;
    }
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a].push_back({b, c}); //a에서 b로갈때 드는비용
        d[b].push_back({a, c}); //a에서 b로갈때 드는비용
        _Map[a][b] = c;
    }
    djikstra(Point, d);
    djikstra(Point, d2);
    for (int i = 1; i <= N; i++)
    {
        if (Point != i)
            Maximum = max(Maximum, _Map[Point][i] + _Map[i][Point]);
    }
    cout << Maximum;
    return 0;
}
