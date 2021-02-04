#include <bits/stdc++.h>
using namespace std;
struct Record
{
    int count, time;
} record; //첫번째는 count 두번째는 시간
int convert(string str)
{
    int hour = stoi(str.substr(0)) * 3600;
    int min = stoi(str.substr(3)) * 60;
    int sec = stoi(str.substr(6));
    return hour + min + sec;
}
vector<vector<int>> logvecs;
//로그의 시작시간이 적은것부터 담기
//1. 끝지점이 적은 대로 정렬
//2. 우선순위큐에 데이터의 시작지점에 대해서 넣기
//3. 끝점-시작지점이 새로읽는데이터의 시작지점보다 크거나같으면 continue,
//4. 아닐시 뱉어내기
//5. MaxCount일시 값저장
bool cmp(vector<int> a, vector<int> b)
{
    if (a[1] != b[1])
        return a[1] < b[1];
    else
        return a[0] < b[0];
}
bool operator<(vector<int> a,vector<int> b){ //끝지점이 작은순으로넣음
    return a[1]>b[1];
}
string solution(string play_time, string adv_time, vector<string> logs)
{
    string answer = "";
    int playtime = convert(play_time);
    int advtime = convert(adv_time);
    for (auto &log : logs)
    {
        int start_ = convert(log.substr(0, 8));
        int end_ = convert(log.substr(9));
        logvecs.push_back({start_, end_});
    }
    sort(logvecs.begin(), logvecs.end(), cmp);
    priority_queue<vector<int>,vector<vector<int>>> q;
    int count = 0;
    for (auto &now : logvecs)
    {
        count++;
        q.push(now);
        while (!q.empty())
        {
            if(q.top()-advtime
        }
    }
}
int main()
{

    cout << convert("11:11:11");
}