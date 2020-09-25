#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define To first
#define Cost second
#define Pair pair<int, int> //도착지점 cost
vector<vector<pair<int, int>>> network; 
vector<int> Map;
vector<int> Trace;
int cnt=0;
vector<vector<int>> line; //start부터 end까지 만드는데   포함
int N, M, S, E;           //도시수,버스수
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
    network.resize(N + 1);
    for (int i = 1; i <= M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        network[from].push_back({to, cost});
        network[to].push_back({from, cost});
    }
    Pair p = {1, 0};
    Map.resize(N + 1, 2e9);
    Trace.resize(N + 1, 1);
    priority_queue<Pair, vector<Pair>, compare> que; //도착지점 ,cost
    que.push(p);
    while (!que.empty())
    {
        Pair cur = que.top();
        que.pop();
        int from = cur.To;
        for (int i = 0; i < network[from].size(); i++)
        {
            int des = network[from][i].To;
            int &until_now = Map[des];
            int now_cost = network[from][i].Cost + cur.Cost;
            if (until_now > now_cost) //비용계산
            {
                if (Trace[from] != des)
                    Trace[des] = from;
                until_now = now_cost;
                que.push({des, now_cost});
            }
        }
    }
    cout<<Trace.size()-2<<endl;
    for(int i=2;i<Trace.size();i++)
    {
        printf("%d %d\n",i,Trace[i]);
    }
    return 0;
}