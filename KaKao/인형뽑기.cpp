#include <string>
#include <vector>
#include<iostream>
using namespace std;
#define FOR(i,end,start) for(int i=start;i<end;i++)

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int answer = 0;
    vector<int> stac;
    FOR(i,moves.size(),0)
    {
        FOR(j,board.size(),0)
        {
            if(board[j][moves[i]-1]!=0)
            {
                if(stac.size()>0&&stac.back()==board[j][moves[i]-1]){ stac.pop_back();
                answer+=2;
                }
                else stac.push_back(board[j][moves[i]-1]);
               while(stac.size()>0&&stac.back()==stac[stac.size()-2])
               {
                stac.erase(stac.end()-3,stac.end());
                answer+=2;
               }
               board[j][moves[i]-1]=0;
               break;
            }
        }
    }
    
  //  cout<<"";
    return answer;
}
int main()
{
vector<vector<int>> board(5);
vector<int> moves(8);
FOR(i,5,0) board[i].resize(5);
//,[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
board[1]={0,0,1,0,3};
board[2]={0,2,5,0,1};
board[3]={4,2,4,4,2};
board[4]={3,5,1,3,1};
moves={1,5,3,5,1,2,1,4};

solution(board,moves);

return 0;
}