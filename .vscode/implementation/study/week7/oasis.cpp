#include <bits/stdc++.h>
#define ll long long
#define val first
#define num second
using namespace std;
int N;
ll cnt = 0;
stack<pair<ll, ll>> st; //firsts 값 second같은값의 갯수
//4 3 2 1
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        pair<ll, ll> cur;
        cin >> cur.val;
        cur.num = 1;
        while (!st.empty() && st.top().first < cur.val) //현재 나온값이 이전값보다 클경우 7 4 3 2 1 5
        {
            cnt += st.top().num;
            st.pop();
        }
        if (!st.empty() && st.top().first == cur.val) //현재 나온값이 이전값이랑 같을경우
        {
            cnt += st.top().second;
            cur.num = ++st.top().second;
            st.pop();
        }
        if (!st.empty() && st.top().first > cur.val) //현재 나온값이 이전값보다 작을경우 5 4 3 2
            cnt++;
        st.push(cur);
    }
    cout << cnt;
    return 0;
}