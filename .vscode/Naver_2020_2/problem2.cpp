#include<iostream>
#include<queue>
#include<cstring>
#include <map>
#include<vector>
using namespace std;
vector<int> solution(vector<vector<int>> blocks) {
    int total = blocks.size();
    vector<int> answer((total * (total + 1)) / 2);
    vector<vector<int>>map(total, vector<int>(total));
    map[0][0] = blocks[0][1];
    for (int i = 1;i < blocks.size();i++)
    {
        int pos = blocks[i][0];
        int value = blocks[i][1];
        map[i][pos] = value;
        int left = pos;  //left
        int right = pos; //right
        while (right < i && left>=1&&blocks[i - 1][right - 1] != 0)
        {
            map[i][right + 1] = map[i - 1][right] - map[i][right];
            right++;
        }
        while (left >= 1)
        {   
            map[i][left-1] = map[i - 1][left-1] - map[i][left];
            left--;
        }
        while (right < i)
        {
            map[i][right + 1] = map[i - 1][right] - map[i][right];
            right++;
        }

        left = pos;
    }
        int cur = 0;
        for (int i = 0;i < map.size();i++)
        {
            for (int j = 0;j <= i;j++)
            {
                answer[cur++] = map[i][j];
            }
        }
    return answer;
}

int main()
{
    vector<vector<int>> blocks(5, vector<int>(2));
    blocks[0][0] = 0;//[[0, 50], [0, 22], [2, 10], [1, 4], [4, -13]]
    blocks[0][1] = 50;
    blocks[1][0] = 0;
    blocks[1][1] = 22;
    blocks[2][0] = 2;
    blocks[2][1] = 10;
    blocks[3][0] = 1;
    blocks[3][1] = 4;
    blocks[4][0] = 4;
    blocks[4][1] = -13;
    solution(blocks);
    return 0;
}