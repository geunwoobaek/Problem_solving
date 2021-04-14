//이문제를 풀기 위한 솔루션
#include <bits/stdc++.h>
using namespace std;
int testCase, N, M;
int cache[11][1 << 10 + 1];
int bitMap[11];
int dfs(int cnt, int cur, int idx, int line, int bitcheck, vector<string> &Room)
{
    if (line == N || cur >= bitMap[M])
        return 0;
    int &result = cache[line][bitcheck];
    if (result != -1&&cur==0)
        return result;
    for (int i = idx; i < M; i++)
    {
        int next = cur | bitMap[i];
        if (Room[line][i] != 'x' && (i == M || (bitMap[i + 1] & bitcheck) == 0) && (i == 0 || (bitMap[i - 1] & bitcheck) == 0))
        {
            result = max(result, dfs(cnt + 1, next, i + 2, line, bitcheck, Room)); //
            result = max(result, cnt + 1 + dfs(0, 0, 0, line + 1, next, Room));
        }
    }
    result = max(result, dfs(0, 0, 0, line + 1, 0, Room));
    if (result == -1)
        return result = 0;
    else
        return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i <= 12; i++)
    {
        bitMap[i] = 1 << i;
    }
    cin >> testCase;
    while (testCase-- > 0)
    {
        cin >> N >> M;
        memset(cache, -1, sizeof(cache));
        vector<string> vec(N);
        for (int i = 0; i < N; i++)
            cin >> vec[i];
        int result = 0;
        // for (int i = 0; i < N; i++)
        result = dfs(0, 0, 0, 0, 0, vec);
        cout << result << "\n";
    }
    return 0;
}