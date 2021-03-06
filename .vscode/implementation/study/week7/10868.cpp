#include <bits/stdc++.h>
#define LIMIT_ 1000000007
#define ll long long
using namespace std;
int N, M;
int arr[200004];

int find(int from, int to)
{
    int result = 2e9;
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
            result = min(result,arr[from]);
            from = (from + 1) >> 1;
        }
        if ((to & 1) == 1)
        {
            to >>= 1;
        }
        else
        {
            result = min(result,arr[to]);
            to = (to - 1) >> 1;
        }
    }
    if (from == to)
        result = min(result,arr[from]);
    else if (from < to)
    {
        result = min(result,min(arr[to],arr[from]));
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    arr[N + 1] = 2e9;
    for (int i = N + 2; i <= 2 * N + 1; i++)
        cin >> arr[i];
    for (int i = N; i >= 1; i--)
    {
        arr[i] = min(arr[i << 1],arr[(i << 1) + 1]);
    }
    for (int i = 0; i <M; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<find(a,b)<<"\n";
    }
    return 0;
}