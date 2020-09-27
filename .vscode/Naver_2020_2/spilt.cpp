#include <iostream>
#include <vector>
using namespace std;

vector<string> spilt(string &str,string &pattern)
{
    vector<string> answer;
    int start=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=' ')//patern
        {
            if(i!=start)
            {
                answer.push_back(str.substr(start,i-start));
            }
            start=i+1;
        }
    }
    if(start!=str.length())
    {
        answer.push_back(str.substr(start,str.length()-start));
    }
    return answer;
}

int main()
{
string test=" abcd sdfc fcdsef fesa";
vector<string> vec=spilt(test,test);
return 0;
}

