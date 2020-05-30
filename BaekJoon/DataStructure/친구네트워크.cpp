#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int N, T;
map<string, int> Cache;
int cnt[100002];
int parent[100001];
int find_parent(int a)
{
    if (parent[a] == a) return a;
    else return parent[a]=parent[parent[a]];
}
int merge(int a, int b)
{
    int temp1 = find_parent(a);
    int temp2 = find_parent(b);
    if (temp1 == temp2) return cnt[temp1];
    if (temp1 < temp2) {
        parent[temp2] = temp1;
        return cnt[temp1] += cnt[temp2];
    }
    parent[temp1] = temp2;
    return cnt[temp2] += cnt[temp1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        int idx = 1;
        string A, B;
        Cache.clear();
        fill(parent, parent + 100002, 0);
        fill(cnt, cnt + 100002, 1);
        for (int i = 0;i < N;i++)
        {
            cin >> A >> B;
            int& a = Cache[A];
            int& b = Cache[B];
            if (a == 0) {
                a = parent[idx] = idx;
                idx++;
            }
            if (b == 0) {
                b = parent[idx] = idx;
                idx++;
            }   
            printf("%d\n",merge(a,b));
        }
    }
    return 0;
}