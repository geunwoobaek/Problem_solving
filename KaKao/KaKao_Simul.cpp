#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
//x,y,a(종류),명령타입
int Map[101][101]; //0이면 기둥 1이면 보 2이면 두개다
//x와y좌표순으로 담고있다
bool compare(vector<int>& a, vector<int>& b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    else if (a[1] != b[1])
        return a[1] < b[1];
    else
        return a[2] < b[2];
}
void simulation(int limit, vector<int>& command)
{
    int x = command[0];
    int y = command[1];
    //보는 항상 기둥위에있다 기둥의 y=k 보는 k+1
    if (command[3] == 0) //삭제
    {
        if (command[2] == 0) //기둥
        {
            int& nowColum = Map[x][y];                                           //범위넘어설때
            if (Map[x][y + 1] == -1 && (x < 1 || Map[x - 1][y + 1] < 1)) //위에 아무것도없을시
            {
                nowColum-=(command[2]+1);
            }

            else //위에 뭐가있을경우
            {   if(Map[x][y+1]==0) return; //바로위에 벽이있을때
                //위에 두개가 다있을경우
                if (x > 0 && Map[x][y + 1] != -1 && Map[x - 1][y + 1] != -1)
                {
                    int right = x;
                    int left = x - 1;
                    bool right_condition = false;
                    bool left_condition = false;
                    while (Map[right][y + 1] != -1)
                    {
                        if (Map[right++][y] % 2 == 0)
                        {
                            right_condition = true;
                            break;
                        }
                    }
                    if (!right_condition) return;
                    while (left >= 0 && Map[left][y + 1] != -1)
                    {
                        if (Map[left--][y] % 2 == 0)
                        {
                            left_condition = true;
                            break;
                        }
                    }
                    if (!left_condition) return;
                }
                //위에 하나만있을경우
                else
                {
                    if ((x > 0 && Map[x - 1][y + 1]>0) &&Map[x-1][y]%2!=0)
                        return; //왼쪽기둥
                    else if ((x < limit && Map[x][y + 1]>0) &&Map[x+1][y]%2!=0)
                        return; //오른쪽기둥
                }
            }
            nowColum-=(command[2]+1);
        }
        else //보
        {
            int& Road = Map[x][y];
            bool left=false, right=false, leftBottom_Colum=false, RightBottom_Colum=false, leftTop_Colum=false, RightTop_Colum=false;
            bool Double_left=false, Double_right=false;
            if (Road == 2)
                leftTop_Colum = true;
            if (x < limit && Map[x + 1][y])
                RightTop_Colum = true;
            if (Map[x][y - 1] % 2 == 0)
                leftBottom_Colum = true;
            if (x < limit && Map[x + 1][y - 1] % 2 == 0)
                RightBottom_Colum = true;
            if (Map[x - 1][y] >= 1)
                left = true;
            if (Map[x + 1][y] >= 1)
                right = true;
            if (x > 1 && Map[x - 1][y - 1] % 2 == 0)
                Double_left = true;
            if (x < limit - 1 && Map[x + 2][y - 1] % 2 == 0)
                Double_right = true;
            //체크
            if (left && !Double_left && !leftBottom_Colum)
                return;
            if (right && !RightBottom_Colum && !Double_right)
                return;
            if (leftTop_Colum && !leftBottom_Colum && !left)
                return;
            if (RightTop_Colum && !RightBottom_Colum && !right)
                return;

            Road-=(command[2]+1);
            //삭제할때 양옆에 뭐가 있는지 확인
        }
    }
    else //설치
    {
        if (Map[x][y] % 2 == 0||Map[x][y]==command[2])
            return; //이미있는경우 return

        if (command[2] == 0) //기둥
        {
            if (y == 0) //바닥에있을경우
            {
                Map[x][y]++;
            }
            else
            {                                                                                   //바닥설치가 아닌경우
                if (Map[x][y - 1] % 2 == 0 || (Map[x][y] == 1 || (x > 0 && Map[x - 1][y] > 0))) //밑에 무엇이라도 있다면
                {
                    Map[x][y]++;
                }
            }
        }
        else //보
        {
            if (y == 0)
                return;
            //바닥이라면
            else
            {
                if (Map[x][y - 1] % 2 == 0)
                    Map[x][y] = 1; //바닥에 뭐가있다면
                else if (x < limit && Map[x + 1][y - 1] % 2 == 0)
                    Map[x][y] = 1;                                                       //오른쪽바닥에 뭐가있다면
                else if (x > 0 && x < limit && Map[x - 1][y] >= 1 && Map[x + 1][y] >= 1) //양옆에 보가있다면
                {
                    Map[x][y] = 1;
                }
            }
        }
    }
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    memset(Map, -1, sizeof Map);
    vector<vector<int>> answer;
    for (auto i : build_frame)
    {
        simulation(n, i);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            vector<int> current(3);
            if (Map[i][j] <0)
                continue;
            current[0] = i;
            current[1] = j;
            if (Map[i][j] != 2)
            {
                current[2] = Map[i][j];
                answer.push_back(current);
            }
            else
            {
                current[2] = 0;
                answer.push_back(current);
                current[2] = 1;
                answer.push_back(current);
            }
        }
    }
    sort(answer.begin(), answer.end(), compare);
    return answer;
}
void push_test(vector<vector<int>>& answer, int a, int b, int c, int d)
{
    vector<int> build_frame(4);
    int i = 0;
    build_frame[i++] = a;
    build_frame[i++] = b;
    build_frame[i++] = c;
    build_frame[i++] = d;
    answer.push_back(build_frame);
}
//command[2]=대상
int main()
{
    //  memset(Map, -1, sizeof Map);
    vector<vector<int>> build_frame;
    push_test(build_frame, 0, 0, 0, 1);
    push_test(build_frame, 2, 0, 0, 1);
    push_test(build_frame, 4, 0, 0, 1);
    push_test(build_frame, 0, 1, 1, 1);
    push_test(build_frame, 1, 1, 1, 1);
    push_test(build_frame, 2, 1, 1, 1);
    push_test(build_frame, 3, 1, 1, 1);
    push_test(build_frame, 2, 0, 0, 0);
    push_test(build_frame, 1, 1, 1, 0);
    push_test(build_frame, 2, 2, 0, 1);
    solution(5, build_frame);
    return 0;
}