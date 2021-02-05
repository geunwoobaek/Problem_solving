#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> Group_vec;
ll dp[300000][2];// i,0 :해당노드를 포함하고  1:해당노드 포함x
int dfs(int group,bool include){
    ll& result=dp[group][include];
    if(result!=-1) return result;
    else result=0;
    if(include){ //현재그룹에서 한명 포함시킨경우
    for(auto& next:Group_vec[group]){
        
    }
    }
    else{ //현재그룹에서 포함시키지 않은경우

    }

}
int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    return answer;
}