#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define To first
#define Cost second
#define Pair pair<int, int>
vector<vector<pair<int, int>>> bus;
vector<int> Map;
int N, M, S, E; //도시수,버스수
struct compare
{
    bool operator()(Pair a, Pair b)
    {
        return a.Cost > b.Cost;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    bus.resize(N + 1);
    for (int i = 1; i <= M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        bus[from].push_back({to, cost});
    }
    cin >> S >> E;
    Pair p = {S, 0};
    Map.resize(N+1,2e9);
    priority_queue<Pair, vector<Pair>, compare> que;
    que.push(p);
    while (!que.empty())
    {
        Pair cur = que.top();
        que.pop();
        int from = cur.To;
        for (int i = 0; i < bus[from].size(); i++)
        {
            int des = bus[from][i].To;
            int &until_now = Map[des];
            int now_cost = bus[from][i].Cost + cur.Cost;
            if (until_now > now_cost)
            {
                until_now = now_cost;
                que.push({des, now_cost});
            }
        }
    }
    cout << Map[E];
    return 0;
}