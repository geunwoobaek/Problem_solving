#include <bits/stdc++.h>
using namespace std;
struct Attr
{
    int index;
    int value;
};
struct Range
{
    int start, end;
};
unordered_map<string, int> Languagemap;
unordered_map<string, int> FiledMap;
unordered_map<string, int> CareerMap;
unordered_map<string, int> SoulFoodMap;
unordered_map<string, int> ScoreMap;

vector<Attr> Langauge;
vector<Attr> Filed;
vector<Attr> Career;
vector<Attr> SoulFood;
vector<Attr> Score;

vector<string> spilt(const string &str, const string &pattern) //직접spilt구현
{
    vector<string> answer;
    char _last = pattern.back();
    int _start = 0;
    int _size = pattern.length();
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == _last && str.substr(i - (_size - 1), _size) == pattern) //pattern
        {
            int size = i - (_size - 1) - _start;
            if (size > 0)
                answer.push_back(str.substr(_start, i - (_size - 1) - _start));
            _start = i + 1;
        }
    }
    if (_start != str.length())
    {
        answer.push_back(str.substr(_start, str.length() - _start));
    }
    return answer;
}
void Init(){
Languagemap["java"]=1;
Languagemap["python"]=2;
Languagemap["cpp"]=3;

FiledMap["backend"]=1;
FiledMap["frontend"]=2;

CareerMap["junior"]=1;
CareerMap["senior "]=2;

SoulFoodMap["chicken"]=1;
SoulFoodMap["pizza "]=2;

Languagemap["-"]=1e9;
FiledMap["-"]=1e9;
CareerMap["-"]=1e9;
SoulFoodMap["-"]=1e9;

}
bool compare(Attr a, Attr b)
{
    return a.value < b.value;
}
int lowerbound(vector<Attr> &kinds, int &what)
{
    int left = 0;
    int right = kinds.size() - 1;
    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (kinds[mid].value >= what)
            right = mid;
        else
            left = mid + 1;
    }
    if(kinds[left].value<what) left++;
    return left;
}
int upperbound(vector<Attr> &kinds, int &what)
{
    int left = 0;
    int right = kinds.size() - 1;
    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (kinds[mid].value <= what)
            left = mid + 1;
        else
            right = mid;
    }
    if (kinds[left].value == what)
        left++;
    return left;
}
void parameticSearch(int &num, vector<bool> &check, vector<Attr> &kinds, int what,bool IsSCore)
{
    if (what == 1e9) return;
    Range range;
    range.start = lowerbound(kinds, what);
    if(!IsSCore) range.end = upperbound(kinds, what);
    for (int start = 0; start < range.start; start++)
    {
        if (check[kinds[start].index])
        {
            // cout << kinds[start].index << ", ";
            check[kinds[start].index] = false;
            num--;
        }
    }
    if(IsSCore) return;
    for (int start = range.end; start < kinds.size(); start++)
    {
        if (check[kinds[start].index])
        {
            //   cout << kinds[start].index << ", ";
            check[kinds[start].index] = false;
            num--;
        }
    }
}
vector<int> solution(vector<string> infos, vector<string> querys)
{
    vector<int> answer;
    Init();
    for (int i = 0; i < infos.size(); i++)
    {
        string info = infos[i];
        vector<string> record = spilt(info, " ");
        Langauge.push_back({i, Languagemap[record[0]]});
        Filed.push_back({i, FiledMap[record[1]]});
        Career.push_back({i, CareerMap[record[2]]});
        SoulFood.push_back({i, SoulFoodMap[record[3]]});
        Score.push_back({i, stoi(record[4])});
    }
    sort(Langauge.begin(), Langauge.end(), compare);
    sort(Filed.begin(), Filed.end(), compare);
    sort(Career.begin(), Career.end(), compare);
    sort(SoulFood.begin(), SoulFood.end(), compare);
    sort(Score.begin(), Score.end(), compare);
    for (auto &query : querys)
    {
        int num = infos.size();
        vector<string> queryspilt = spilt(query, " ");
        vector<bool> checkvec(infos.size(), true);
        parameticSearch(num, checkvec, Score, stoi(queryspilt[7]),true);
        parameticSearch(num, checkvec, Langauge, Languagemap[queryspilt[0]],false);
        parameticSearch(num, checkvec, Filed, FiledMap[queryspilt[2]],false);
        parameticSearch(num, checkvec, Career, CareerMap[queryspilt[4]],false);
        parameticSearch(num, checkvec, SoulFood, SoulFoodMap[queryspilt[6]],false);
        answer.push_back(num);
        //  cout << "\n";
    }
    return answer;
}
int main()
{
    vector<string> info = {
        "java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50"};
    vector<string>
        query = {
            "java and backend and junior and pizza 100",
            "python and frontend and senior and chicken 200",
            "cpp and - and senior and pizza 250",
            "- and backend and senior and - 150",
            "- and - and - and chicken 100",
            "- and - and - and - 150"};
    solution(info, query);
    return 0;
}