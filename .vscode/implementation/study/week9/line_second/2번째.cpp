#include <bits/stdc++.h>
using namespace std;

using namespace std;
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

unordered_map<string, string> flagMap; //key= 명령어 value는 타입
bool isNumber(char &a) { return a >= '0' && a <= '9'; }
bool isChar(char &a) { return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'); }
bool check(string &command, string &args)
{
    for (auto &arg : args)
    {
        if (command == "NUMBER" || command == "NUMBERS")
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
vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands)
{
    vector<bool> answer;
    for (auto &flag : flag_rules)
    {
        vector<string> split_flag = spilt(flag, " ");
        flagMap[split_flag[0]] = split_flag[1];
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
            if (flagMap[split_command[i]].length() > 0)
            {
                string &com = flagMap[split_command[i]];
                if (com == "NULL")
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
                    if (IsTrue && (com == "STRINGS") || (com == "NUMBERS"))
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
int main(){
   solution("line",{"-s STRINGS", "-n NUMBERS", "-e NULL"},{"line -n 100 102 -s hi -e", "line -n id pwd -n 100"});
   return 0;
}