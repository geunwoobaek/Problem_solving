#include <bits/stdc++.h>
//100,0000
using namespace std;
vector<int> leave_order(1001); //나간순서체크 leave[i]=j; i번째 사람은 j에 나감 그럼 j번째 나간사람은누구
vector<int> converse_leave_order(1001); 
vector<int> enter_order(1001); //들어온 순서체크 enter_order[i]는 i번째사람이 몇번째들어왔는지 체크
// 4 ,2 , 3 1
vector<int> solution(vector<int> enter, vector<int> leave)
{
    //나중에 들어온사람보다 늦게 나가면 체크
    vector<int> answer(enter.size());
    for (int i = 0; i < enter.size(); i++)
    {
        enter_order[enter[i]-1] =i; 
    }
    for (int i = 0; i < leave.size(); i++)
    {
        leave_order[leave[i]-1] = i; //leave_order[i]=k i번째나간 순서k
        converse_leave_order[i]=leave[i]-1;
    }
    for (int i = 0; i < enter.size(); i++) //나중에 들어온사람보다 늦게 나가면 체크  나중에 들어온사람체크 먼저나간사람체크
    {
        unordered_map<int,bool>back_enter;
        int cnt=0;
        for(int j=enter_order[i]+1;j<enter.size();j++)//나중에 들어온사람체크
        {
            back_enter[enter[j]]=true;
        }
        for(int j=leave_order[i]-1;j>=0;j--) //나가는 사람체크
        {
            if(back_enter[converse_leave_order[j]]) {
                answer[i]++;
                answer[converse_leave_order[j]]++;
            }
        }
    }
    for(auto& now:answer) cout<<now<<" ";
    return answer;
}
int main(){
    solution(	{1, 3, 2}, {1, 2, 3});
    return 0;
}