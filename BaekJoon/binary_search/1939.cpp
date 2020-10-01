// N(2≤N≤10,000)개의 섬으로 이루어진 나라가 있다. 이들 중 몇 개의 섬 사이에는 다리가 설치되어 있어서 차들이 다닐 수 있다.
// 영식 중공업에서는 두 개의 섬에 공장을 세워 두고 물품을 생산하는 일을 하고 있다. 물품을 생산하다
//보면 공장에서 다른 공장으로 생산 중이던 물품을 수송해야 할 일이 생기곤 한다.
//그런데 각각의 다리마다 중량제한이 있기 때문에 무턱대고 물품을 옮길 순 없다.
// 만약 중량제한을 초과하는 양의 물품이 다리를 지나게 되면 다리가 무너지게 된다.
// 한 번의 이동에서 옮길 수 있는 물품들의 중량의 최댓값을 구하는 프로그램을 작성하시오.
// 입력
// 첫째 줄에 N, M(1≤M≤100,000)이 주어진다. 다음 M개의 줄에는 다리에 대한 정보를 나타내는
// 세 정수 A, B(1≤A, B≤N), C(1≤C≤1,000,000,000)가 주어진다. 이는 A번 섬과 B번 섬 사이에 중량제한이 C인 다리가 존재한다는 의미이다.
// 서로 같은 두 도시 사이에 여러 개의 다리가 있을 수도 있으며, 모든 다리는 양방향이다. 마지막 줄에는 공장이 위치해 있는 섬의 번호를 나타내는 서로 다른 두 정수가 주어진다.
//공장이 있는 두 섬을 연결하는 경로는 항상 존재하는 데이터만 입력으로 주어진다.
// 3 3
// 1 2 2
// 3 1 3
// 2 3 2
// 1 3
// 9 9

// 1 4 11

// 1 5 2

// 4 5 4

// 4 3 10

// 4 2 7

// 5 2 10

// 5 6 13

// 3 2 9

// 2 6 8

// 1 6
#include <queue>
#include <iostream>
#include <functional>
using namespace std;
#define f(i, j, k) for (int i = j; i < k; i++)
#define Pair pair<int, int>
bool check[10001];
vector<vector<Pair>> adj;
int N, M, S, G, Maximum = 0;
void dfs(int number, int value) 
{
    if (Maximum > value) return;
    if (number == G) { Maximum = value;return; }
    for (Pair i : adj[number])
    {
        if (check[i.first]) continue;
        check[i.first] = true;
        int cur_value = i.second < value ? i.second : value;
        dfs(i.first, cur_value);
        check[i.first] = false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    memset(check, false, sizeof check);
    adj.resize(N + 1);
    f(i, 0, M)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    cin >> S >> G;
    dfs(S, 1e9);
    cout << Maximum;
    return 0;
}