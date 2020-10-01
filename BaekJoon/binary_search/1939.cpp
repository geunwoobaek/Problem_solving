#include <iostream>
#include<cstring>
#include<queue>
#include <functional>
using namespace std;
#define f(i, j, k) for (int i = j; i < k; i++)
#define Pair pair<int, int>
vector<vector<Pair>> adj;
bool check[10001];
int N, M, S, G;
bool bfs(int weight);
int binary_search();
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    adj.resize(N + 1);
    vector<int> cost;
    f(i, 0, M)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    cin >> S >> G;
    

    cout << binary_search();
    return 0;
}
bool bfs(int weight)
{
    queue<int> que;
    memset(check, false, sizeof check);
    que.push(S);
    check[S] = true;
    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        if (now == G)  
            return true;
        for (Pair p : adj[now])
        {
            if (p.second < weight||check[p.first]) continue;
            check[p.first] = true;
            que.push(p.first);
        }
    }
    return false;
};

int binary_search()
{
    int result = 0;
    int left = 0;
    int right = 1e9;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (bfs(mid)) 
            left = mid+1;
        else 
            right = mid - 1;
    }
    return right;
};
