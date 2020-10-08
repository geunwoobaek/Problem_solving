#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, cnt = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    for (int i = 0; i < N; i++)
    {
        int left = 0;
        int right = N - 1;
        while (left < right)
        {
            int comp = vec[left] + vec[right];
            if (comp == vec[i])
            {
                if (i != left && i != right)
                {
                    cnt++;
                    break;
                }
                else if (i == right) right--;
                else if (i == left) left++;
            }
            else if (vec[i] < comp)
                right--;
            else
                left++;
        }
    }
    cout<<cnt;
}