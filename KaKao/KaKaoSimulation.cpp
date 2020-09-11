#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int Map[101][101]; //0이면 기둥 1이면 보 2이면 두개다
bool compare(vector<int>& a, vector<int>& b)
{
    if (a[0] != b[0])
        return a[0] < b[0];
    else if (a[1] != b[1])
        return a[1] < b[1];
    else
        return a[2] < b[2];
}
void cache(int n,vector<int> &command)
{ 
int x=command[0];
int y=command[1]; 
int what=command[2]; //if 기둥 or 보
int how=command[3]; //설치 or 삭제
if(how==1) //설치
{

}
else { //삭제

}
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    memset(Map, -1, sizeof Map);
    vector<vector<int>> answer;
    for (auto i : build_frame)
    {
       cache(n,i);
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
