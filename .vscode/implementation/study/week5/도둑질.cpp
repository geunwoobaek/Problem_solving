#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cache_vec(2,vector<int>(1000001,-1));
int dfs(vector<int>& cache,vector<int>& money,int start,int end){
    if(start>=end) return 0;
    int &result=cache[start];
    if(result!=-1) return result;
    return result=max(money[start]+dfs(cache,money,start +2,end),dfs(cache,money,start+1,end));
}
int solution(vector<int> money) {
    return max(money[0]+dfs(cache_vec[0],money,2,money.size()-1),dfs(cache_vec[1],money,1,money.size()));
}