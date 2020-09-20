#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
#define Row 0
#define Colum 1
int TC;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    cin >> TC;
    int order = 0;
    while (++order <= TC)
    {
        bool On = true;
        int N, M;
        cin >> N >> M;
        vector<vector<int>> map(N + 1, vector<int>(M + 1, 0));
        vector<vector<int>> MaxCut(2, vector<int>(101, 0));
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                int &cur = map[i][j];
                cin >> cur;
                if (MaxCut[Row][i] < cur)
                    MaxCut[Row][i] = cur; //i는 행
                if (MaxCut[Colum][j] < cur)
                    MaxCut[Colum][j] = cur; //j에 열이들어가야됨
            }
        }
        for (int i = 1; i <= N && On; i++)
        {
            for (int j = 1; j <= M && On; j++)
            {
                if (map[i][j] == MaxCut[Row][i] || map[i][j] == MaxCut[Colum][j])
                {
                    continue;
                }
                else
                {
                    cout << "#" << order << " "
                         << "NO" << endl;
                    On = false;
                    break;
                }
            }
        }
        if (On)
            cout << "#" << order << " "
                 << "YES" << endl;
    }
    return 0;
}