#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;
unordered_map<int, pair<int, int>> M;
typedef vector<int>::iterator it;
bool check[2001];
int N, cnt;
vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int target = arr[i] + arr[j];
            int &low=M[target].first;
            int &upper=M[target].second;
            if (low == 0 &&upper == 0)
            {
                low = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
                 upper = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
            }
            if (arr[low] == target)
            {   
                for (int k = low; k < upper; k++)
                {
                    if (k == i || k == j)
                        continue;
                    if(!check[k]) cnt++;
                    check[k] = true;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}