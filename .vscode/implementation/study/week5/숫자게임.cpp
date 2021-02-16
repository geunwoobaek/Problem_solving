#include <bits/stdc++.h>

using namespace std;
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int a=0,b=0;a<A.size()&&b<B.size();){
        if(A[a]<B[b]){
            answer++;
            a++;
            b++;
        }
        else{
            b++;
        }
    }   
    return answer;
}
int main()
{
    cout << solution({5, 1, 3, 7}, {2, 2, 6, 8});
}