#include <bits/stdc++.h>
#define LIMIT_ 20001
#define F(i, s, e) for (int i = s; i <= e; i++)
using namespace std;
int TestCase, N, W;
vector<int> vec1, vec2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TestCase;
    while (TestCase--)
    {
        cin >> N >> W;
        vec1.resize(N + 1);
        vec2.resize(N + 1);
        F(i, 1, 2 * N)
        {
            cin >> vec1[i];
            if (i == 1)
                continue;
            else
                vec2[i - 1] = vec1[i];
        }
    }
    return 0;
}
