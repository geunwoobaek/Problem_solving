#include<iostream>
#include<vector>
#include <cstdio>
#include <string>  
using namespace std;
#define Pair pair<int,vector<int>>
vector<int> date(4); //10,1,3600 월,일,시간
vector<int> Maxdate(13, 31); //11,9,6,4,2
void add(int minute, vector<int>& date)
{
    date[2] += minute * 60;
    if (date[2] >= 3600*24)
        date[1] += (date[2] /  3600*24);
    date[2] %= 3600*24;
    int cur = Maxdate[date[0]];
    date[0] += date[1] / Maxdate[date[0]];
    date[1] %= cur;
}
void push_date(string data, vector<int>& date_)
{
    date_[0] = (stoi(data.substr(0, 2)));
    date_[1] = (stoi(data.substr(3, 2)));
    int time = stoi(data.substr(6, 2)) * 60 * 60;
    time += stoi(data.substr(9, 2)) * 60;
    time += stoi(data.substr(12, 2));
    date_[2] = time;
    date_[3] = stoi(data.substr(15, 2));
}
void setting()
{
    Maxdate[2] = 28;
    Maxdate[4] = 30;
    Maxdate[6] = 30;
    Maxdate[9] = 30;
    Maxdate[11] = 30;
}
struct compare {
    bool operator()(Pair& a, Pair& b) {
        if (a.second[0] != b.second[0])
        {
            return a.second[0] > b.second[0];
        }
        if (a.second[1] != b.second[1])
        {
            return a.second[1] > b.second[1];
        }
        return a.second[2] > b.second[2];
    }
};
int main()
{
    int currenttime = 0;
    push_date("10/01 23:20:25 30", date);
    // date.push_back(10);
    // date.push_back(31);
    // date.push_back(3540);
    // add(1,date);
    // priority_queue<Pair,vector<Pair>,compare> que;

    // while(!customer.empty())
    // {   int cur=
    //     while(que.size()!=FULL)
    //     {
    //         집어넣기
    //     }

    // }
    cout << "";
}