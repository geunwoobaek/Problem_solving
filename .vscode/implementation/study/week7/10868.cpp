#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[200003]; //O(N^2)불가능 memorization 필요
//어떻게 해야할까?
// 하나씩 넘어갈때 마다 //dp[i][j] i->z사이의 가장큰값 일반dp를 사용하는것도 결국엔 n^2
//segmentTree통해서
int find(int start, int end)
{
    start = start * 2 + 2;
    end = end * 2 + 2;
    int result = 2e9;
    do
    {
        while (start & 1 == 0 && start >= 1)
            start << 1;
        result = min(arr[start], result);
        start += 1;
        while (end & 1 == 1 && end >= 1)
            end << 1;
        result = min(arr[end], result);
        end -= 1;
    } while (start < end);
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i <= 2 * N + 2; i++)
        arr[i] = 2e9;
    //1,2,3,4,5,6,7;
    for (int i = 2; i <= N + 1; i++)
        cin >> arr[N + i];
    for (int i = N; i >= 1; i--)
        arr[i] = min(arr[(i << 1)], arr[(i << 1) + 1]);
    for (int i = 1; i <= M; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << find(start, end) << "\n";
    }
    return 0;
}
