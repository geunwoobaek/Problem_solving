#include <bits/stdc++.h>
using namespace std;
int convert(string str)
{
    int hour = stoi(str.substr(0)) * 3600;
    int min = stoi(str.substr(3)) * 60;
    int sec = stoi(str.substr(6));
    return hour + min + sec;
}
int sum[3600000];
struct compare
{
    bool operator()(vector<int> a, vector<int> b) { return a[1] < b[1]; };
};
struct Point
{
    int start = 0, length = 0, sum = 0;
} temp, record;
int answer = 2e9;
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
vector<vector<int>> logvecs;
int max_count;
bool cmp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}
string solution(string play_time, string adv_time, vector<string> logs)
{
    int playtime = convert(play_time);
    int advtime = convert(adv_time);
    priority_queue<int, vector<int>, greater<>> pq;
    for (auto &log : logs)
    {
        int start_ = convert(log.substr(0, 8));
        int end_ = convert(log.substr(9));
        logvecs.push_back({start_, end_});
    }
    sort(logvecs.begin(), logvecs.end()); //정렬

    for (int i=0;i<logvecs.size()-1;i++)
    {   
        auto &cur=logvecs[i];
        auto &next=logvecs[i+1];
        pq.push(cur[1]);
        while (!pq.empty())
        {   
            int p_=pq.top();
            if (pq.top() < cur[0])
                pq.pop();
            else break;
        }
        for (int k = cur[0]; k <= next[0]&&k<=cur[1]; k++)
        {
            sum[k]+=pq.size();
        }
    }
    for (int i = 0; i < 3600000; i++)
    {
        if (temp.length <= advtime)
        {
            temp.length++;
            temp.sum += sum[i];
        }
        else
        {
            temp.start++;
            temp.sum += (sum[i] - sum[temp.start]);
        }
        if (record.sum < temp.sum)
            record.sum = temp.sum;
    }
    return convertTostr(record.sum);
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
