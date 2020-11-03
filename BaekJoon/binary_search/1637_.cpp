#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, L=2e9,sum = 0, R = 0, num;
ll a[20202], b[20202], c[20202];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        sum += ((b[i] - a[i]) / c[i] + 1);
        L = min(L, a[i]);
		R = max(R, b[i]);
    }
    if (sum % 2 == 0)
    {
        cout << "NOTHING";
        return 0;
    }
    while (L < R)
    {
        ll mid = (L + R) >>1;
        sum = 0;
        for (int i = 0; i < N; i++)
        {   
            if (mid > b[i]) sum += ((b[i] -a[i]) /c[i] + 1);
            else if (mid >= a[i]) sum += ((mid -a[i]) / c[i] + 1);
        }
        if (sum&1) R = mid;
        else L = mid + 1;
    }
    for (int i = 0; i < N; i++)
    {
        if (R >= a[i] && R <= b[i] && (R-a[i])%c[i]==0)
            num++;
    }
    cout << R << " " << num;
    return 0;
}