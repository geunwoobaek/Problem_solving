#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[500][500];
bool check[500][500];
int dy[2] = { 0, 1 };
int dx[2] = { 1, 0 };
int MOD = 20170805;

void simulation(vector<vector<int>> city_map)
{
    map[0][0] = 1;
    int limit_x = city_map[0].size();
    int limit_y = city_map.size();

    for (int i = 0; i < limit_y; i++) //맨위의 값전부다 1로초기화
    {
        if (city_map[i][0] != 1)
            map[i][0] = 1;
    }
    for (int i = 0; i < limit_x; i++) //맨왼쪽의 값 모두 0으로 초기화
    {
        if (city_map[0][i] != 1)
            map[0][i] = 1;
    }
    for (int y = 1; y < limit_y; y++)
    {
        int k = 0;
        for (int x = 1; x < limit_x; x++)
        {
            int up_value = map[y - 1][x], left_value = map[y][x - 1];
            int copy_y = y;
            int copy_x = x;
            int up_condition = city_map[y - 1][x];
            int left_condition = city_map[y][x - 1];
            while (copy_y >= 1 && up_condition == 2)
            {
                copy_y--;
                up_condition = city_map[copy_y][copy_x];
                up_value = map[copy_y][copy_x];
            }
            copy_y = y;
            while (copy_x >= 1 && left_condition == 2)
            {
                copy_x--;
                left_condition = city_map[copy_y][copy_x];
                left_value = map[copy_y][copy_x];
            }
            if (up_condition != 2) 
                 map[y][x] += up_value;
            if (left_condition != 2)
                map[y][x] += left_value;
        }
    }
}
int solution(int m, int n, vector<vector<int>> city_map)
{
    simulation(city_map);
    int answer = map[m - 1][n - 1] % 20170805;
    return answer;
}
int main()
{
    vector<vector<int>> city_map(3);
    for (int i = 0; i < 3; i++)
    {
        city_map[i].resize(6);
    }
    city_map[0][1] = 2;
    city_map[0][5] = 2;
    city_map[1][2] = 2;
    city_map[1][4] = 1;
    city_map[2][0] = 1;
    city_map[2][3] = 2;
    city_map[2][4] = 2;
    cout << solution(3, 3, city_map);
    return 0;
}