#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adjGraph;
int cache[300001][2];
//한팀에 하나
int dfs(int nodeNum, int mustInclude, vector<int> &sales)
{ //현재 읽고 있는 노드번호,현재 단계에서 무조건 읽어야 하는지 아닌지

    int &result = cache[nodeNum][mustInclude];
    if (result != -1)
        return result;
    result = sales[nodeNum - 1];
    for (int i : adjGraph[nodeNum])
    {
        result += dfs(i, false, sales);
    }
    if (!mustInclude) //false일시에
    {
        int next_result = 0;
        for (int include_node : adjGraph[nodeNum])
        {
            next_result = dfs(include_node, true, sales);
            for (int notInclude_node : adjGraph[nodeNum])
            {
                if (notInclude_node != include_node)
                    next_result += dfs(notInclude_node, false, sales);
            }
            result = min(next_result, result);
        }
        if (adjGraph[nodeNum].size() == 0)
            result = 0;
    }
    return result;
}
int solution(vector<int> sales, vector<vector<int>> links)
{
    adjGraph.resize(sales.size() + 1);
    memset(cache, -1, sizeof cache);
    for (auto link : links)
        adjGraph[link[0]].push_back(link[1]);
    return dfs(1, false, sales);
}
int main()
{
    cout<<solution({14, 17, 15, 18, 19, 14, 13, 16, 28, 17},
             {{10, 8},
              {1, 9},
              {9, 7},
              {5, 4},
              {1, 5},
              {5, 10},
              {10, 6},
              {1, 3},
              {10, 2}});
    // cout << solution({5, 6, 5, 3, 4},
    //                  {{1, 4}, {1, 2}});
    return 0;
}