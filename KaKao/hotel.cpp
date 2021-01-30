#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> hotel; //정렬되있음

// 1,4 2
pair<int, bool> process1(ll room) //int=위치 bool=true일시 작업끝남(방에들어감),false:방 위치 찾지못함
{
    pair<int, bool> result;
    //호텔에 해당 방있는지 체크
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
    if (hotel.empty()) //비어있을시
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
}
ll process2(int left)
{   
    //똑같은 방있을시 1,2,3,6
    int right=hotel.size()-1;
    while(left<right){
        int mid=(left+right)/2;
        ll capacity_=hotel[mid]-hotel[left];
        ll size_=mid-left;
        if(capacity_!=size_) right=mid;
        else left=mid+1;
    }
    
    //이분탐색으로 들어가게될방 찾음
    //capacity!=size 일시 right=mid
    //같을경우 left=mid+1
}
vector<ll> solution(ll k, vector<ll> room_number)
{
    vector<ll> answer;
    for (auto room : room_number)
    {
        pair<int, bool> info = process1(room);
        if (!info.second)
        {
            room = process2(info.first);
        }
        answer.push_back(room);
    }
    return answer;
}

int main()
{
    solution(10, vector<ll>({1, 3, 5, 7, 11, 13}));
}