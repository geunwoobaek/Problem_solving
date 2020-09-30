// 첫째 줄에는 테스트케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 주어진다.
//첫째 줄에 건물의 개수 N 과 건물간의 건설순서규칙의 총 개수 K이 주어진다. (건물의 번호는 1번부터 N번까지 존재한다)
// 둘째 줄에는 각 건물당 건설에 걸리는 시간 D가 공백을 사이로 주어진다.
//셋째 줄부터 K+2줄까지 건설순서 X Y가 주어진다. (이는 건물 X를 지은 다음에 건물 Y를 짓는 것이 가능하다는 의미이다)
// 마지막 줄에는 백준이가 승리하기 위해 건설해야 할 건물의 번호 W가 주어진다.
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int cache[1001];
#define Pair pair<int, int> //first=건물번호 완성시간
#define f(i, j, k) for (int i = j; i < k; i++)
int T, N, K, G;
int dfs(vector<int> &cost, vector<vector<int>> &Rules, int G)
{
    int &result = cache[G];
    if (result != -1)
        return result;
    result = 0;
    for (int i : Rules[G])
    {
        result = max(result, dfs(cost, Rules, i));
    }
    return result = result + cost[G];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T-- > 0)
    {
        cin >> N >> K;
        int now_time = 0;
        memset(cache, -1, sizeof cache);
        vector<int> cost(N + 1);
        vector<vector<int>> Rules(N + 1); //a를먼저 지어야지만 지을수 있는 빌딩들
        f(i, 1, N + 1) cin >> cost[i];
        f(i, 0, K)
        {
            int a, b;
            cin >> a >> b;
            Rules[b].push_back(a);
        }
        cin >> G;
        cout << dfs(cost, Rules, G) << endl;
    }
    return 0;
}
