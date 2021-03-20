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

string program;
unordered_map<string, string> flagMap; //key= 명령어 value는 타입
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
        vector<string> split_command = spilt(command," ");
        if (split_command[0] != program)
        {
            answer.push_back(false);
            continue;
        }
        bool IsTrue=true;
        for (int i = 1; i < split_command.size(); i++)
        {     
            if (flagMap[split_command[i]].length() > 0)
            {
                string &com = flagMap[split_command[i]];
                if (com == "NULL") continue;
                else
                {
                    if (i == split_command.size()-1)
                        IsTrue=false;
                    string &args=split_command[i+1];
                    if (com == "NUMBER")
                    {
                        for(auto& arg:args){
                            if(arg<'0'||arg>'9') {
                                IsTrue=false;
                                break;
                            }
                        }
                    }
                    else
                    {
                         for(auto& arg:args){
                            if((arg>='a'&&arg<='z')||(arg>='A'&&arg<='Z')) continue;
                                IsTrue=false;
                                break;
                        }
                    }
                    i++;
                }
            }
            else
            {
               IsTrue=false;
                break;
            }
        }
        answer.push_back(IsTrue);
    }
    return answer;
}