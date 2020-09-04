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
void processing(vector<int> &weak, vector<int> &dist) //info vec만들어주는역할
{
    vector<info> now;
    for (int i = 0; i < dist.size(); i++)
    {
        now.push_back(Running(weak, dist[i]));
    }
    sort(now.begin(), now.end(), compare);
    int k = 0;
    vector<int>::iterator it = weak.begin();
    for (; it != weak.end();)
    {
        if (*it == now[0].weak[k++])
        {
            weak.erase(it);
        }
        else
            it++;
    }
    dist.pop_back();
}
info Running(vector<int> &weak, int now_distance)
{
    info current={now_distance,0};
    int max=0;
    for (int i = 0; i <= weak.size(); i++)
    {   
        int dist=now_distance+weak[i];
        int j=i;
        for(;j<weak.size();)
        {
            if(dist-weak[j]) break;
            j++;
        }
        if(max<j){
            max=j;
        }
    }
}
int simulation(vector<int> &weak, vector<int> &dist) //info vec 가장 위에값제거 weak가 아예 0이될때까지 simulation
{
    int result = 0;
    vector<info> now;
    while (weak.size() > 0)
    {
        processing(weak, dist);
        result++;
    }
    return result;
}
int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = 0;
    return answer;
}

int main()
{
    vector<int> vec2(19, 9);

    vec.push_back(info{1, 2});
    vec.push_back(info{2, 2});
    vec.push_back(info{3, 4});
    sort(vec.begin(), vec.end(), compare);
    cout << "hello";
    return 0;
}