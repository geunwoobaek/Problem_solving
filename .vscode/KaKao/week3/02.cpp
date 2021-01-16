#include<bits/stdc++.h>
using namespace std;

struct Block {
    int y, x, shpae;
};
int board_size;
#define For(i,j,k) for(int i=j;i<k;i++)
vector<vector<Block>> Blocks(1); //블록 담겨있음

void FillBlack(vector<vector<int>>& board) {
    For(x, 0, board_size) {
        For(y, 0, board_size) {
            if (board[y][x] > 0) break;
            else board[y][x] = -1; //black
        }
    }
}

int solution(vector<vector<int>> board) {
    board_size = board.size();
    int numberofBlocks=0;
    For(y, 0, board_size) For(x, 0, board_size) numberofBlocks = max(numberofBlocks, board[y][x]); //Blcoks갯수구하기

    Blocks.resize(numberofBlocks); //Blocks사이즈정해주기

    For(y, 0, board_size) {
        For(x, 0, board_size) {
            if (board[y][x] != 0) Blocks[board[y][x]-1].push_back({ y,x });   
        }
    }

    FillBlack(board);

    while (1) {
        int prev_block_size = Blocks.size();
        vector<vector<Block>>::iterator it = Blocks.begin();
        while (it != Blocks.end()) {
         
           
        }
    }
int answer = 0;
return answer;
}
