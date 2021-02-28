#include <bits/stdc++.h>
using namespace std;
#define mod(k) k % 1000000000
#define Limit 1000000000
int N, cnt = 0;
int full = (1 << 10) - 1;
int cache[101][10][1 << 10];
map<int, int> m;
int dp(int idx, int cur, int check)
{
    if (cur < 0 || cur > 9)
        return 0;
    int &result = cache[idx][cur][check];
    if (result != -1)
        return result;
    if (idx == N)
    {
        if (check == full)
            return result = 1;
        else
            return result = 0;
    }
    result = 0;
    result += mod(
        mod(dp(idx + 1, cur + 1, check | m[cur + 1])) +
        mod(dp(idx + 1, cur - 1, check | m[cur - 1])));
    if (result != mod(result))
        cout << "mod(result)= "<<mod(result)<<"result="<<result<<endl;
    return mod(result);
}
int main()
{
    // cin >> N;
    // memset(cache, -1, sizeof(cache));
    // for (int i = 0; i < 10; i++)
    //     m[i] = (1 << i);
    // for (int i = 1; i <= 9; i++)
    // {
    //     cnt += dp(1, i, m[i]);
    //     cnt = mod(cnt);
    // }
    // cout << cnt;
    int k = Limit+213123;
    int h = Limit+431231;
    cout << mod(mod(k) + mod(h))<<endl;
    cout << mod((k + h));
    return 0;
}