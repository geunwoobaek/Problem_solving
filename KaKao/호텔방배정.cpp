#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> hotel; //정렬되있음
bool isRange(int end, int start); //해당 범위에 빈방이 있는지 체크
pair<int, bool> process1(ll &room); //고객이 원하는 지점에 빈방이 있는지 체크및 없다면 방의 위치 반환 
ll process2(int start); //해당지점의 방위치부터 이분탐색으로 빈방의 위치를 찾음 

bool isRange(int end, int start)
{
    ll capacity_ = hotel[end] - hotel[start]; //수용가능공간
    ll size_ = end - start; //현재 차있는공간
    return capacity_ != size_; //빈방이있다면
}
pair<int, bool> process1(ll &room) //int=위치 bool=true일시 작업끝남(방에들어감),false:방 위치 찾지못함
{
    pair<int, bool> result;
    int left = 0;
    int right = hotel.size() - 1;
    while (left < right)
    {
        int mid = (left + right) >> 1;
        if (hotel[mid] >= room)
            right = mid;
        else
            left = mid + 1;
    }
    if (hotel.empty() || hotel.back() < room) //비어있거나 더큰값일시
    {
        hotel.push_back(room);
        result = {0, true};
    }
    else //비어있지않을시
    {
        if (hotel[left] == room) //방이있을시
        {
            result = {left, false}; //있다면 해당방의 [위치,true] return
        }
        else
        {
            if (hotel[left] > room)
            {
                hotel.insert(hotel.begin() + left, room);
            }
            else
            {
                hotel.push_back(room);
            }
            result = {0, true}; //없다면 hotel에 집어넣고 [0,true] return
        }
    }
    return result;
}
ll process2(int start)
{
    ll result;
    int left = start;
    int right = hotel.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isRange(mid, start)) //해당범위안에 남은 방이있을경우
            right = mid;
        else
            left = mid + 1;
    }
    if (isRange(left, start))
    {
        result = hotel[left - 1] + 1;
        hotel.insert(hotel.begin() + left, result);
    }
    else{
        result=hotel[left]+1;
        hotel.push_back(result);
    }
    return result;
}
vector<ll> solution(ll k, vector<ll> room_number)
{
    vector<ll> answer;
    for (auto room : room_number)
    {
        pair<int, bool> info = process1(room);
        if (!info.second) //해당지점에 빈방이 없다면
        {
            room = process2(info.first); //고객원하는지점부터 빈방찾기
        }
        answer.push_back(room); //새로찾은 방위치 집어넣기
    }
    hotel.clear();
    return answer;
}

int main()
{
    solution(10, vector<ll>({1, 3, 4, 1, 3, 1}));
    solution(10, vector<ll>({1, 2, 4, 1, 1, 1, 10}));
    solution(10, vector<ll>({1, 3, 9, 10, 11, 1, 1}));
}