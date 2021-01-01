#include <bits/stdc++.h>
using namespace std;
#define Pair pair<int, int>
#define s first
#define e second
//2016-09-15 01:00:04.002 2.0s
const int _sec = 1000;
const int _min = _sec * 60;
const int _hour = 60 * _min;
const int real_sec = 999;
int _maximum = 0;

vector<Pair> vec;

void process();
void countProcess(Pair& p);
bool compare(Pair a, Pair b);
int solution(vector<string> lines);
Pair StringtoNumber(string& line);
bool isInclude(const Pair& pivot, const Pair& target);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string>vec_str(2);
    vec_str[0]= "2016-09-15 01:00:04.002 2.0s";
    vec_str[1]= "2016-09-15 01:00:07.000 2s";
    solution(vec_str);
    return 0;
}

int solution(vector<string> lines) {
    vec.resize(lines.size());
    for (int i = 0;i < lines.size();i++) {
        vec[i] = StringtoNumber(lines[i]);
    }
    sort(vec.begin(), vec.end(), compare);
    process();
    int answer = _maximum;
    return answer;
}
void process() {
    for (int i = 0;i < vec.size();i++) {
        Pair p1 = { vec[i].s,vec[i].s + real_sec };
        Pair p2 = {vec[i].s-real_sec, vec[i].s };
        countProcess(p1);
        countProcess(p2);
     }
}
void countProcess(Pair& p) { 
    int cnt = 0;
    for (const auto& target : vec) {
        if (isInclude(p, target)) cnt++;
    }
    _maximum = max(_maximum, cnt);
}
bool isInclude(const Pair &pivot,const Pair&target ) {
    return (pivot.e >= target.s && target.e >= pivot.s);
}
bool compare(Pair a, Pair b) {
    if (a.s != b.s) return a.s < b.s;
    else return a.e < b.e;
}
Pair StringtoNumber(string& line)
{
    Pair value;
    int end = 0, ptime = 0, length = line.length();
    string now;
    int idx = 11;
    //01:00:04.002 2.121s
    end+= stoi(line.substr(idx, 2)) * _hour;
    end += stoi(line.substr(idx + 3, 2)) * _min;
    end += stoi(line.substr(idx + 6, 2)) * _sec;
    end += stoi(line.substr(idx + 9, 3));
    value.e = end;

    ptime+= stoi(line.substr(idx + 13, 1)) * _sec;
    try {
        ptime += stoi(line.substr(idx + 15, (length - 1) - (idx + 15)));
    }
    catch (const std::exception&){}
    value.s = value.e - ptime + 1;
    return value;
}