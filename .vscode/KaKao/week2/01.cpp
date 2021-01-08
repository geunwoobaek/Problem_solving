#include <bits/stdc++.h> //https://programmers.co.kr/learn/courses/30/lessons/60063
using namespace std;
#define Board vector<vector<int>>
int MapSize = 0;
bool isVisit[101][101][2] = {true,}; 
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 }; //오른쪽 왼쪽 아래 위
enum Direction
{
Row = 0, //x2>x1
Col = 1  //y2>y1
};
struct Robot
{
    int x1 = 0, y1 = 0, x2 = 1, y2 = 0, direct = Row, sec = 0; //방향
    Robot() {}
    Robot(int x1, int y1, int x2, int y2, int direct, int sec)
    {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->direct = direct;
        this->sec = sec;
    }
};
queue<Robot> robots;
int search(const Board& board);
void RotateAndPush(Robot& robot, const Board& board);
bool isRange(Robot& robot, const Board& board);
bool IsVisit(Robot& robot);
void Push(Robot& robot);
int solution(vector<vector<int>> board)
{
    MapSize = board.size();
    return search(board);
}
bool IsVisit(Robot& robot) { return isVisit[robot.y1][robot.x1][robot.direct]; }
void Push(Robot& robot) {
    robots.push(robot);
    isVisit[robot.y1][robot.x1][robot.direct] = true;
}
bool isRange(Robot& robot, const Board& board)
{
    return robot.x1 >= 0 && robot.y1 >= 0 && robot.x2 < MapSize && robot.y2 < MapSize && board[robot.y1][robot.x1] != 1 && board[robot.y2][robot.x2] != 1;
}
void RotateAndPush(Robot& robot, const Board& board)
{
    if (robot.direct == Row)
    { //Row형태일경우
        //robot의 밑부분
        Robot Next_range = robot;
        Next_range.y1 = Next_range.y2 = robot.y1 + 1;
        if (isRange(Next_range, board))
        {
            Robot next_robot(robot.x1, robot.y1, robot.x1, robot.y1 + 1, Col, robot.sec + 1);
            Robot next_robot2(robot.x2, robot.y2, robot.x2, robot.y2 + 1, Col, robot.sec + 1);
            if (!IsVisit(next_robot)) Push(next_robot);
            if (!IsVisit(next_robot2)) Push(next_robot2);
        }
        //robot의 윗부분
        Next_range.y1 = Next_range.y2 = robot.y1 - 1;
        if (isRange(Next_range, board))
        {
            Robot next_robot(robot.x1, robot.y1 - 1, robot.x1, robot.y1, Col, robot.sec + 1);
            Robot next_robot2(robot.x2, robot.y2 - 1, robot.x2, robot.y2, Col, robot.sec + 1);
            if (!IsVisit(next_robot)) Push(next_robot);
            if (!IsVisit(next_robot2))  Push(next_robot2);
        }
    }
    else //Col일경우
    {
        Robot Next_range = robot;
        Next_range.x1 = Next_range.x2 = robot.x1 + 1;
        if (isRange(Next_range, board))
        {
            Robot next_robot(robot.x1, robot.y1, robot.x1 + 1, robot.y1, Row, robot.sec + 1);
            Robot next_robot2(robot.x2, robot.y2, robot.x2 + 1, robot.y2, Row, robot.sec + 1);
            if (!IsVisit(next_robot)) Push(next_robot);
            if (!IsVisit(next_robot2))  Push(next_robot2);
        }
        //robot의 윗부분
        Next_range.x1 = Next_range.x2 = robot.x1 - 1;
        if (isRange(Next_range, board))
        {
            Robot next_robot(robot.x1 - 1, robot.y1, robot.x1, robot.y1, Row, robot.sec + 1);
            Robot next_robot2(robot.x2 - 1, robot.y2, robot.x2, robot.y2, Row, robot.sec + 1);
            if (!IsVisit(next_robot)) Push(next_robot);
            if (!IsVisit(next_robot2))  Push(next_robot2);
        }
    }
}
int search(const Board& board)
{
    robots.push(Robot());
    while (!robots.empty())
    {
        Robot robot = robots.front();
        robots.pop();
        if ((robot.x2 == MapSize - 1 && robot.y2 == MapSize - 1))
        {
            return robot.sec;
        }
        //Go
        for (int i = 0; i < 4; i++)
        {
            Robot next_robot(robot.x1 + dx[i], robot.y1 + dy[i], robot.x2 + dx[i], robot.y2 + dy[i], robot.direct, robot.sec + 1);
            if (isRange(next_robot, board) && !IsVisit(next_robot))  Push(next_robot);
        }
        RotateAndPush(robot, board);
    }
    return 1234567890;
}