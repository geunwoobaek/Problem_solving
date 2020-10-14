#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int L, K, C;
int cut[10002];
bool isPossible(int log)
{
    int k;
    int start = L, cnt = 0;

    int diff = 0;

    for (k = K - 1; k >= 0; k--)
    {

        diff += cut[k + 1] - cut[k];

        if (diff > log)
        {

            diff = cut[k + 1] - cut[k];

            cnt++;

            if (diff > log)
            {

                cnt = C + 1;

                break;
            }
        }
    }

    return cnt <= C;
}

bool isFirst(int idx, int log)
{

    int k;

    int start = cut[idx], cnt = 1;

    if (cut[idx] - start > log)
        return false;

    if (cnt == C)
    {

        if (L - cut[idx] <= log)
            return true;

        else
            return false;
    }

    int diff = 0;

    for (k = idx + 1; k <= K; k++)
    {

        diff += cut[k + 1] - cut[k];

        if (diff > log)
        {

            diff = cut[k + 1] - cut[k];

            cnt++;

            if (diff > log)
            {

                cnt = C + 1;

                break;
            }
        }
    }

    return cnt <= C;
}

int main()
{

    scanf("%d%d%d", &L, &K, &C);

    for (int k = 1; k <= K; k++)
        scanf("%d", &cut[k]);

    cut[0] = 0, cut[++K] = L;

    sort(cut, cut + K + 1);

    int ans1 = (int)2e9;

    int l = 0, r = (int)(1e9 + 1);

    while (l <= r)
    {

        int mid = (l + r) / 2;

        if (isPossible(mid))
        {
            ans1 = min(ans1, mid);
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    int diff = 0, cnt = 0;
    int idx = K;
    for (int k = K - 1; k >= 0; k--)
    {
        diff += cut[k + 1] - cut[k];
        if (diff > ans1)
        {
            cnt++;
            diff = cut[k + 1] - cut[k];
            idx = k + 1;
        }
    }
    if (cnt < C)
        idx = 1;
    printf("%d %d\n", ans1, cut[idx]);
    return 0;
}
