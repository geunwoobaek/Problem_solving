#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int MOD = 20170805;
int up_[501][501];
int left_[501][501];

int solution(int m, int n, vector<vector<int>> city_map)
{
    memset(up_, 0, sizeof(up_));
    memset(left_, 0, sizeof(left_));
    up_[1][1] = 1;
    left_[1][1] = 1;

    for (int y = 1; y <= m; y++)
    {
        for (int x = 1; x <= n; x++)
        {
            int option = city_map[y - 1][x - 1];
            if (option == 2)
            {
                left_[y][x] = left_[y][x - 1];
                up_[y][x] = up_[y - 1][x];
            }
            else if (option == 1)
            {
                left_[y][x] = 0;
                up_[y][x] = 0;
            }
            else
            {
                left_[y][x] = (left_[y][x] + left_[y][x - 1] + up_[y - 1][x]) % MOD;
                up_[y][x] = (up_[y][x] + left_[y][x - 1] + up_[y - 1][x]) % MOD;
            }
        }
    }
    return (left_[m][n - 1] + up_[m - 1][n]) % MOD;
}
int main()
{
    vector<vector<int>> city_map(3);
    for (int i = 0; i < 3; i++)
    {
        city_map[i].resize(3);
    }
    cout << solution(3, 6, city_map);
    return 0;
}