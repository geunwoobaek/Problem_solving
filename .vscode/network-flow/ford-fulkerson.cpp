#include <bits/stdc++.h>
using namespace std;
#define V 6
// #define Pair pair<vector<int>, int>
// #define vtx first
// #define cost second
bool isVisit[V];
int max_graph[V][V]; //res
void dfs(vector<int> &vtxs, int end, int graph[V][V], bool &isEnd)
{
    int now = vtxs.back();
    if (now == end)
    {
        int min_value = 2e9;
        for (int i = 1; i < vtxs.size(); i++)
            min_value = min(graph[vtxs[i - 1]][vtxs[i]], min_value); //min_graph찾기
        for (int i = 1; i < vtxs.size(); i++)
        {
            graph[vtxs[i - 1]][vtxs[i]] -= min_value;
            graph[vtxs[i]][vtxs[i - 1]] += min_value;
            max_graph[vtxs[i - 1]][vtxs[i]] += min_value;
        }
        isEnd = false;
        return;
    }
    for (int i = 0; i < V; i++)
        if (!isVisit[i] && graph[vtxs.back()][i] != 0)
        {
            vtxs.push_back(i);
            isVisit[i] = true;
            dfs(vtxs, end, graph, isEnd);
            isVisit[i] = false;
            vtxs.pop_back();
        }
}
int fordFulkerson(int graph[V][V], int start, int end)
{
    int res = 0;
    vector<int> vtxs({start});
    bool isEnd = false;
    while (!isEnd)
    {
        isEnd = true;
        memset(isVisit, false, sizeof(isVisit));
        isVisit[start] = true;
        dfs(vtxs, end, graph, isEnd);
    }
    for (int i = 0; i < V; i++)
        res += max_graph[i][end];
    return res;
}
int main()
{
    // Let us create a graph shown in the above example
    int graph[V][V] = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0}, {0, 4, 0, 0, 14, 0}, {0, 0, 9, 0, 0, 20}, {0, 0, 0, 7, 0, 4}, {0, 0, 0, 0, 0, 0}};
    cout << "The maximum possible flow is "
         << fordFulkerson(graph, 0, 5);
    cout << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << graph[i][j] << "/" << max_graph[i][j] << ", ";
        cout << endl;
    }
    return 0;
}
