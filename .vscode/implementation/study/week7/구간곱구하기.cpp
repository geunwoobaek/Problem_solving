#include <bits/stdc++.h>
#define LIMIT_ 1000000007
#define ll long long
using namespace std;
int N, M, K;
ll arr[2000004];
void change(ll what, ll how)
{
    what = N + 1 + what;
    while (1)
    {
        arr[what] = how;
        if (what == 1)
            break;
        what = what >> 1;
        how = (arr[what << 1] * arr[(what << 1) + 1]) % LIMIT_;
    }
}
int multifly(int from, int to)
{
    ll result = 1;
    from = N + 1 + from;
    to = N + 1 + to;
    while (from < to)
    {
        //계속 같은층이여야됨
        if ((from & 1) == 0)
        {
            from >>= 1;
        }
        else
        {
            result = (result * arr[from]) % LIMIT_;
            from = (from + 1) >> 1;
        }
        if ((to & 1) == 1)
        {
            to >>= 1;
        }
        else
        {
            result = (result * arr[to]) % LIMIT_;
            to = (to - 1) >> 1;
        }
    }
    if (from == to)
        result = (result * arr[from]) % LIMIT_;
    // else if (from < to)
    // {
    //     result = (result * (arr[from] * arr[(to)]) % LIMIT_) % LIMIT_;
    // }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    arr[N + 1] = 1;
    for (int i = N + 2; i <= 2 * N + 1; i++)
        cin >> arr[i];
    for (int i = N; i >= 1; i--)
    {
        arr[i] = (arr[i << 1] * arr[(i << 1) + 1]) % 1000000007;
    }
    for (int i = 0; i < M + K; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            change(b, c);
        else
            cout << multifly(b, c) << "\n";
    }
    return 0;
}