// 트리가 입력으로 주어진다.
// 먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고
//(2≤V≤100,000)둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다.
//(정점 번호는 1부터 V까지 매겨져 있다고 생각한다)
// 먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데,
// 하나는 정점번호, 다른 하나는 그 정점까지의 거리이다.
//3 1 2 4 3 -1
// 예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고,
//정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다.
// 각 줄의 마지막에는 -1이 입력으로 주어진다. 주어지는 거리는 모두 10,000 이하의 자연수이다.
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
long long distance = 0;
int cache[100000][2];
int N, M;
#define Pair pair<int, int>
#define f(i, j, k) for (int i = j; i < k; i++)
#define V_to(i, j) V[i][j].first
#define V_tocost(i, j) V[i][j].second

int max(int a, int b){ return a > b ? a : b;}
vector<vector<pair<int, int>>> V; //from,to,cost

int dp(int prev, int cur, int result, int flag) //flag=0일때 2개까지 탐색가능 flag=1일때 하나만 탐색가능 
{
    int size = V.size();
    if (size == 1 && (prev == V_to(cur, 0)))
    {
        return result;
    }
    int &result = cache[cur][flag];
    if (result != -1) return result;
    result=0;
    if (flag==0)
    {
        f(i, 0, V[cur].size())
        {
            f(j, i + 1, V[cur].size())
            {
                result = max(result,dp(cur, V_to(cur, i), V_tocost(cur, i), 1)+dp(cur, V_to(cur, j), V_tocost(cur, j), 1));
            }
        }
    }
    for (Pair p : V[cur])
    {
        result = max(result, dp(cur, p.first, p.second, flag));
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    V.resize(N + 1);
    memset(cache, -1, sizeof cache);
    f(i, 0, N)
    {
        int from, to = 0, d = 0;
        cin >> from;
        while (to != -1)
        {
            cin >> to;
            while (to != -1)
            {
                cin >> d;
                V[from].push_back({to, d});
            }
        }
    }
    cout<<dp(0,1,0,0);
    return 0;
}