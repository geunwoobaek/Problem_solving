#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 }; //위 오른쪽 아래 왼쪽
int finalanswer = 0;
void dfs(vector<vector<int>>& maze, pair<int, int> position, int direction, int result)
{
    if (position.first == maze.size() - 1 && position.second == maze.size() - 1)
    {
        finalanswer = result;
        return;
    }
    if (position.first == maze.size() || position.second == maze.size())
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int y = position.first;
        int x = position.second;
        int now = (i + direction) % 4;
        y += dy[now];
        x += dx[now];
        if (y >= 0 && x >= 0 && y < maze.size() && x < maze.size())
        {
            if (maze[y][x] != 1)
            {
                pair<int, int> p = make_pair(y, x);
                if (now == 0) now = 4;
                dfs(maze, p, now - 1, result + 1);
                break;
            }
        }
    }
}
int solution(vector<vector<int>> maze)
{
    pair<int, int> start = make_pair(0, 0);
    dfs(maze, start, 1, 0);
    return finalanswer;
}
int main()
{
    vector<vector<int>> maze(6);
    vector<int> a(6);
    vector<int> a1(6);
    vector<int> a2(6);
    vector<int> a3(6);
    vector<int> a4(6);
    vector<int> a5(6);
    //[[0, 1, 0, 0, 0, 0], [0, 1, 0, 1, 1, 0], [0, 1, 0, 0, 1, 0], [0, 1, 1, 1, 1, 0], [0, 1, 0, 0, 0, 0], [0, 0, 0, 1, 1, 0]]
    a[1] = 1;
    a1[1] = 1;
    a1[3] = 1;
    a1[4] = 1;
    a2[1] = 1;
    a2[4] = 1;
    a3[1] = 1;
    a3[2] = 1;
    a3[3] = 1;
    a3[4] = 1;
    a4[1] = 1;
    a5[3] = 1;
    a5[4] = 1;
    maze[0] = a;maze[1] = a1;maze[2] = a2;maze[3] = a3;maze[4] = a4;maze[5] = a5;
    solution(maze);
    return 0;
}