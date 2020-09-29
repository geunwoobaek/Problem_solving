// 첫째 줄에는 테스트케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 주어진다.
//첫째 줄에 건물의 개수 N 과 건물간의 건설순서규칙의 총 개수 K이 주어진다. (건물의 번호는 1번부터 N번까지 존재한다)
// 둘째 줄에는 각 건물당 건설에 걸리는 시간 D가 공백을 사이로 주어진다.
//셋째 줄부터 K+2줄까지 건설순서 X Y가 주어진다. (이는 건물 X를 지은 다음에 건물 Y를 짓는 것이 가능하다는 의미이다)
// 마지막 줄에는 백준이가 승리하기 위해 건설해야 할 건물의 번호 W가 주어진다.
#include <iostream>
#include <queue>
#include<cstring>
#include <vector>
using namespace std;
bool check[1001];
#define f(i, j, k) for (int i = j; i < k; i++)
int T, N, K, X, Y, W, D;


void main()
{
    cin >> T;
    while (T-- > 0)
    {
        cin >> N >> K;
        memset(check,false,sizeof check);
        vector<int> cost(N + 1);
        vector<vector<int>> Rules(K + 1); //
        f(i, 1, N + 1) cin >> cost[i];
        f(i, 0, K)
        {
            int a, b;
            cin >> a >> b;
            Rules[a].push_back(b);
        }
    }
}
