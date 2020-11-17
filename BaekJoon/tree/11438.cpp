#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int N, M;
int Parent[100001][21];
vector<int> Depth(100001, 100001);
vector<vector<int>> adj(100001);
#define f(i, j, N) for (int i = j; i <= N; i++)
void getTreedfs(int parent, int cur)
{
    Parent[cur][0] = parent;
    Depth[cur] = Depth[parent] + 1;
    for (auto child : adj[cur])
    {
        if (child != parent)
        {
            getTreedfs(cur, child);
        }
    }
}
int findSameParent(int a, int b)
{
    //depth가 같을때까지 계속 findSameParent진행
    //depth가 같아지면 같은 공통조상나올때까지 재귀진행
    if (a == b)
        return a;
    else if (Depth[a] == Depth[b]) findSameParent(Parent[a][0], Parent[b][0]);
    else { //depth가 다를때
           //depth큰쪽을 depth가 적은쪽이랑 같아지도록 맞춤
           //예를들어 2,7 7->6>5->3,가게하기
        int aParentNum = 0, bParentNum=0;
        int aValue = a, bValue = b;
        while (Depth[aValue] > Depth[bValue])
        {
            if (Depth[Parent[a][aParentNum]] > Depth[b]) {
                aValue = Parent[a][aParentNum];
                aParentNum++;
            }
            else {
                a = aValue;
                aValue = Parent[a][aParentNum=0];
            }
        }
        while (Depth[aValue] < Depth[bValue])
        {
            if (Depth[Parent[b][bParentNum]] > Depth[a]) {
                bValue = Parent[b][bParentNum];
                bParentNum++;
            }
            else {
                b = bValue;
                bValue = Parent[b][bParentNum = 0];
            }
        }
        return findSameParent(aValue, bValue);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    Depth[1] = -1;
    f(i, 1, N - 1)
    {
        int from, to, p, c;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    getTreedfs(1, 1);
    f(i, 1, N)
    {
        f(j, 0, 19)
        {
            if (Parent[i][j] <= 1) break;
            Parent[i][j + 1] = Parent[Parent[i][j]][j];//아는것을 이용해서 topDown방식으로
        }
    }
    cin >> M;
    f(i, 1, M)
    {
        int a, b;
        cin >> a >> b;
        cout << findSameParent(a, b) << "\n";
    }
    return 0;
}