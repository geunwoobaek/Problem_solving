#include <iostream> 
#include <queue>
 #include <vector>
using namespace std;
int N;
vector<pair<int, int>> map[100002];
int visited[100002];
int maxDistance;
int maxIndex;
void input();
void dfs(int index, int cost);
int main()
{
    input();
    dfs(1, 0);
    for (int i = 1; i <= N; i++)
        visited[i] = 0;
    maxDistance = 0;
    dfs(maxIndex, 0);
    printf("%d", maxDistance);
}
void input()
{
    int starter, end, distance;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &starter);
        for (;;)
        {
            scanf("%d", &end);
            if (end == -1)
                break;
            scanf("%d", &distance);
            map[starter].push_back(make_pair(end, distance));
            map[end].push_back(make_pair(starter, distance));
        }
    }
}
void dfs(int index, int cost)
{
    if (visited[index] != 0)
        return;
    if (maxDistance < cost)
    {
        maxDistance = cost;
        maxIndex = index;
    }
    visited[index] = 1;
    for (int i = 0; i < map[index].size(); i++)
    {
        pair<int, int> next = map[index][i];
        int nextIndex = next.first;
        int nextWeight = next.second;
        dfs(nextIndex, nextWeight + cost);
    }
}
