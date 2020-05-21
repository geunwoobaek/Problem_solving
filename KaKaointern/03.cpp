#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
//stoi //tostring //map //copy //fill sort
int N;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<string> vec;
    map<string,int> m;
    vector<vector<int>> vec;
    for(int i=0;i<gems.size();i++)
    {
        if(m[gems[i]]==0) m[gems[i]]++;
    }
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


return 0;
}