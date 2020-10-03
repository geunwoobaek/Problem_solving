// 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

// 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

// 입력
// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)

// 출력
// 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

// 둘째 줄에는 정답이 될 수 있는 가장 긴 증가하는 부분 수열을 출력한다.
#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> vec(1);
void lower_bound(vector<int>& vec, int value)
{
    int left = 0;
    int mid = 0;
    int right = vec.size() - 1;
    while (right > left) 
    {
        mid = (right + left) / 2;
        if (vec[mid] >= value) 
            right = mid;
        else left = mid + 1; 
    }
    if (left < 0) left = 0;
    vec[left] = value;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N>> vec[0];
    for (int i = 1;i < N;i++)
    {
        int cur;
        cin >> cur;
        if (cur > vec.back()) vec.push_back(cur);
        else lower_bound(vec, cur);
    }
    cout<<vec.size()<<endl;
    for (int i : vec) cout<<i<<" ";
    return 0;
}
