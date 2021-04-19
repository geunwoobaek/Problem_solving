#include <bits/stdc++.h>
using namespace std;
#define V 6
bool bfs(int rGraph[V][V], int s, int t, int parent[V])
{
    queue<int> que;
    que.push(s);
    bool visit[V];
    memset(visit, 0, sizeof(visit));
    parent[s]=-1;
    visit[s] = true;
    while (!que.empty())
    {
        int cur_vtx = que.front();
        que.pop();
        for (int next_vtx = 0; next_vtx < V; next_vtx++)
        {
            if (!visit[next_vtx] && rGraph[cur_vtx][next_vtx]>0)
            {
                parent[next_vtx] = cur_vtx;
                if(next_vtx==t) return true;
                que.push(next_vtx);
                visit[next_vtx] = true;
            }
        }
    }
    return false;
}
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    int parent[V];
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent))
    { //bfs 깊이 탐색 s to t까지
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) //not using self recurence
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int main()
{
    // Let us create a graph shown in the above example
    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
 
    cout << "The maximum possible flow is "
         << fordFulkerson(graph, 0, 5);
 
    return 0;
}