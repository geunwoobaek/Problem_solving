#include <bits/stdc++.h>
using namespace std;
#define Pair pair<int, int>
#define s first
#define e second
bool compare(Pair A, Pair B)
{
    if (A.s != B.s)
        return A.s < B.s;
    else
        return A.e > B.e;
}
int N;
vector<Pair> line;
int length = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    line.resize(N);
    for (int i = 0; i < N; i++)
        cin >> line[i].s >> line[i].e;
    sort(line.begin(), line.end(), compare);
    for (int i = 0; i < N;)
    {
        length += (line[i].e - line[i].s);
        int next = i + 1;
        while (next < N && line[next].e <= line[i].e) next++;
        if (next < N && line[i].e > line[next].s) line[next].s = line[i].e;
        i = next;
    }
    cout<<length;
    return 0;
}