#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info
{
    int distance;
    int size;
    vector<int> weak;
};
vector<info> vec;
bool compare(info i1, info i2)
{
    if (i1.size != i2.size)
    {
        return i1.size > i2.size ? true : false;
    }
    else
        return (i1.distance) < (i2.distance) ? true : false;
}
info Running(vector<int> &weak, int now_distance, int n)
{
    info current = {now_distance, 0};
    int max = 0;
    int MaxDistance=200;
    int Point;
    for (int i = 0; i < weak.size(); i++)
    {
        int dist = now_distance + weak[i];
        int j = i;
        int h = 0;
        while (dist - weak[j - h] >= 0)
        {
            j++;
            if (j - h >= weak.size())
            {
                dist -= n;
                h = j;
            }
        }
     if (max < j - i||(max==j-i)&&dist<MaxDistance)
        {
            max = j - i;
            MaxDistance=dist;
            Point = i;
        }


    }
    current.size = max + 1;
    int k = 0;
    for (int i = 0; i < max; i++)
    {
        if (Point < weak.size())
            current.weak.push_back(weak[Point++]);
        else
        {
            current.weak.insert(current.weak.begin() + k, weak[Point - weak.size()]);
            Point++;
            k++;
        }
    }

    return current;
}
void processing(vector<int> &weak, vector<int> &dist, int n) //info vec만들어주는역할
{
    vector<info> now;
    for (int i = 0; i < dist.size(); i++)
    {
        now.push_back(Running(weak, dist[i], n));
    }
    sort(now.begin(), now.end(), compare);
    int k = 0;
    auto it = weak.begin();
    while (it != weak.end() && k < now[0].weak.size())
    {
        if (*it == now[0].weak[k])
        {
            k++;
            it = weak.erase(it);
        }
        else
            it++;
    }
    for (int i = dist.size() - 1; i >= 0; i--)
    {
        if (dist[i] == now[0].distance)
        {
            dist.erase(dist.begin() + i);
            break;
        }
    }
};

int simulation(vector<int> &weak, vector<int> &dist, int n) //info vec 가장 위에값제거 weak가 아예 0이될때까지 simulation
{
    int result = 0;
    int total = dist.size();
    vector<info> now;
    while (weak.size() > 0 && dist.size() > 0)
    {
        processing(weak, dist, n);
        result++;
    }
    if (dist.size() == 0 && weak.size() != 0) return -1;
    return result;
}
int solution(int n, vector<int> weak, vector<int> dist)
{  
    sort(dist.begin(),dist.end());
    return simulation(weak, dist, n);
}

int main()
{
    int n = 12;
    vector<int> weak;
    vector<int> dist;
    weak.push_back(1);
    weak.push_back(5);
    weak.push_back(6);
    weak.push_back(10);
    dist.push_back(1);
    dist.push_back(2);
    dist.push_back(3);
    dist.push_back(4);
    cout << solution(n, weak, dist);
    return 0;
}