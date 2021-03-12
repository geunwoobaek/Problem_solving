#include <bits/stdc++.h>
using namespace std;
#define Pair pair<int, int>
#define Block vector<Pair>
#define y first
#define x second
#define fill true
#define empty false
int N; //N(1 ≤ N ≤ 10,000)
int Map[11][11];
int dy[2] = {1, 0}, dx[2] = {0, 1};
int score = 0;
vector<Block> blocks = {{{0, 0}}, {{0, 0}, {0, 1}}, {{0, 0}, {1, 0}}};
bool isRange(Block &next)
{
    for (auto &cur : next)
    {
        if (cur.y > 10 || cur.x > 10 || Map[cur.y][cur.x] != 0)
            return false;
    }
    return true;
}
void goDown(int Y, int X, int mode) //밑으로 밀어넣기
{
    if (mode == 0)
        Map[Y][X] = Map[Y - dy[mode]][X - dx[mode]];
    else
        Map[X][Y] = Map[X - dy[mode]][Y - dx[mode]];
}
bool checkFill(int target, int mode)
{
    for (int i = 1; i <= 4; i++)
    {
        if (mode == 0)
        {
            if (Map[target][i] == 0)
                return empty;
        }
        else
        {
            if (Map[i][target] == 0)
                return empty;
        }
    }
    return fill;
}
bool checkEmpty(int target, int mode)
{
    for (int i = 1; i <= 4; i++)
    {
        if (mode == 0)
        {
            if (Map[target][i] != 0)
                return fill;
        }
        else
        {
            if (Map[i][target] != 0)
                return fill;
        }
    }
    return empty;
}
void removeLine(int target, int mode)
{
    for (int i = 1; i <= 4; i++)
    {
        if (mode == 0)
            Map[target][i] = 0;
        else
            Map[i][target] = 0;
    }
}
void moveBlock(Block &block, int mode)
{
    while (1) //go
    {
        Block next = block;
        for (auto &one : next)
        {
            one.y += dy[mode];
            one.x += dx[mode];
        }
        if (isRange(next))
            swap(block, next);
        else
            break;
    }
}
void FillBlock(Block &block, int block_num)
{
    for (auto &one : block)
        Map[one.y][one.x] = block_num;
}
void simulation(Block init_block, int y, int x, int block_num)
{
    for (auto &block : init_block)
    {
        block.y += y;
        block.x += x;
    }
    for (int mode = 0; mode < 2; mode++)
    {
        Block block = init_block;
        //1. 블록 이동
        moveBlock(block, mode);
        //2.블록채우기
        FillBlock(block, block_num);
        //3. 라인이 완성됐는지 보기
        //밑에서부터 확인후 제거 되면 제거 된 윗지점부터 밑으로 내려오게 하기
        int prev_score = -1;
        while (prev_score != score) //제거되는게 없을때까지
        {
            prev_score = score;
            int remove_point = 0;
            for (int Y = 10; Y >= 5; Y--)
            {
                if (checkFill(Y, mode) == fill)
                {
                    removeLine(Y, mode);
                    remove_point = Y;
                    score++;
                }
            }
            if (prev_score != score)
            {
                for (int Y = remove_point - 1; Y >= 5; Y--)
                {
                    for (int X = 1; X <= 4; X++)
                    {
                        int mode_y = Y, mode_x = X;
                        if (mode == 1)
                            swap(mode_y, mode_x);
                        if (Map[mode_y][mode_x] == 0)
                            continue;
                        Block next_block, start_block;
                        //옆에꺼랑 붙어있는경우
                        if (mode_x <= 3 && Map[mode_y][mode_x] == Map[mode_y + dx[mode]][mode_x + dy[mode]])
                            start_block = {{mode_y, mode_x}, {mode_y + dx[mode], mode_x + dy[mode]}};
                        //혼자인경우
                        else
                            start_block = {{mode_y, mode_x}};

                        next_block = start_block;
                        moveBlock(next_block, mode);
                        FillBlock(next_block, Map[mode_y][mode_x]);
                        FillBlock(start_block, 0);
                    }
                }
            }
            //4. 옅은줄에 걸쳤는지 확인
            int go = 0;
            if (checkEmpty(5, 0) != empty)
                go = 2;
            else if (!checkEmpty != empty)
                go = 1;
            //밑으로 밀어넣기
            while (go-- > 0)
            {
                int Y, X;
                for (Y = 10; Y >= 5; Y--)
                    for (X = 1; X <= 4; X++)
                        goDown(Y, X, mode);
            }
        }
    }
    cout << "";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int num = 1;
    while (N-- > 0)
    {
        int y, x, what;
        cin >> what >> y >> x;
        simulation(blocks[what - 1], y + 1, x + 1, num++);
    }
    int cnt = 0;
    for (int i = 7; i <= 10; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (Map[i][j] != 0)
                cnt++;
            if (Map[j][i] != 0)
                cnt++;
        }
    }
    cout << score << "\n"
         << cnt;
    return 0;
}
