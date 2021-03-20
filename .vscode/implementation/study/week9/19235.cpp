#include <bits/stdc++.h>
using namespace std;
#define Board vector<vector<int>>
struct Block
{
    int y, x;
};
int score = 0, number_blocks = 0;
Board green_board(6, vector<int>(4));
Board blue_board(6, vector<int>(4));
vector<vector<Block>> Blocks({{{0, 0}}, {{0, 0}}, {{0, 0}, {0, 1}}, {{0, 0}, {1, 0}}});
int N;
void rotate(vector<Block> &blocks) 
{
    for (auto &block : blocks)
        swap(block.y, block.x);
}
bool isRange(Board &board, vector<Block> blocks)
{
    for (auto &block : blocks)
    {
        if (block.y <= 5 && block.y >= 0 && block.x >= 0 && block.x <= 3 && board[block.y][block.x] == 0)
            continue;
        return false;
    }
    return true;
}
void down(int number, Board &board, vector<Block> blocks)
{
    for (auto &block : blocks)
        board[block.y][block.x] = 0;
    while (1)
    {
        vector<Block> next = blocks;
        for (auto &block : next)
            block.y += 1;
        if (isRange(board, next))
            swap(next, blocks);
        else
            break;
    }
    for (auto &block : blocks)
        board[block.y][block.x] = number;
}
vector<Block> comb_block(Board &board, int y, int x)
{
    vector<Block> blocks({{y, x}});
    int number = board[y][x];
    if (y >= 1 && board[y - 1][x] == number)
        blocks.push_back({y - 1, x});
    else if (y <= 1 && board[y + 1][x] == number)
        blocks.push_back({y + 1, x});
    else if (x <= 2 && board[y][x + 1] == number)
        blocks.push_back({y, x + 1});
    else if (x >= 1 && board[y][x - 1] == number)
        blocks.push_back({y, x - 1});
    return blocks;
}
void go(int number, Board &board, vector<Block> blocks)
{
    //  
    int rotate_y = 100; //평행이동지점
    for (auto &block : blocks)
        rotate_y = min(rotate_y, block.y);
    for (auto &block : blocks)
    {
        block.y -= rotate_y; //평행이동 및 board에 채워넣기
    }

    //2.막히는 지점이 나올때까지 떨어트리기
    down(number, board, blocks);
    int before = -1;
    //3.지울 수 있는걸 한번에 다 지우기 밑에서 부터 체크
    while (before != score)
    {
        before = score;
        for (int y = 0; y <=5; y++)
        {
            int line_length = 0;
            for (int x = 0; x <= 3; x++)
            {
                if (board[y][x] != 0)
                    line_length++;
            }
            if (line_length == 4) //full
            {
                for (int x = 0; x <= 3; x++)
                    board[y][x] = 0;
                score++;
            }
        }
        //4.이때 같은 블록은 같이 떨어져야함 //어떻게 체크하지
        for (int y = 5; y >= 0; y--)
            for (int x = 0; x <= 3; x++)
                if (board[y][x] != 0)
                    down(board[y][x], board, comb_block(board, y, x)); //같은블록은 합쳐서 한번에 내리기;
    }
    //5. 3->4의 작업을 지울 수 있는게 없을때까지 반복
    //6 옅은부분 체크
    int howManyDown = 0;
    for (int y = 0; y <= 1 && howManyDown == 0; y++)
    {
        for (int x = 0; x <= 3; x++)
        {
            if (board[y][x] != 0)
            {
                howManyDown = 2 - y;
                break;
            }
        }
    }
    if (howManyDown > 0)
    {
        //7 옅은부분 만큼 밑으로 내리기
        for (int y = 5; y >= howManyDown; y--)
        {
            for (int x = 0; x <= 3; x++)
            {
                board[y][x] = board[y - howManyDown][x];
            }
        }
        //옅은부분 지우기
        for (int y = howManyDown-1; y >= 0; y--)
        {
            for (int x = 0; x <= 3; x++)
                board[y][x] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int num = 0;
    while (N-- > 0)
    {
        num++;
        int t, x, y;
        cin >> t >> y >> x;
        vector<Block> next = Blocks[t];
        for (auto &block : next)
        {
            block.y += y;
            block.x += x;
        }
        go(num, green_board, next); // 그린보드 작업
        rotate(next); ///블루보드에 넣기 위해 회전
        go(num, blue_board, next); //블루보드 작업
    }
    for (int y = 2; y <= 5; y++)
        for (int x = 0; x <= 3; x++)
        {
            if (green_board[y][x] != 0)
                number_blocks++;
            if (blue_board[y][x] != 0)
                number_blocks++;
        }
    cout << score << "\n" << number_blocks;
    return 0;
}