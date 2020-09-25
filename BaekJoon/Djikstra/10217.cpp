#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define Pair pair<int, pair<int, int>> // first=도착지점,first.first=비용 first.second=소요시간
#define To first
#define Cost second.first
#define Time second.second
//map[start][end] 해당 코스트로 해당지점까지 가는게 걸리는 시간
struct compare
{
    bool operator()(Pair a, Pair b)
    {
        return a.Time > b.Time;
    }
};
int TC;
int N, M, K;    //공항수,총 지원비용,티켓정보의수
int u, v, c, d; //출발공항,도착공항,비용,소요시간
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TC;
    while (--TC >= 0)
    {
        cin >> N >> M >> K;
        vector<vector<int>> Map(100001,vector<int>(100,2e9)); // 해당 코스트로 해당지점까지 가는게 걸리는 시간
        // 해당 지점까지 가는데 걸리는 시간과 cost
        vector<vector<Pair>> adjacency(N + 1); //인접배열
        while (--K >= 0)
        {
            cin >> u >> v >> c >> d;
            adjacency[u].push_back({v, {c, d}});
        }
        priority_queue<Pair, vector<Pair>, compare> que;
        que.push({1, {0, 0}});
        while (!que.empty())
        {
            Pair cur = que.top();
            que.pop();
            int From = cur.To;
            for (int i = 0; i < adjacency[From].size(); i++)
            {
                Pair &now = adjacency[From][i];
                int to = now.To;
                int &prev_time = Map[to].first;
                int &prev_cost = Map[to].second;
                int now_time = now.Time + cur.Time;
                int now_cost = now.Cost + cur.Cost;
                if (now_cost <= M &&(prev_time>now_time)||prev_cost>now_cost) //비용:90 시간이 10 비용 50 시간 20
                {   prev_time=now_time;
                    que.push({to,{now_cost,now_time}});
                }
            }
        }
        if(Map[N].second==2e9) cout<<"Poor KCM\n";
        else cout<<Map[N].first<<endl;
    }
    return 0;
}