#include <bits/stdc++.h>

using namespace std;
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(auto i:A){
        auto it=upper_bound(B.begin(),B.end(),i);
        if(it!=B.end()&&(*it)>i) {
            answer++;
            B.erase(it);
        }
    }
    return answer;
}
int main()
{
    cout << solution({5, 1, 3, 7}, {2, 2, 6, 8});
    // vector<int> B(1,2);
    // auto it=upper_bound(B.begin(),B.end(),2);
    // cout<<*it<<"\n";
    // if(it==B.end()) 
    //     cout<<"fuck";
    return 0;
}