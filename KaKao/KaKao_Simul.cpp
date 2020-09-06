#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
//x,y,a(종류),명령타입
int Map[101][101]; //0이면 기둥 1이면 보 2이면 두개다
//x와y좌표순으로 담고있다
vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    memset(Map, -1, sizeof Map);
    vector<vector<int>> answer;
    return answer;
}
void simulation(int limit,vector<int> &command)
{
    int x = command[0];
    int y = command[1];
    if (command[3] == '0') //삭제
    {
        if (Map[x][y]!=command[2]||Map[x][y]!=2) //아무것도 삭제할게 없을경우에 끝냄
            return;          
        if (command[2] == 0) //기둥
        {
          if(Map[x][y+1]==-1&&Map[x-1][y+1]!=1) //위에 아무것도없을시
          {
            Map[x][y]--;
          }
          else{ //위에 뭐가있을경우
           //위의 왼쪽에 보가 있을경우 :그왼쪽에 기둥또는 더왼쪽에 보가있어야함
           if(x>0&&(Map[x-1][y+1]==1)) return;
           //위의 오른쪽에 보가 있을경우 :그오른쪽에 기둥이 있거나 그오른쪽에 보가 있어야함
           if(x<limit-1&&(Map[x][y+1]==1&&Map[x][y]) return;
           //위의 바로위에 기둥이 있을경우 :해당지점의 오른쪽또는 왼쪽에 보가 있어야함
            if(Map[x][y+1]==0)
            {
                if(x>0&&Map[x-1][y+1]<1) return ;
            }
            Map[x][y]--;
          }
        }
        else //보
        {   
            //왼쪽에 보가있는지 체크 
            //있다면 보만 있으면 삭제 x
            if(x>0&&Map[x-1][y]==1) return ;
            //오른쪽에 보가 있는지 체크
            //오른쪽에 보만있는경우 삭제 x
            if(x<limit-1&&Map[x+1][y]==1) return ;
            //보의 위에 기둥이 있는지 체크
            //있다면 다른 바칠곳이 있는지 체크
      
            //보위에 기둥이있다면
            //보의 오른쪽부분에 기둥이 있는경우 : 기둥의 밑부분에 기둥또는 다른 보가 있어야한다.
            if(Map[x+1][y]==1 &&(Map[x+1][y-1]!=0&&Map[x+1][y-1]!=2)) return ;
            //보의 왼쪽부분에 기둥이있는경우 :;;
            if(Map[x][y]==1 &&(Map[x][y-1]!=0&&(Map[x-1][y]<1))) return ;

        }
    }
    else //설치
    {
        if (Map[x][y] == 2 || Map[x][y] == command[2])
            return; //이미있는경우 return

        if (command[2] == 0) //기둥
        {
            if (y == 0) //바닥에있을경우
            {
                Map[x][y]++;
            }
            else 
            {   //바닥설치가 아닌경우
                if(Map[x][y-1]==0||Map[x][y-1]==2) //밑에 기둥이있다면
                {
                    Map[x][y]++;
                }
                else if(Map[x][y]==1||(x>0&&Map[x-1][y]>=1))//밑에 보가있다면
                {
                    Map[x][y]++;
                }
            }
        }
        else //보
        { 
            if(y==0) return; //바닥이라면
            if(Map[x][y-1]==0&&(x<limit-1&&Map[x+1][y]==0)) //밑에 기둥이있다면
            {
                Map[x][y]++; 
            }
            else{
                if(x==0) return; 
                if(Map[x-1][y]>=0&&Map[x+1][y]>=0) //양옆에 보가있다면
                {
                    Map[x][y]++;
                }
            }
        }
    }
}