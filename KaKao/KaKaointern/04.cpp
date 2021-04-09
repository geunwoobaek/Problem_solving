#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dir_y[4] = { 1, -1, 0, 0 };
int dir_x[4] = { 0, 0, 1, -1 };
int dir = 0;
bool check[26][26] = { false, };
vector<int> visit[4][25];
int result = 2e9+1e8;
void DFS(vector<vector<int>> board, int y, int x, int direction, int money) {
   if (y == board.size() - 1 && x == board.size() - 1) {
      if (result > money) result = money;
      return;
   }
   for (int i = 0; i < 4; i++) {
      int next_y = dir_y[i] + y;
      int next_x = dir_x[i] + x;
      if (next_y >= 0 && next_y < board.size() && next_x >= 0 && next_x < board.size()) {
         if (next_y == y + dir_y[direction] && next_x == x + dir_x[direction]&&visit[direction][next_y][next_x]>money+100)
         {
            visit[direction][next_y][next_x]=money+100;
            if (check[next_y][next_x] == false) {
               check[next_y][next_x] = true;
               DFS(board, next_y, next_x, direction, money + 100);
               check[next_y][next_x] = false;
            }
         }
       else if (check[next_y][next_x] == false&&visit[direction][next_y][next_x]>money+600) {
            visit[direction][next_y][next_x]=money+600;
            DFS(board, next_y, next_x, i, money + 600);
            check[next_y][next_x] = false;
         }
      }
   }
}


int solution(vector<vector<int>> board) {
   int answer = 0;
   for(int i=0;i<4;i++)
   {
   for(int j=0;j<board.size();j++){
       visit[i][j].resize(board.size(),2e9+1e8);
        visit[i][0][0]=0;
   }
   }
   check[0][0] = true;
   DFS(board, 0, 0, 2, 0);
   DFS(board, 0, 0, 0, 0);
   answer = result;
   return answer;
}