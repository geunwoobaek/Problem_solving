#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;
int N, M, Point; //학생수,길수,도착할마을지점
int Maximum = 0;
vector<vector<pair<int, int>>> d(1001);
vector<vector<pair<int, int>>> d2(1001);
int prev_cost[1001];
int answer[1001];
struct info
{
    int current, cost;
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
    for (int i = 1; i <= N; i++)
		prev_cost[i] = 1e9; //시작지점 부터 해당지점까지의거리 ㅇ

    priority_queue<info, vector<info>, compare> queue;
    queue.push({start,0});
    while (!queue.empty())
    {
        info cur = queue.top(); //현재위치
        queue.pop();
        for(int i=0;i<Map[cur.current].size();i++)
        {
            int now_cost=Map[cur.current][i].second+cur.cost;//현재지점부터 특정지점까지갔을때 의거리
            int arrive=Map[cur.current][i].first;
            if(now_cost<prev_cost[arrive])
            {
                prev_cost[arrive]=now_cost;
                queue.push({arrive,now_cost});
            }
        }
    }
    for(int i=1;i<=N;i++)
    {   
        answer[i]+=prev_cost[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> Point;
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a].push_back({b, c}); //a에서 b로갈때 드는비용
        d2[b].push_back({a, c}); //a에서 b로갈때 드는비용
    }
    djikstra(Point, d);
    djikstra(Point, d2);
    for (int i = 1; i <= N; i++)
    {
        if (Point != i)
            Maximum = max(Maximum,answer[i]);
    }
    cout << Maximum;
    return 0;
}
