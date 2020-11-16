#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int N, M;
vector<int> Parent(50001, 1);
vector<int> Depth(50001, 50001);
vector<vector<int>> adj(50001);
queue<int> tree;
#define f(i, j, N) for (int i = j; i <= N; i++)
int findSameParent(int a, int b)
{
    //depth가 같을때까지 계속 findSameParent진행
    //depth가 같아지면 같은 공통조상나올때까지 재귀진행
    if (a == b)
        return a;
    else if (Depth[a] < Depth[b])
        return findSameParent(a, Parent[b]);
    else if (Depth[a] > Depth[b])
        return findSameParent(Parent[a], b);
    else
        return findSameParent(Parent[a], Parent[b]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    Depth[1] = 0;
    f(i, 1, N - 1)
    {
        int from, to, p, c;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    tree.push(1);
    while (!tree.empty())
    {
        int parent = tree.front();
        tree.pop();
        for (auto child : adj[parent])
        {
            if (child!=Parent[parent])
            {
                tree.push(child);
                Depth[child] = Depth[parent] + 1;
                Parent[child] = parent;
            }
        }
    }
    cin >> M;
    f(i, 1, M)
    {
        int a, b;
        cin >> a >> b;
        cout << findSameParent(a, b) << "\n";
    }
    return 0;
}