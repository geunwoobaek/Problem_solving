#include <iostream>
#include <vector>
using namespace std;
int N, answer = 0;
int seq[1001];
int up[1001];
int cache[2][1001];
int dw[1001];
int max(int a, int b) { return a > b ? a : b; }
void input();
int dp(int cur);
int mem(int cur, bool isUp);
int main()
{
    input();
    cout << mem(0, true);
    // cout<<dp(1)+1;
    return 0;
}
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cache[0][0]=-1;
    cache[1][0]=-1;
    for (int i = 1; i <= N; i++)
    {
        cin >> seq[i];
        up[i] = dw[i] = -1;
        cache[0][i] = cache[1][i] = -1;
    }
}
// int dp(int cur)
// {
// int &res = up[cur];
// if (res != -1)
//     return res;
// res = 0;
// for (int i = cur + 1; i <= N; i++)
// {
//     res = max(res, (seq[cur] < seq[i]) + dp(i));
// }
// return res;
// }
int mem(int cur, bool isUp) //한번에 메모리제이션할려고했는데실패
{
    int &res = cache[isUp][cur];
    if (res != -1)
        return res;
    res = 0;
    for (int i = cur + 1; i <= N; i++)
    {
        bool isNext = seq[cur] < seq[i];
        bool isPlus = (seq[cur] != seq[i])&&((isUp == isNext) ||isUp);
        if(isPlus) res=max(res,1+mem(cur+1,isNext));
        res = max(res, mem(cur + 1, isUp));
    }
    return res;
}