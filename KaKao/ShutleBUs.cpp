#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//시간을 분으로 변환
void ChangeTimeToMinute(int n, int t, vector<int> &TimeTable, vector<string> &Hour)
{
    for (int i = 0; i < Hour.size(); i++)
    {
        int time = 0;
        time += 60 * (stoi(Hour[i].substr(0, 2)));
        time += stoi(Hour[i].substr(3, Hour[i].size()));
        if (time > (540 + t * (n - 1))||time==0) continue;
        TimeTable.push_back(time);
    }
    sort(TimeTable.begin(), TimeTable.end());
}
//분을 시간으로 변환
string ChangeMinuteToTime(int time)
{
    int hour = time / 60;
    int minute = time % 60;
    string h = to_string(hour);
    string m = to_string(minute);
    if (h.size() == 1)
        h = "0" + h;
    if (m.size() == 1)
        m = "0" + m;
    return h.substr(0, 2) + ":" + m.substr(0, 2);
}
string solution(int n, int t, int m, vector<string> timetable)
{
    vector<int> Hour;
    ChangeTimeToMinute(n, t, Hour, timetable); //변환
    int starttime = 60 * 9;
    int count = 0;
    int day = 1;
    for (day = 1; day <= n; day++)
    {
        int degree = 0; //현재 탑승한 승객수
        while (degree < m && count < Hour.size() && starttime + t * (day - 1) >= Hour[count])
        {
            count++; //누적으로 탑승한 크루의수
            degree++;
            if (count == Hour.size()) //모든 크루가 탑승했을시
                {   if(day!=n) degree=0;
                    day = n;
                }
        }
        if (day == n) //탈수있는 마지막 버스
        {
            int current = starttime + (t * (day - 1));
            if (degree == m) //버스가 꽉찼을경우
            {
                return ChangeMinuteToTime(Hour[count - 1] - 1); //마지막크루보다 -1해서 타기
            }
            else //버스가 가득안찼을경우
            {
                return ChangeMinuteToTime(current);
            }
        }
    }
}
int main()
{
    vector<string> str(2);
    str[0] = "08:09";
    str[1] = "08:09";

    cout << solution(2, 10, 2, str);
}