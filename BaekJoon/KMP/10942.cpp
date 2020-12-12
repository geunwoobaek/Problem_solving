#include <bits/stdc++.h>
using namespace std;

int N;
int board[2001];
int cache[2001][2001];
vector<int> res;

int palin(int s, int e)
{
    if (s >= e)
    {
        return 1;
    }
    int &ret = cache[s][e];
    if (ret != -1)
        return ret;

    if (board[s] == board[e])
    {
        return ret = palin(s + 1, e - 1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> board[i];
    memset(cache, -1, sizeof(cache));
    int M;
    cin >> M;
    while (M--)
    {   int S, E;
        cin >> S>>E;
        res.push_back(palin(S, E));
    }
    for (int i = 0; i < (int)res.size(); ++i)
    {
        cout<<res[i]<<"\n";
    }
    return 0;
}