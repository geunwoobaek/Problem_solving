#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#define Max 1000001
int min(int a, int b) { return a > b?b:a; };
int N;
vector<int> Graph[Max];
int cache[Max][2];
int dp(int cur, int from, int state)
{
    if (Graph[cur].size() == 1 && from == Graph[cur][0]) //말단노드에 도착했을경우
    {
        if (state == 1) //자기자신칠해야하는경우 1
            return 1;
        else
            return 0; //자기자신안칠해도되는경우
    }
    int& result = cache[cur][state];
    if (result != -1)
        return result;
    else
        result = 1;//자기 자신 칠할경우
    for (int i = 0; i < Graph[cur].size(); i++)
    {
        if (Graph[cur][i] == from) continue;
        result += (dp(Graph[cur][i], cur, 0)); //state=0으로
    }
    if (state == 0) //이때 자기자신 안칠해도 되는경우
    {
        int k = 0;
        for (int i = 0; i < Graph[cur].size(); i++)
        {
            if (Graph[cur][i] == from) continue; //이때 왔던 노드일경우 스킵
            k += dp(Graph[cur][i], cur, 1); //다음노드들은 자기자신을 칠해야한다.
        }
        result = min(k, result); //자기자신 칠한경우+자기자신안칠한경우
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
    cout <<dp(1,0,0);
    return 0;
}