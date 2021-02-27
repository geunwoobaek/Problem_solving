#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N;
int FULL = (1 << 10) - 1;
ll cnt = 0;
ll cache[10][40];
int dfs(int cur, int idx)
{
    if (cur < 0 || cur > 10)
        return 0;
    if (idx == N)
        return 1;
    ll &result = cache[cur][idx];
    if (result != -1)
        return result;
    result = 0;
    return result = dfs(cur - 1, idx + 1) + dfs(cur + 1, idx + 1);
}
int check = 0;
ll calculate(int cur, int idx, int check)
{
    if (cur < 0 || cur > 9 || idx >= N) return 0;
    check |= (1 << (cur));
    if (check == FULL)
    {
        return cache[cur][idx];
    }
    return calculate(cur + 1, idx + 1, check) + calculate(cur - 1, idx + 1, check);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    memset(cache, -1, sizeof cache);
    for (int i = 0; i <= 9; i++)
        dfs(i, 0);
    for (int i = 1; i <= 9; i++)
    {
        cnt += calculate(i, 0,i);
        cnt %= 1000000000;
    }
    cout << cnt;
    return 0;
}