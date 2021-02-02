#include <bits/stdc++.h>
using namespace std;
#define Board vector<vector<int>>
int answer = 2e9;
//방문처리를 해야하는데 중요한 포인트
bool isVisit[(1 << 6) + 1][4][4][5][5]; //첫번째는 먹은카드에 관해서 비트연산 //두번째 세번째는 커서위치
//4번째 5번째는 뒤집은카드위치
int full;
struct Dir
{
    int y[4] = {0, 0, 1, -1};
    int x[4] = {1, -1, 0, 0};
} dir;
struct Cursor
{
    int y, x;
    int card = 0;   // 이전에 뒤집은 카드
    int card_y = 4; //이전카드 위치 4는 뒤집은카드 없을때
    int card_x = 4; //이전카드 위치 4는 뒤집은카드 없을때
    int eat = 0;
    //
};
bool isRange(Cursor &cursor);
bool alreadyAteorNone(Cursor &cursor, int card);
void CtrlMove(Cursor &cursor, int cmd, Board &board);
bool IsVisit(Cursor &cursor);
void CheckVisit(Cursor &cursor);
void dfs(Board &board, Cursor cursor, int move_count);
void godfs(Cursor &cursor, Board &board, int move_count);
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
    card_count /= 2;
    full = (1 << card_count) - 1;
    CheckVisit(cursor);
    dfs(board, cursor, 0);
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
bool isRange(Cursor &cursor)
{
    return cursor.y < 4 && cursor.y >= 0 && cursor.x < 4 && cursor.x >= 0;
}
bool alreadyAteorNone(Cursor &cursor, int card)
{ //이미 먹었거나 없는 블록일경우
    return card == 0 || (card != 0 && (cursor.eat & card) != 0);
}
void CtrlMove(Cursor &cursor, int cmd, Board &board)
{
    int &card = board[cursor.y][cursor.x];
    while (isRange(cursor) && alreadyAteorNone(cursor, card))
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
    return isVisit[cursor.eat][cursor.y][cursor.x][cursor.card_y][cursor.card_x];
}
void CheckVisit(Cursor &cursor)
{
    isVisit[cursor.eat][cursor.y][cursor.x][cursor.card_y][cursor.card_x] = !IsVisit(cursor);
}
void godfs(Cursor &cursor, Board &board, int move_count)
{
    if (!IsVisit(cursor))
    {
        CheckVisit(cursor);
        dfs(board, cursor, move_count);
        CheckVisit(cursor);
    }
}
void dfs(Board &board, Cursor cursor, int move_count)
{
    if (answer <= move_count || move_count > 20)
        return;
    if (cursor.eat == full)
        answer = move_count;
    //do enter
    Cursor temp = cursor;
    temp.card = board[cursor.y][cursor.x];
    temp.card_x = cursor.x;
    temp.card_y = cursor.y;

    if (!IsVisit(temp) && !alreadyAteorNone(cursor, temp.card)) //카드 잡힐경우 이때 이전에 잡았던 카드는 안됨.
    {
        Cursor temp2 = temp;
        if (cursor.card != 0 && (temp.card != cursor.card)) //현재가지고있는카드는 0이아니고 서로다른카드일경우
        {   
            CheckVisit(temp2);
            temp.card = 0;
            temp.card_x = temp.card_y = 4;
        }
        else if (cursor.card == temp.card)
        {   
            CheckVisit(temp2);
            temp.eat += (1 << (temp.card - 1));
            temp.card = 0;
            temp.card_x = 4;
            temp.card_y = 4;
        }
        godfs(temp, board, move_count + 1);
    }
    //단순이동+ctrl이동
    for (int i = 0; i < 4; i++)
    { //단순이동
        temp = cursor;
        temp.y += dir.y[i];
        temp.x += dir.x[i];
        if (isRange(temp)) godfs(temp, board, move_count + 1);
        temp = cursor;
        CtrlMove(temp, i, board);
        godfs(temp, board, move_count + 1);
    }
}