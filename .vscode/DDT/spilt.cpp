#include <iostream>
#include <vector>
using namespace std;

vector<string> spilt(string& str,string& pattern) //직접spilt구현
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

int main()
{
    string test = " kdcd__,s dab__fc,dsa.bef,fesa";
    string pattern = ",";
    vector<string> vec = spilt(test, pattern);
    for(auto i:vec)
    {
        cout<<i<<endl;
    }
    return 0;
}

