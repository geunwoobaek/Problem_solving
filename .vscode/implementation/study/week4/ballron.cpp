#include <bits/stdc++.h>
using namespace std;
#define F(i, j, k) for (int i = j; i < k; i++)
#define Max 1000001
int dp[Max], dp2[Max];
int solution(vector<int> a)
{
    int answer = 0;
    dp[0] = a[0];
    F(i, 1, a.size()) //dp[i]에는 i까지 값중 제일 큰값이 들어가게됨
    {
        if (dp[i - 1] > a[i]) //이전값이 현재값보다 크면
            dp[i] = a[i];
        else //이전값이 현재 값보다 작으면
            dp[i] = dp[i - 1];
    }
    dp2[a.size() - 1] = a[a.size() - 1];    //뒤에서부터 읽기
    for (int i = a.size() - 2; i >= 0; i--) //dp2[i]에는 n->i까지 중 가장큰 값이 들어가게됨.
    {
        if (dp2[i + 1] > a[i]) //뒤에값이 크면
            dp2[i] = a[i];     //앞에값을 바꿔치기
        else
            dp2[i] = dp2[i + 1];
    }
    F(i, 0, a.size())
    {
        if (a[i] <= dp[i] || a[i] <= dp2[i])
            answer++;
    }
    F(i, 0, a.size()){
        cout<<dp[i]<<", ";
    }
    cout<<"\n";
    F(i, 0, a.size()){
        cout<<dp2[i]<<", ";
    }
    return answer;
}
int main()
{
    solution({-16, 27, 65, -2, 58, -92, -71, -68, -61, -33});
    return 0;
}