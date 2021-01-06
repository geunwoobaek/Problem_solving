#include <bits/stdc++.h> //https://programmers.co.kr/learn/courses/30/lessons/60063
using namespace std;
#define Board vector<vector<int>>
int MapSize = 0;
bool isVisit[101][101][2] = {
    true,
}; //x1,y1,direction always x2>x1 or y2>y1
enum Direction
{
    Right = 0, //x2>x1
    Down = 2   //y2>y1
};
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 }; //오른쪽 위 왼쪽 아래
enum Rotate
{
    Clock = 0,
    Count_Clock = 1,
    None = 2
};

struct Robot
{
    int x1 = 0, y1 = 0, x2 = 1, y2 = 0, direct = Right, sec = 0; //방향
};
int search(const Board& board);
bool Rotate(Robot& robot, int Mode, Board& board);
bool isRange(Robot& robot, Board& board);
queue<Robot> robots;
int solution(vector<vector<int>> board)
{
    MapSize = board.size();
    return search(board);
}
int main()
{
    vector<vector<int>> board = { {0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0} };
    cout << solution(board);
}

bool Rotate(Robot& robot, int Mode, const Board& board)
{
    if (Mode == Clock)
    { //시계방향
        if (robot.x1 == robot.x2)
        {
            if (robot.x1 == MapSize-1|| board[robot.x1 +1][robot.y1] == 1)
                return false;
            robot.direct = Right;
            robot.y1 = robot.y2;
            robot.x2 += 1;
        }
        else //y같을때
        {
            if (robot.y1 == 0|| board[robot.x1][robot.y1-1] == 1)
                return false;
            robot.direct = Down;
            robot.x1 = robot.x2;
            robot.y1 -= 1;
        }
    }
    else
    { //반시계방향
        if (robot.x1 == robot.x2)
        {
            if (robot.x1 ==0 || board[robot.x1 - 1][robot.y1] == 1)
                return false;
            robot.direct = Right;
            robot.y1 = robot.y2;
            robot.x1 -= 1;
        }
        else
        {
            if (robot.y1 ==MapSize-1 || board[robot.x1][robot.y1 + 1] == 1)
                return false;
            robot.direct = Down;
            robot.x1 = robot.x2;
            robot.y2 += 1;
        }
    }
    return true;
}
bool isRange(Robot& robot, const Board& board)
{
    return robot.x1 >= 0 && robot.y1 >= 0 && robot.x2 < MapSize && robot.y2 < MapSize && board[robot.x1][robot.y1] != 1 && board[robot.x2][robot.y2] != 1;
}
int search(const Board& board)
{
    robots.push(Robot());
    while (!robots.empty())
    {
        Robot robot = robots.front();
        robots.pop();
        if ((robot.x1 == MapSize - 1 && robot.y1 == MapSize - 1) || (robot.x2 == MapSize - 1 && robot.y2 == MapSize - 1))
        {
            return robot.sec;
        }
        //Go
        for (int i = 0; i < 2; i++)
        {
            Robot next_robot;
            next_robot.x1 = robot.x1 + dx[robot.direct + i];
            next_robot.x2 = robot.x2 + dx[robot.direct + i];
            next_robot.y1 = robot.y1 + dy[robot.direct + i];
            next_robot.y2 = robot.y2 + dy[robot.direct + i];
            next_robot.sec = robot.sec + 1;
            next_robot.direct = robot.direct;

            if (isRange(next_robot, board) && !isVisit[next_robot.x1][next_robot.y1][next_robot.direct])
            {
                isVisit[next_robot.x1][next_robot.y1][next_robot.direct] = true;
                robots.push(next_robot);
            }
        }
        //Rotate
        for (int mode = 0; mode < 2; mode++)
        {
            Robot next_robot = robot;
            next_robot.sec += 1;
            if (Rotate(next_robot, mode, board) && isRange(next_robot, board) && !isVisit[next_robot.x1][next_robot.y1][next_robot.direct])
            {
                isVisit[next_robot.x1][next_robot.y1][next_robot.direct] = true;
                robots.push(next_robot);
            }
        }
    }
    return 1234567890;
}