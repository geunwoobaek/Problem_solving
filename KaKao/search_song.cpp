#include <iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(auto i:queries)
    {   int k=0;
        for(auto j:words)
        {   
            if(i.length()==j.length())
            {   bool check=true;
                for(int k=0;k<j.length();k++)
                {   
                    if(i[k]=='?'||j[k]==i[k]) continue;
                    else {check=false; break;} 
                }
                if(check) k++;
            }   
        }
        answer.push_back(k);
    }
    return answer;
}
int main()
{





    return 0;
}