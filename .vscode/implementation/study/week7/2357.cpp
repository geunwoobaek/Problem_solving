#include <bits/stdc++.h>
#define LIMIT_ 1000000007
#define ll long long
#define Pair pair<int, int>
#define min_ first
#define max_ second
using namespace std;
int N, M;
Pair arr[200004];
Pair findPair(Pair cur, int target)
{
    return {min(cur.min_, arr[target].min_), max(cur.max_, arr[target].max_)};
}
Pair find(int from, int to)
{
    Pair result = {2e9, 0};
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
            result = findPair(result, from);
            from = (from + 1) >> 1;
        }
        if ((to & 1) == 1)
        {
            to >>= 1;
        }
        else
        {
            result = findPair(result, to);
            to = (to - 1) >> 1;
        }
    }
    if (from == to)
        result = findPair(result, from);
    else if (from < to)
    {
        result = findPair(findPair(result, from), to);
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    arr[N + 1] = {2e9, 0};
    for (int i = N + 2; i <= 2 * N + 1; i++)
    {
        int num;
        cin >> num;
        arr[i] = {num, num};
    }
    for (int i = N; i >= 1; i--)
    {
        arr[i] = findPair(arr[i << 1], (i << 1) + 1);
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Pair result = find(a, b);
        cout << result.first << " " << result.second << "\n";
    }
    return 0;
}