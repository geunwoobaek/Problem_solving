// N(2 ≤ N ≤ 50,000)개의 정점으로 이루어진 트리가 주어진다. 트리의 각 정점은 1번부터 N번까지 번호가 매겨져 있으며, 루트는 1번이다.
// 두 노드의 쌍 M(1 ≤ M ≤ 10,000)개가 주어졌을 때, 두 노드의 가장 가까운 공통 조상이 몇 번인지 출력한다.
// 입력
// 첫째 줄에 노드의 개수 N이 주어지고, 다음 N-1개 줄에는 트리 상에서 연결된 두 정점이 주어진다. 그 다음 줄에는 가장 가까운 공통 조상을 알고싶은 쌍의 개수 M이 주어지고, 다음 M개 줄에는 정점 쌍이 주어진다.
// 출력
// M개의 줄에 차례대로 입력받은 두 정점의 가장 가까운 공통 조상을 출력한다.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
#define f(i, j, k) for (int i = j; i < k; i++)
vector<vector<int>> adj;
vector<int> Parent;
vector<int> depth;
struct node {
    int prev_data,data,depth;
};
int LCA(int a, int b)
{
    while (a != b)
    {
        if (depth[a] > depth[b])
        {
            a = Parent[a];
        }
        else b=Parent[b];
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    Parent.resize(N + 1, 1); //전체노드의 부모는 1
    adj.resize(N + 1);
    depth.resize(N + 1);
    f(i, 1, N) { int a, b;cin >> a >> b;adj[a].push_back(b);adj[b].push_back(a);}
    queue<node> que;
    que.push({ 1,1,0 });
    while (!que.empty())
    {
        node cur = que.front();
        depth[cur.data] = cur.depth;
        que.pop();
        f(i, 0, adj[cur.data].size())
        {
            int next_Data = adj[cur.data][i];
            if (next_Data != cur.prev_data)
            {
                Parent[next_Data] = cur.data;
                int next_depth = cur.depth + 1;
                que.push({ cur.data,next_Data,next_depth });
            }
        }
    }
    
    cin >> M;
    f(i, 0, M)
    {
        int t1, t2;
        cin >> t1 >> t2;
        cout<<LCA(t1,t2)<<endl;
    }
    return 0;
}