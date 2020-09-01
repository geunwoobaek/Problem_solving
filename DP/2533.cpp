#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define Max 1000001
int N;
vector<int> Graph[Max];
int cache[Max];
int dp(int cur,int from, bool state)
{
    if (Graph[cur].size() == 1)
    {
        if (state == true)
            return 1;
        else
            return 0;
    }
    int &result = cache[cur];
    if (result != -1)
        return result;
    else
        result = 0;
    result ++;
    for (int i = 0; i < Graph[cur].size(); i++)
    {   if(Graph[cur][i]==from) continue;
        result += (dp(Graph[cur][i],cur,false));
    }
    if (state == false)
    {
        int k = 0;
        for (int i = 0; i < Graph[cur].size(); i++)
        {   if(Graph[cur][i]==from) continue;
            k += dp(Graph[cur][i],cur,true);
        }
        result = min(k, result);
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int from, to;
        cin >> from >> to;
        Graph[from].push_back(to);
        Graph[to].push_back(from);
    }
    memset(cache, -1, sizeof(cache));
    cout << min(dp(1,Graph[1][0],true), dp(1,Graph[1][0],false) + 1);
    return 0;
}