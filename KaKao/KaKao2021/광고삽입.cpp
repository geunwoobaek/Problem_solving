#include <bits/stdc++.h>
using namespace std;
#define ll long long
int convert(string str)
{
    int hour = stoi(str.substr(0)) * 3600;
    int min = stoi(str.substr(3)) * 60;
    int sec = stoi(str.substr(6));
    return hour + min + sec;
}
struct Record
{
    ll sum = 0, start = 0, end = 0;
} record, temp;
string convertTostr(int time)
{
    string answer;
    int hour = time / 3600;
    int min = (time % 3600) / 60;
    int sec = (time % 60);
    string stime[3]{to_string(hour), to_string(min), to_string(sec)};
    for (auto &t : stime)
    {
        if (t.size() == 1)
            answer += "0";
        answer += t + ":";
    }
    answer.pop_back();
    return answer;
}
ll SumArray[360001];
string solution(string play_time, string adv_time, vector<string> logs)
{
    int playtime = convert(play_time);
    int advtime = convert(adv_time);
    for (auto &log : logs) //1. In and Out구하기
    {
        int start_ = convert(log.substr(0, 8));
        int end_ = convert(log.substr(9));
        ++SumArray[start_];
        --SumArray[end_];
    }
    for (int i = 1; i < playtime; i++) //2. 구간별 재생수구하기
        SumArray[i] += SumArray[i - 1];
    for (int i = 1; i < playtime; i++) //3. 누적재생수 구하기
        SumArray[i] += SumArray[i - 1];
    record.sum=SumArray[advtime];
    for (int start = advtime+1; start < playtime; start++)
    {
        ll Sum = SumArray[start] - SumArray[start - advtime];
        if (Sum > record.sum)
        {
            record.start = start-advtime+1;
            record.sum = Sum;
        }
    }
    return convertTostr(record.start);
}
int main()
{
    cout << solution("02:03:55", "00:14:15",
                     {"01:20:15-01:45:14",
                      "00:40:31-01:00:00",
                      "00:25:50-00:48:29",
                      "01:30:59-01:53:29",
                      "01:37:44-02:02:30"}

    );

    return 0;
}