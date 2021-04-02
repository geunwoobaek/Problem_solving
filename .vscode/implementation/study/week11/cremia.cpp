#include <bits/stdc++.h>
using namespace std;
int findRank(int cur_score, const vector<int> &scores)
{ //등급을 return
    int result = 1;
    for (auto score : scores)
    {
        if (cur_score < score) //클수록 점수가 높은것
            result++;
    }
    return result;
}
int numPlayers(int k, vector<int> scores)
{ //이분탐색
    sort(scores.begin(), scores.end());
    auto it = upper_bound(scores.begin(), scores.end(), 0);
    int index=it-scores.begin();
    int left = index, right = scores.size() - 1;
    while (left < right)
    {
        int mid = (left + right) >> 1;
        int result = findRank(scores[mid], scores);
        if (result <= k)
        { //k보다 등수가 적다면 즉 높다면
            right = mid;
        }
        else
            left = mid + 1;
    }
    return (int)scores.size() - left;
}
// 2 2 3 4 5 5 --> 1 1 3 4 5 5
int main()
{
    vector<int> scores = {0,0,2, 2, 3, 4, 5};
    cout << numPlayers(4, scores);
}
