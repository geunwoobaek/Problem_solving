#include <cstdio>
#include <queue>
#include <iostream>
#include <functional>
#define MAX_TIME 60000000000
#define MAX_M 10000 + 1
using namespace std;

// global
long long N;
 int M;
int arr[MAX_M];

int find_answer(long long sum, long long now_time)
{   
    for (int i = M; i >= 1; i--)
    {   
        sum -= ((now_time - 1) / arr[i] - (now_time - 2) / arr[i]);
        if (sum == N-1) return i;
    }
}
long long find_current(long long now_time)
{
    long long sum = 0;
    for (int i = 1; i <= M; i++)
    {
        if(sum>N) return sum;
        sum += ((now_time - 1) / arr[i] + 1);
    }
    return sum;
}
int find()
{
    long long left = 1;
    long long Right = MAX_TIME;
    long long mid = 0;
    long long current_num = M;
    if (current_num >= N)
        return N;
    while (left < Right)
    {
        mid = (left + Right) / 2;
        current_num = find_current(mid);
        if (current_num < N)
        {
            left = mid + 1;
        }
        else
        {
            Right = mid;
        }
    }
    current_num = find_current(left);
    return find_answer(current_num, left);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        cin >> arr[i];
    cout << find();
    return 0;
}
