#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> language_preference;
unordered_map<string,int> job;
pair<string,int> preference_job={"",-1};
vector<string> spilt(string& str,string pattern) //직접spilt구현
{
    vector<string> answer;
    char _last = pattern.back();
    int _start = 0;
    int _size = pattern.length();
    for (int i = 0;i < str.length();i++)
    {
        if (str[i]== _last&&str.substr(i-(_size-1), _size)==pattern)//pattern
        {
          int size = i - (_size - 1) - _start;
          if(size>0)
          answer.push_back(str.substr(_start,i- (_size - 1) -_start));
          _start = i+1;
        }
    }
    if (_start != str.length()) {
        answer.push_back(str.substr(_start, str.length() - _start));
    }
    return answer;
}
string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    sort(table.begin(),table.end());
    for(int i=0;i<languages.size();i++){
        language_preference[languages[i]]=preference[i];
    }
    for(auto& record:table){
        vector<string> result=spilt(record," ");
        job[result[0]]=0;
        for(int i=1,j=5;i<result.size();i++,j--)
            job[result[0]]+=language_preference[result[i]]*j;
        if(preference_job.second<job[result[0]]) {
            preference_job.first=result[0];
            preference_job.second=job[result[0]];
        }
    }
    cout<<preference_job.second;
    return preference_job.first;
}