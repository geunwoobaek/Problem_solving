#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
bool check[50][50];
int cache[50][50];
int minimum = 2e9;
#define Pair pair<int, int>
#define Que queue<Pair,vector<Pair>>
int simulation(vector<Pair> &candidate,Que& que)
{
    while(!que.empty())
    {

    }
}
void dfs(Que que,vector<vector<int>> &adj, Pair cur, int result)
{
    check[cur.first][cur.second] = false;
    vector<Pair> candidate;
    int now = simulation(candidate,que);
    result += now;
    if (now == 0)
    {
        minimum = minimum < result ? minimum : result;
    }
    for (int i = 0; i < candidate.size(); i++)
    {
        dfs(que,adj, {candidate[i].first, candidate[i].second}, result);
    }
}
int solution(int n, vector<vector<int>> edges)
{
    vector<vector<int>> adj(n); //인접배열담음
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            check[i][j] = false;
            cache[i][j] = 2e9;
        }
    }
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    int answer = 0;
    return answer;
}
string str;
int main()
{
    cout << solution(9, 10);
    return 0;
}