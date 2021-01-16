#include <bits/stdc++.h>
using namespace std;

struct Block { int y, x, shpae;};
int board_size;
#define For(i, j, k) for (int i = j; i < k; i++)
#define BlockSet vector<vector<Block>>
#define It BlockSet::iterator 
BlockSet Blocks(1); //블록 담겨있음

void FillBlack(vector<vector<int>>& board)
{
    For(x, 0, board_size)
    {
        For(y, 0, board_size)
        {
            if (board[y][x] > 0)
                break;
            else
                board[y][x] = -1; //black
        }
    }
}
bool IsCanRemove(vector<vector<int>>& board, vector<Block>& block)
{
    //가장Left,가장Right,가장위,가장아래
    //가로로 길이가 3
    int min_x = 2e9, max_x = 0, min_y = 2e9, max_y = 0;
    for (Block& one : block)
    {
        min_x = min(one.x, min_x);
        max_x = max(one.x, max_x);
        min_y = min(one.y, min_y);
        max_y = max(one.y, max_y);
    }
    For(x, min_x, max_x + 1)
    {
        For(y, min_y, max_y + 1)
        {
            if (board[y][x] == -1 || board[y][x] == block[0].shpae)
                continue;
            else
                return false;
        }
    }
    return true;
}
void Remove(vector<vector<int>>& board, BlockSet& Blocks, It& block)
{
    for (auto& one : *block)
    {
        board[one.y][one.x] = 0;
    }
    block = Blocks.erase(block);
}
int solution(vector<vector<int>> board)
{
    board_size = board.size();
    int numberofBlocks = 0;
    For(y, 0, board_size) For(x, 0, board_size) numberofBlocks = max(numberofBlocks, board[y][x]); //Blcoks갯수구하기

    Blocks.resize(numberofBlocks); //Blocks사이즈정해주기

    For(y, 0, board_size)
    {
        For(x, 0, board_size)
        {
            if (board[y][x] != 0)
                Blocks[board[y][x] - 1].push_back({ y, x, board[y][x] });
        }
    }
    while (1)
    {
        FillBlack(board);
        int prev_block_size = Blocks.size();
        It block = Blocks.begin();
        while (block != Blocks.end())
        {
            if (IsCanRemove(board, *block))  
            {   
                 if(block->size()==0) numberofBlocks--;
                 Remove(board, Blocks, block); //in board
            }
            else block++;
        }
        if (prev_block_size == Blocks.size())
            return numberofBlocks - prev_block_size;
    }
}