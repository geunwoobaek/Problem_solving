#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int N;
bool isFalse[50001];
struct user
{
    // string &word= //언어
    // string &work; //직군
    // string &career;//경력
    // string soulfood; //소울푸드
    string info[4];
    int score; //점수
};
struct user_query
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
        if (a.info[i] != b.info[i])
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
    vector<int> answer(info.size());
    vector<user> uservec(info.size());
    vector<user_query> queryvec(query.size());
    for (int i = 0; i < info.size(); i++)
    {
        int start = 0;
        int index = 0;
        user& nowuser = uservec[i];
        for (int j = 0; j < info[i].size(); j++)
        {
            if (index < 4)
            {
                if (info[i][j] == ' ')
                {
                    nowuser.info[index++] = info[i].substr(start, j - start);
                    if (index != 4)
                        j += 4;
                    start = j + 1;
                }
            }
            else
            {
                nowuser.score = stoi(info[i].substr(start, info.size() - 1 - start));
                break;
            }
        }
    }
    sort(uservec.begin(), uservec.end(), compare);
    for (int i = 0; i < query.size(); i++) //query읽기
    {
        int start = 0;
        int index = 0;
        user_query& now_query = queryvec[i];
        int range_Start = 0;
        int range_end = uservec.size();
        fill_n(isFalse, uservec.size(), false);
        for (int j = 0; j < query[i].size(); j++)
        {
            if (index < 4)
            {
                if (query[i][j] == ' ')
                {
                    now_query.info[index++] = query[i].substr(start, j - start);
                    string& cmp = now_query.info[index - 1];
                    if (cmp != "-") 
                    {

                        for (int idx = range_Start; idx < range_end; idx++) //찾기
                        {
                            bool check=(cmp!= uservec[idx].info[index - 1] && uservec[idx].info[index - 1] != "-"); //조건이성립하면
                            if (check) 
                                isFalse[idx] = true;
                        }
                    }
                    if (index != 4)
                        j += 4;
                    start = j + 1;
                }
            }
            else
            {
                now_query.score = stoi(query[i].substr(start, query.size() - 1 - start));
                bool on = false;
                for (int idx = range_Start;idx < range_end;idx++)
                {
                    if (!isFalse[idx])
                    {
                        answer[i]++;
                    }
                }
                break;
            }
        }
       // answer[i] = range_end- range_Start;
    }
    return answer;
}

int main()
{
    string st[]={"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    string qt[]={"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
   vector<string> info(6);
   vector<string> query(6);
    for(int i=0;i<6;i++)
    {
    info[i]=st[i];
    query[i]=qt[i];
    }
    solution(info, query);
    return 0;
}