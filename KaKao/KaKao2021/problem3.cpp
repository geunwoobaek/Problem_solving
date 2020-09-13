#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
struct user
{
    // string &word= //언어
    // string &work; //직군
    // string &career;//경력
    // string soulfood; //소울푸드
    string info[4];
    int score; //점수
};
bool compare(user a, user b)
{
    for (int i = 0; i < 4; i++)
    {
        if (a.info[i] != a.info[i])
            return a.info[i][0] > b.info[i][0];
    }
    return a.score > b.score;
}

// 언어	직군	경력	소울 푸드	점수
// java	backend	junior	pizza	150
// python	frontend	senior	chicken	210
// python	frontend	senior	chicken	150
// cpp	backend	senior	pizza	260
// java	backend	junior	chicken	80
// python	backend	senior	chicken	50

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<user> uservec(info.size());
    for (int i = 0; i < info.size(); i++)
    {
        int start = 0;
        int index = 0;
        user &nowuser = uservec[i];
        for (int j = 0; j < info[i].size(); j++)
        {
            if (index != 4)
            {
                if (info[i][j] == ' ')
                {
                    nowuser.info[index++] = info[i].substr(start, j);
                    j+=4;
                    start=j;
                }
            }
            else
                nowuser.score = stoi(info[i].substr(start, j + 1));
        }
    }
    vector<int> answer;
    return answer;
}

int main()
{
    int k = '1';
    int ten = '9';
    string u[5]; 
    string u[0] = "java and backend and junior and pizza 100";
    string u[1] = "python and frontend and senior and chicken 200";
    string u[2] = "cpp and - and senior and pizza 250";
    string u[3] = "- and backend and senior and - 150";
    string u[4] = "- and - and - and - 150";
    vector<string> info(5);
    for(int i=0;i<info.size();i++) info[i]=u[0];
    solution(info,info);
    return 0;
}