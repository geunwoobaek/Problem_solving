#include <iostream>
#include <vector>
#include <string.h>
#define For(i, start, end) for (int i = start; i < end; i++)
using namespace std;
pair<int, int> coin[101]; //first:동전 second:갯수
int N, K;
int sum[10001][101]; //
int dp(int result, int cur)
{
    if (result == N)
        return 1;
    else if (cur > K-1)
        return 0;
    int &cache = sum[result][cur];
    if (cache != -1)
        return cache;
    cache = 0;
    for (int i = cur; i < K; i++)
    {
        For(j, 1, coin[i].second + 1)
        {   int new_result=result + coin[i].first * j;
            if(new_result>N) break;
            cache += dp(new_result, i + 1);
        }
    }
    return cache;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    For(i, 0, K)
    {
        cin >> coin[i].first >> coin[i].second;
    }
    memset(sum, -1, sizeof(sum));
    cout << dp(0, 0);
    return 0;
}