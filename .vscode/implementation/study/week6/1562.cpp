#include <bits/stdc++.h>
using namespace std;
int n;
int memo[101][10][1 << 10];
int solve(int len, int cur, int situ)
{
    int &ret = memo[len][cur][situ];
    if (ret != -1)
        return ret;
    if (len == n)
    {
        if (situ == (1 << 10) - 1)
            return 1;
        else
            return 0;
    }
    ret = 0;
    if (cur == 0)
    {
        ret += solve(len + 1, cur + 1, situ | (1 << (cur + 1)));
        ret %= 1000000000;
    }
    else if (cur == 9)
    {
        ret += solve(len + 1, cur - 1, situ | (1 << (cur - 1)));
        ret %= 1000000000;
    }
    else
    {
        ret += solve(len + 1, cur - 1, situ | (1 << (cur - 1)));
        ret %= 1000000000;
        ret += solve(len + 1, cur + 1, situ | (1 << (cur + 1)));
        ret %= 1000000000;
    }
    return ret %= 1000000000;
    ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    memset(memo, -1, sizeof(memo));
    int sum = 0;
    for (int i = 1; i < 10; i++)
    {
        int situ = (1 << i);
        sum += solve(1, i, situ);
        sum %= 1000000000;
    }
    cout << sum << '\n';
    return 0;
}
