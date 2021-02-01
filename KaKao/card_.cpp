#include <bits/stdc++.h>
using namespace std;
#define Board vector<vector<int>>
int answer = 2e9;
//방문처리를 해야하는데 중요한 포인트
bool isVisit[(1 << 6) + 1][4][4][2]; //첫번째는 먹은카드에 관해서 비트연산 //두번째 세번째는 위치 4번쨰는 먹었나 안먹었나
struct Dir
{
    int y[4] = {0, 0, 1, -1};
    int x[4] = {1, -1, 0, 0};
} dir;
struct Cursor
{
    int y, x;
    int card = 0;   //현재 선택된 카드
    int card_y = 0; // 위치
    int card_x = 0; // 위치
    int eat = 0;
    //
};

bool isRange(Cursor &cursor)
{
    return cursor.y < 4 && cursor.y >= 0 && cursor.x < 4 && cursor.x >= 0;
}
void CtrlMove(Cursor &cursor, int cmd, Board &board)
{
    while (isRange(cursor) && board[cursor.y][cursor.x] == 0)
    {
        cursor.y += dir.y[cmd];
        cursor.x += dir.x[cmd];
    }
    if (!isRange(cursor))
    {
        cursor.y -= dir.y[cmd];
        cursor.x -= dir.x[cmd];
    }
}
bool IsVisit(Cursor &cursor)
{
    return isVisit[cursor.eat][cursor.y][cursor.x][cursor.card != 0];
}
bool CheckVisit(Cursor &cursor)
{
    isVisit[cursor.eat][cursor.y][cursor.x][cursor.card != 0] = !isVisit[cursor.eat][cursor.y][cursor.x][cursor.card != 0];
}
void dfs(Board &board, Cursor cursor, int move_count, int card_count)
{
    if (answer <= move_count)
        return;
    if (card_count == 0)
        answer = move_count;
    //enter작업
    if (board[cursor.y][cursor.x] != 0) //카드 잡힐경우 이때 이전에 잡았던 카드는 안됨.
    {
        Cursor copy = cursor;
        copy.card=
        int nowcard = board[cursor.y][cursor.x];      //현재카드
        if (cursor.card != nowcard && !IsVisit(copy)) //이전카드가 다른카드일경우
        {
            copy.card_x = cursor.x;
            copy.card_y = cursor.y;
            copy.card = nowcard;
            CheckVisit(copy);
            dfs(board, copy, move_count + 1, card_count);
            CheckVisit(copy);
        }
        else if (!IsVisit(copy) && cursor.card == nowcard && !(cursor.y == cursor.card_y && cursor.x == cursor.card_x)) //이전 짝찾았을경우
        {
            //이전에 선택한게 아니고 짝을 찾았을때
            board[cursor.y][cursor.x] = board[cursor.card_y][cursor.card_x] = 0; //지우기
            copy.eat += (1 << cursor.card);
            copy.card = copy.card_x = copy.card_y = 0;
            CheckVisit(copy);
            dfs(board, copy, move_count + 1, card_count - 1);
            CheckVisit(copy);
            board[cursor.y][cursor.x] = board[cursor.card_y][cursor.card_x] = nowcard; //살려내기
            return;
        }
    }
    //단순이동+ctrl이동
    for (int i = 0; i < 4; i++)
    { //단순이동
        Cursor copy = cursor;
        copy.y += dir.y[i];
        copy.x += dir.x[i];
        if (isRange(copy) && !IsVisit(copy))
        {
            CheckVisit(copy);
            dfs(board, copy, move_count + 1, card_count);
            CheckVisit(copy);
        }
        //ctrl이동
        Cursor ctrl_copy = cursor;
        CtrlMove(ctrl_copy, i, board);
        if (IsVisit(ctrl_copy))
        {
            CheckVisit(ctrl_copy);
            dfs(board, ctrl_copy, move_count + 1, card_count);
            CheckVisit(ctrl_copy);
        }
    }
}
int solution(Board board, int r, int c)
{
    Cursor cursor = {r, c};
    int card_count = 0;
    for (auto line : board)
    {
        for (auto one : line)
        {
            if (one > 0)
                card_count++;
        }
    }
    CheckVisit(cursor);
    dfs(board, cursor, 0, card_count / 2);
    return answer;
}
int main()
{
    cout << solution(
        {{1, 0, 0, 3},
         {2, 0, 0, 0},
         {0, 0, 0, 2},
         {3, 0, 1, 0}},
        1, 0);
}