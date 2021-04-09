#include <bits/stdc++.h>
using namespace std;
//pick 2 target 9 logn  3
unordered_map<int, int> um;
vector<int> solution(vector<int> list, int target)
{
    vector<int> answer;
    //숫자 2개를 뽑아서 target으로
    for (int i = 0; i < list.size(); i++)
    {
        um[list[i]] = i;
        if (um.find(target - list[i]) != um.end())
        {
            answer.push_back(i);
            answer.push_back(um[target-list[i]]);
            break;
        }
    }
    return answer;
}
int main()
{
    vector<int> answer = solution({3, 4, 5, 10}, 9);
    cout << "";
}