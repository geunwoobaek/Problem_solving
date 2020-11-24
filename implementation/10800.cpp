#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define Max 200000
struct ball
{
    int color, size;
};
struct info { int size, sum; };
//함수부분
bool compare(ball a, ball b);
int lower_bound(const vector<info>& Color, int target);
//전역변수
int N;
vector<ball> balls(Max), ColorSeqeunce;
vector<info> Colorballs[Max];
int SizeNumber[2001], SizeSegment[2001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    ColorSeqeunce.resize(N);
    for (int i = 0; i < N; i++)
    {
        int c, s;
        cin >> c >> s;
        balls[i].color=c, balls[i].size = s;
        ColorSeqeunce[i]=balls[i];
        SizeNumber[s]++;
    }
    for (int i = 1; i <= 2000; i++)
        SizeSegment[i] = (i - 1) * SizeNumber[i - 1] + SizeSegment[i - 1]; //SizeSegment

    sort(ColorSeqeunce.begin(), ColorSeqeunce.end(), compare);

    Colorballs[ColorSeqeunce[0].color].push_back({ ColorSeqeunce[0].size,0});
    for (int i = 1;i < ColorSeqeunce.size();i++) //ColorSequence반복
    {
        auto& cur = ColorSeqeunce[i];
        auto& prev = ColorSeqeunce[i-1];
        auto& Colorball = Colorballs[cur.color];
        if(prev.color==cur.color)
            Colorball.push_back({ cur.size,Colorballs[cur.color].back().sum + prev.size});
        else 
            Colorball.push_back({cur.size,0});
    }
    for (int i = 0; i < N; i++)
    {
        auto& now = balls[i];
        cout << SizeSegment[now.size] - lower_bound(Colorballs[now.color], now.size) << "\n";
    }
    return 0;
}

bool compare(ball a, ball b)
{
    if (a.color != b.color)
        return a.color < b.color;
    return a.size < b.size;
}
int lower_bound(const vector<info>& Color, int target)
{
    int right = Color.size() - 1;
    int left = 0;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (Color[mid].size>= target)
            right = mid;
        else
            left = mid + 1;
    }
    return Color[left].sum;
}