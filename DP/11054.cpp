#include <iostream>
#include <vector>
using namespace std;
int N, answer = 0;
int seq[1001];
int up[1001];
int dw[1001];
int max(int a, int b) { return a > b ? a : b; }
void input();
int dp(int cur, bool isUp);
int main()
{
    input();
    for (int i = 1; i <= N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (seq[i] > seq[j]) up[i] = max(up[i], up[j] + 1);
        }
    }
    for (int i = N-1; i >=1; i--)
    {
        for (int j = i+1; j<=N; j++)
        {
            if (seq[j] < seq[i]) dw[i] = max(dw[i], dw[j] + 1);
        }
    }
    for(int i=1;i<=N;i++)
    {
        answer=max(answer,up[i]+dw[i]);
    }
    cout<<answer-1;
    return 0;
}
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> seq[i];
        up[i]=dw[i]=1;
    }
}
