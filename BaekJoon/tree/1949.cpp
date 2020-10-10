//양방향가능
//인접
//우수 동네수의 총합최대로해야함
//우수 동네들끼리는 인접하면 안됨
//우수동네와 아닌동네 인접 최소 1개
#include <iostream>
#include <vector>
using namespace std;
int N; //1<N<10,000
int max(int a, int b) { return a > b ? a : b; }
vector<int> cost(10001);
int dp[2][10001];               //0일경우 이거없이 1일경우 이때포함
vector<vector<int>> adj(10001); //[0].first=사람수 [0].second는 인접동네
int _cost = 0;
int traverlsal(int prev, int cur, int mode) //mode=0일경우 칠함 //1일경우 안칠하기
{   int res=0;
    if (mode == 0) res += cost[cur];
    if (adj[cur].size() == 1 && adj[cur][0] == prev) return res; 
    int &result = dp[mode][cur];
    if (result != -1) return result;
    result = res;
    for (int i = 0; i < adj[cur].size(); i++)
    {
        int next = adj[cur][i];
        if (next == prev) continue;
        int now = 0;
        now = traverlsal(cur, next, 1);
        if (mode == 1) now = max(now, traverlsal(cur, next, 0));
        result += now;
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        dp[0][i] = -1;
        dp[1][i] = -1;
        cin >> cost[i];
    }
    for (int i = 1; i <= N - 1; i++)
    {
        int From, to;
        cin >> From >> to;
        adj[From].push_back(to);
        adj[to].push_back(From);
    }
    cout<<max(traverlsal(0, 1, 0),traverlsal(0, 1, 1));
    return 0;
}