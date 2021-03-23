#include <bits/stdc++.h>
using namespace std;
enum
{
    NONE,
    NULL_,
    STRING_,
    STRINGS_,
    NUMBER_,
    NUMBERS_
};
vector<string> spilt(string &str, string pattern) //직접구현
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
unordered_map<string, int> orders;
unordered_map<string, int> flagMap; //key= 명령어 value는 타입
unordered_map<int, string> aliasMap;
bool isNumber(char &a) { return a >= '0' && a <= '9'; }
bool isChar(char &a) { return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'); }
bool check(int &command, string &args)
{
    for (auto &arg : args)
    {
        if (command == NUMBER_ || command == NUMBERS_)
        {
            if (!isNumber(arg))
                return false;
        }
        else
        {
            if (!isChar(arg))
                return false;
        }
    }
    return true;
}
//NULL NUMBER STRING
void init()
{
    orders["NULL"] = NULL_;
    orders["NUMBER"] = NUMBER_;
    orders["STRING"] = STRING_;
    orders["NUMBERS"] = NUMBERS_;
    orders["STRINGS"] = STRINGS_;
}
vector<vector<string>> flag_vec;
bool compare(vector<string> &a, vector<string> &b) { return a.size() < b.size(); }
vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands)
{
    init();
    vector<bool> answer;
    //-n string
    // -n alias num
    for (int i = 0; i < flag_rules.size(); i++)
    {
        auto &flag = flag_rules[i];
        {
            flag_vec.push_back(spilt(flag, " "));
        }
    }
    sort(flag_vec.begin(), flag_vec.end(), compare);
    for (auto flag : flag_vec)
    {
        if (flag.size() == 2)
        {
            flagMap[flag[0]] = orders[flag[1]];
        }
        else
        {
            flagMap[flag[0]] = flagMap[flag[2]];
        }
    }
    for (auto &command : commands)
    {
        vector<string> split_command = spilt(command, " ");
        if (split_command[0] != program)
        {
            answer.push_back(false);
            continue;
        }
        bool IsTrue = true;
        for (int i = 1; i < split_command.size(); i++)
        {
            if (flagMap[split_command[i]] > 0)
            {
                int &com = flagMap[split_command[i]];
                if (aliasMap[com].length()>0)
                {
                    if (aliasMap[com] != split_command[i])
                    {
                        IsTrue = false;
                        break;
                    }
                }
                else
                    aliasMap[com] = split_command[i];
                if (com == NULL_)
                    continue;
                if (i == split_command.size() - 1)
                {
                    IsTrue = false;
                    break;
                }
                else
                {
                    string args = split_command[++i];
                    IsTrue = check(com, args);
                    if (IsTrue && (com == STRINGS_) || (com == NUMBERS_))
                    {
                        while (IsTrue && i < split_command.size() - 1)
                        {
                            args = split_command[++i];
                            IsTrue = check(com, args);
                        }
                        IsTrue = true;
                        i--;
                    }
                }
            }
            else //없는명령일경우
            {
                IsTrue = false;
                break;
            }
        }
        answer.push_back(IsTrue);
    }
    return answer;
}
int main()
{
    solution("line", {"-s STRING", "-num NUMBER", "-e NULL", "-n ALIAS -num"}, {"line -n 100 -s hi -e", "line -n 100 -e -num 150"});
    return 0;
}