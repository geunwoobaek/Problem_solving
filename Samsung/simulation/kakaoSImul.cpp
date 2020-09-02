#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int up_[500][500];
int left_[500][500];
int MOD = 20170805;

void simulation(vector<vector<int>> city_map)
{
    up_[0][0] = 1;
    left_[0][0]=1;
    int limit_x = city_map[0].size();
    int limit_y = city_map.size();

    for (int i = 0; i < limit_y; i++) //맨위의 값전부다 1로초기화
    {
        if (city_map[i][0] != 1 && city_map[i][0] != 2)
            {left_[i][0]=1;up_[i][0] = 1;}
    }
    for (int i = 0; i < limit_x; i++) //맨왼쪽의 값 모두 0으로 초기화
    {
        if (city_map[0][i] != 1 && city_map[0][i] != 2)
          {left_[0][i]=1;up_[0][i] = 1;}
    }
    for (int y = 1; y < limit_y; y++)
    {
        for (int x = 1; x < limit_x; x++)
        {
            int option=city_map[y][x];
            if(option==2) 
            {
                left_[y][x]=left_[y][x-1];
                up_[y][x]=up_[y-1][x];
            }
            else if(option==1)
            {
                left_[y][x]=0;
                up_[y][x]=0;
            }
            else{
                left_[y][x]=(left_[y][x-1]+up_[y-1][x])%MOD;
                up_[y][x]=left_[y][x];
            }
        }
    }
}
int solution(int m, int n, vector<vector<int>> city_map)
{
    simulation(city_map);
    int answer = up_[m - 1][n - 1] % MOD;
    return answer;
}
int main()
{
    vector<vector<int>> city_map(3);
    for (int i = 0; i < 3; i++)
    {
        city_map[i].resize(3);
    }
    // city_map[0][1] = 2;
    // city_map[0][5] = 2;
    // city_map[1][2] = 2;
    // city_map[1][4] = 1;
    // city_map[2][0] = 1;
    // city_map[2][3] = 2;
    // city_map[2][4] = 2;
    cout << solution(3, 6, city_map);
    return 0;
}