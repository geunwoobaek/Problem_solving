// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>
#define F(i, s, e) for (int i = s; i <= e; i++)
#define Pair pair<int, int>
#define y first
#define x second
#define LIMIT_ 1e4
using namespace std;
int N, M; //1<=N,M<=10
int Map[11][11];
int dy[4] = { 1, 0, -1, 0 }, dx[4] = { 0, 1, 0, -1 };
// 각섬에서 각섬까지의 거리 계산
//섬갯수 최대 6
// 최소 구할때 Dfs로 구하기
// 하나의 섬에서 하나의 섬으로 거리 계산? 어떻게
//A점에있는 한점에서 퍼져나가기
//이때 퍼져나간점이 다른 섬에있는지 체크 어떻게?? HashMap으로
//HashMap[점]=섬
map<Pair, int> landMap;
vector<Pair> landVec;
//섬에서 섬까지 최소거리 담고있는 컨테이너
bool isRange(const Pair& next_)
{
    return next_.y > 0 && next_.y <= N && next_.x > 0 && next_.x <= M;
}
struct minDistance
{
    set<int> connections;
    int totalDistance = 0;
};
struct compare
{
    bool operator()(minDistance& a, minDistance& b)
    {
        return a.totalDistance > b.totalDistance;
    }
};

vector<vector<int>> distances(7, vector<int>(7, LIMIT_));
void findLand(int island, Pair pos)
{
    Map[pos.y][pos.x] = 0;
    landMap[pos] = island;
    F(d, 0, 3)
    {
        Pair next_ = { pos.y + dy[d], pos.x + dx[d] };
        if (isRange(next_) && Map[next_.y][next_.x] == 1)
        {
            findLand(island, next_);
        }
    }
}
void findDistance(bool isColum)
{
    int row = M;
    int col = N;
    if (!isColum) swap(row, col);
    F(i, 1, row)
    {
        int cur_land = 0;
        int cur_distance = 0;
        F(j, 1, col)
        {
            int next_land = isColum ? landMap[{j, i}] : landMap[{i, j}];
            if (next_land != 0 && next_land != cur_land) //현재 밟은곳이 다른 섬이라면
            {
                if (cur_land != 0 && cur_distance >= 2) //섬에서 시작했고 거리가 2보다 크거나 같을경우
                {
                    distances[cur_land][next_land] = min(cur_distance, distances[cur_land][next_land]);
                    distances[next_land][cur_land] = distances[cur_land][next_land];
                }
                cur_land = next_land;
                cur_distance = 0;
            }
            else if (cur_land != 0 && next_land == 0) //섬에서 시작했고 현재밟은점이 강이라면
                cur_distance++;
            else cur_distance = 0; //자기 자신을 밟은거라면
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    F(i, 1, N)
        F(j, 1, M)
        cin >> Map[i][j];
    int land = 0;
    F(i, 1, N)
    {
        F(j, 1, M)
        {
            if (Map[i][j] == 1)
            {
                findLand(++land, { i, j });
            }
        }
    }
    findDistance(true);
    findDistance(false);
    priority_queue<minDistance, vector<minDistance>, compare> que;
    que.push({ {1}, 0 });
    while (!que.empty())
    {
        minDistance cur = que.top();
        que.pop();
        if (cur.connections.size() == land)
        {
            cout << cur.totalDistance;
            exit(0);
        }
        for (int from : cur.connections)
        {
            for (int to = 1; to <= land; to++)
            {
                if (cur.connections.find(to) != cur.connections.end() || distances[from][to] == LIMIT_) continue;
                cur.connections.insert(to);
                que.push({ cur.connections, cur.totalDistance + distances[from][to] });
                cur.connections.erase(to);
            }
        }
    }
    cout << -1;
    return 0;
}
