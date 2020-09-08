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
//command[2]=대상
void simulation(int limit, vector<int> &command)
{
    int x = command[0];
    int y = command[1];
    //보는 항상 기둥위에있다 기둥의 y=k 보는 k+1
    if (command[3] == '0') //삭제
    {
        if (Map[x][y] != command[2] || Map[x][y] != 2) //아무것도 삭제할게 없을경우에 끝냄
            return;
        if (command[2] == 0) //기둥
        {
            int &nowColum = Map[x][y];
            if (y == limit - 1)
                return;                                                    //범위넘어설때
            if (Map[x][y + 1] == -1 && (x == 0 || Map[x - 1][y + 1] != 1)) //위에 아무것도없을시
            {
                nowColum--;
            }
            else //위에 뭐가있을경우
            {
                //위에 두개가 다있을경우
                if (x > 0 && Map[x][y + 1] != -1 && Map[x - 1][y + 1] != -1)
                {
                    int right = x;
                    int left = x - 1;
                    bool right_condition = false;
                    bool left_condition = false;
                    while (Map[right][y + 1] != -1)
                    {
                        if (Map[right][y + 1] == 0 || Map[right++][y + 1] == 2)
                        {
                            right_condition = true;
                            break;
                        }
                    }
                    if (!right_condition)
                        return;
                    while (left > 0 && Map[left][y + 1] != -1)
                    {
                        if (Map[left][y + 1] == 0 || Map[left--][y + 1] == 2)
                        {
                            left_condition = true;
                            break;
                        }
                    }
                     if (!left_condition)
                        return;
                }
                //위에 하나만있을경우
                else
                {
                    if ((x > 0 && Map[x - 1][y + 1] == 1) && (Map[x - 1][y] != 2 || Map[x - 1][y] != 0))
                        return; //왼쪽기둥
                    else if (Map[x - 1][y] != 0 && Map[x - 1][y] != 2)
                        return; //오른쪽기둥
                }
            }
            nowColum--;
        }
        else //보
        {   
            int& Road=Map[x][y];
            //삭제할때 위에 뭐가있는지 확인
            if(Road==2) //왼쪽위벽검사
            {

            }
            if(x>0&&Map[x+1][y]==0) //오른쪽위벽검사
            {

            }
            //삭제할때 양옆에 뭐가 있는지 확인
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
            {                                                                  //바닥설치가 아닌경우
                if (Map[x][y - 1] != -1 || (x > 0 && Map[x - 1][y - 1] != -1)) //밑에 무엇이라도 있다면
                {
                    Map[x][y]++;
                }
            }
        }
        else //보
        {
            if (y == 0)
                return;                                                          //바닥이라면
            if (Map[x][y - 1] == 0 && (x < limit - 1 && Map[x + 1][y - 1] == 0)) //밑에 기둥이있다면
            {
                Map[x][y]++;
            }
            else
            {
                if (x == 0 || x == limit - 1)
                    return;
                if (Map[x - 1][y] >= 0 && Map[x + 1][y] >= 0) //양옆에 보가있다면
                {
                    Map[x][y]++;
                }
            }
        }
    }
}